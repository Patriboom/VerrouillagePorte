#include <Stepper.h>
#include <SPI.h>
#include <MFRC522.h>
#include <Keypad.h>

//Raspberry Pi Pico (non, pas Wifi)
//----------------------------Liste des GPI0 attribués au projet ci-bas ---------------------------------------------------------------------
//00  clavier 4x4 - blanc-brun
//01	clavier 4x4 - brun
//02	Moteur - blanc-orange
//03	Moteur - blanc-bleu
//04	Moteur - blanc-vert
//05	Moteur - blanc-brun
//06	
//07	clavier 4x4 - blanc-orange
//08	clavier 4x4 - orange
//09	clavier 4x4 - blanc-bleu
//10	clavier 4x4 - bleu
//11	clavier 4x4 - blanc-vert
//12	
//13	pinDEL - rouge
//14	pinDEL - vert
//15	pinDEL - bleu
//16	Carte identification    -- blanc-vert
//17	Carte identification    -- blanc-bleu
//18	Carte identification    -- blanc-brun
//19	Carte identification    -- bleu
//20	clavier 4x4 - vert
//21	Carte identification    -- vert
//22	
//26	pinSW1 - Interrupteur fermé lorsque la porte est ouverte
//27	pinSW2 - Interrupteur fermé lorsque la porte est fermée
//28	
//29	
//----------------------------Fin de la liste des GPI0 attribués au projet ci-bas ----------------------------------------------------------

//En vue de fonctionner sous Respberry PICO
/*----- Variables, Pins -----*/
//#define STEPS  4      // Number of steps per revolution of Internal shaft
int delai = 60000;      //La DEL restera allumée - en rouge ou vert - pendant une minute après la fin du mouvement, tandis que durant le mouvement elle affichera jaune
int pas = 25;           // 1 tour = 2048   // Était à 25, ce 12 novembre 2024 à 12h
int sens = 1;
int vitesseMax = 1000;      //Max 700
String libre = "oui";
bool tourne = false;
bool initOUV = false;
bool initFER = false;
int rendu = 0;

int pinSW1 = 26;    //GPIO00 = pin 31  -> Interrupteur fermé lorsque la porte est ouverte  => DEL vert
int pinSW2 = 27;    //GPIO01 = pin 32  -> Interrupteur fermé lorsque la porte est fermée   => DEL rouge
int pinMO1 = 2;     //GPIOO2 = pin 4  -> Mouvement du moteur, contrôleur 1
int pinMO2 = 3;     //GPIOO3 = pin 5  -> Mouvement du moteur, contrôleur 2
int pinMO3 = 4;     //GPIOO4 = pin 6  -> Mouvement du moteur, contrôleur 3
int pinMO4 = 5;     //GPIOO5 = pin 7  -> Mouvement du moteur, contrôleur 4
int pinDER = 13;    //GPIO13 = pin 17 -> Rouge de la DEL;    ... DEL tri-colore : ici Rouge
int pinDEV = 14;    //GPIO14 = pin 19 -> Vert de la DEL;     ... DEL tri-colore : ici Vert
int pinDEB = 15;    //GPIO15 = pin 20 -> Bleu de la DEL;     ... DEL tri-colore : ici Bleu
int pinCLA1 = 7;    //GPIO07 = pin 10 -> Clavier 4x4
int pinCLA2 = 8;    //GPIO08 = pin 11 -> Clavier 4x4
int pinCLA3 = 9;    //GPIO09 = pin 12 -> Clavier 4x4
int pinCLA4 = 10;   //GPIO010 =pin 14 -> Clavier 4x4
int pinCLA5 = 11;   //GPIO011 =pin 15 -> Clavier 4x4
int pinCLA6 = 20;   //GPIO020 =pin 26 -> Clavier 4x4
int pinCLA7 = 0;    //GPIO00 = pin 1  -> Clavier 4x4
int pinCLA8 = 1;    //GPIO01 = pin 2  -> Clavier 4x4
byte CRT_RST = 21;  //GPIO21 = pin 27 -> Lecteur de cartes sans contact - Reset
byte CRT_SSC = 17;  //GPIO17 = pin 22 -> Lecteur de cartes sans contact - SS
String codeEntree = "";
String codeValide = "B6580";
const int col = 4;
const int lgn = 4;
String TchClavier[lgn][col] = {
  {"*","0","#","D"},
  {"7","8","9","C"},
  {"4","5","6","B"},
  {"1","2","3","A"}
};
byte pinLgnCLA[lgn] = {7,8,9,10};
byte pinColCLA[col] = {11,20,0,1};
Keypad clavier = Keypad(makeKeymap(TchClavier), pinLgnCLA, pinColCLA, lgn, col);


unsigned long dernBoutonClavier = millis();

//Création des principaux objets
Stepper moteur(32, pinMO1, pinMO3, pinMO2, pinMO4);
/*
Voici comment connecter le module moteur
PINcarte Defn    PICO    GPIO
A1       GND     >>>>>>  >>>>>>>>   AliM GND  - brun
A2       5V      >>>>>>  >>>>>>>>   Alim 5V   - orange
B1       IN1     4       GPIO2                - blanc-orange
B2       IN2     5       GPIO3                - blanc-bleu
B3       IN3     6       GPIO4                - blanc-vert
B4       IN4     7       GPIO5                - blanc-brun
*/
MFRC522 cartes;   // Create MFRC522 instance.
/*
Voici comment connecter les fils du lecteur de cartes magnétiques, les coueleurs sont celles de la porte secrète de Pond Inlet
PINcarte Defn    PICO    GPIO                                   Couleur
1       3.3V     >>>>>>  >>>>>>>>>>   Alim 3.3 volts            Bleu
2       RST      27      GPIO21                                 Bourgogne
3       GND      >>>>>>  >>>>>>>>>>   Alim GND                  Gris
4       RQ       >>>>>>  >>>>>>>>>>   Libre (non-connecté)
5       MISO     21      GPIO16                                 Blanc
6       MOSI     25      GPIO19                                 Noir
7       SCK      24      GPIO18                                 Brun
8       SDA      22      GPIO17                                 Rouge
*/

void setup() { 
  Serial.begin(115200);
  Serial.println("");
  delay(550);
  Serial.println("Bonjour les testeurs");
  SPI.begin();        // Init SPI bus
  Serial.println("SPI est démarré.");
  cartes.PCD_Init(CRT_SSC, CRT_RST); // Init each MFRC522 card
  cartes.PCD_DumpVersionToSerial();

  pinMode(pinSW1, INPUT);   //Interrupteur fermé lorsque la porte est ouverte  => DEL vert
  pinMode(pinSW2, INPUT);   //Interrupteur fermé lorsque la porte est fermée   => DEL rouge
  pinMode(pinMO1, OUTPUT);  //Moteur 1
  pinMode(pinMO2, OUTPUT);  //Moteur 2
  pinMode(pinMO3, OUTPUT);  //Moteur 3
  pinMode(pinMO4, OUTPUT);  //Moteur 4
  pinMode(pinDER, OUTPUT);  //rouge de la DEL
  pinMode(pinDEV, OUTPUT);  //vert de la DEL
  pinMode(pinDEB, OUTPUT);  //bleu de la DEL

  digitalWrite(pinMO1, LOW);
  digitalWrite(pinMO2, LOW);
  digitalWrite(pinMO3, LOW);
  digitalWrite(pinMO4, LOW);
  digitalWrite(pinDER, LOW);
  digitalWrite(pinDEV, LOW);
  digitalWrite(pinDEB, LOW);

  Serial.println("Voici que tout est défini.  Il ne reste qu`à jouer de la porte.");
}  // fin de setup()

void loop() {
  if (++rendu > 100) { rendu = 0; Serial.println("Nous voici en début de boucle."); }
  if (millis()-dernBoutonClavier < 5000) {
    digitalWrite(pinDER, LOW);
    digitalWrite(pinDEV, LOW);
    digitalWrite(pinDEB, HIGH);
  } else {
    codeEntree = "";
    digitalWrite(pinDER, LOW);
    digitalWrite(pinDEV, LOW);
    digitalWrite(pinDEB, LOW);
  }
  char touche = clavier.getKey();
  if ( (!cartes.PICC_IsNewCardPresent() || !cartes.PICC_ReadCardSerial()) && touche == NO_KEY ) {
    delay(50);
    return;
  }
  Serial.println("Nous voici en analyse de carte.");
  digitalWrite(pinDER, LOW);
  digitalWrite(pinDEV, LOW);
  digitalWrite(pinDEB, HIGH);
  libre = "ouvrons";
  sens = 1;
  if (carteValide(cartes.uid.uidByte, cartes.uid.size)) { 
    Serial.println("La carte a été jugée valide.");
  } else if (touche != NO_KEY) {
    if (libre != "oui") { return; }
    Serial.println("Entrons ici dans les tests de clavier");
    if (String(touche) == "*") { 
      //Demande de fermeture
      sens = -1;
      libre = "fermons";
    } else if (String(touche) == "#") {
      //Testons validité du code
      if (codeEntree != codeValide ) { 
        digitalWrite(pinDEV, LOW);
        digitalWrite(pinDEB, LOW);
        for (int x=0; x<3; x++) { digitalWrite(pinDER, HIGH); delay(100); digitalWrite(pinDER, LOW);  delay(50); }
        for (int x=0; x<5; x++) { digitalWrite(pinDER, HIGH); delay(30);  digitalWrite(pinDER, LOW);  delay(25); }
        codeEntree = ""; 
        return; 
      }
    } else {
      codeEntree = codeEntree + String(touche);
      digitalWrite(pinDER, LOW);
      digitalWrite(pinDEV, LOW);
      digitalWrite(pinDEB, HIGH);
      dernBoutonClavier = millis();
      return;
    }
    Serial.println("Fin des tests de clavier");
  }

  Serial.println("Activons les mouvements du moteur");
  if (digitalRead(pinSW2) == LOW) {
    sens = -1;
    libre = "fermons";
  }

  digitalWrite(pinDER, LOW);
  for (int x=0; x<5; x++) {
      digitalWrite(pinDEB, HIGH);
      delay(200);
      digitalWrite(pinDEV, LOW);
      digitalWrite(pinDEB, LOW);
      delay(50);
  }
  Serial.println("Fin du signal lumineux confirmant la lecteur réussie.  On passe au jaune.");
  Serial.print  ("État de la situation: ");
  Serial.println(libre);

  digitalWrite(pinDER, HIGH);
  digitalWrite(pinDEV, HIGH);
  digitalWrite(pinDEB, LOW);
    Serial.print  ("Vitesse du moteur: ");
    Serial.println(vitesseMax);
    Serial.print  ("Pas du moteur: ");
    Serial.println(pas);
  int tours = 1;
  int vitesse = 100;
  
  //Mouvement
  while (libre == "ouvrons" || libre == "fermons") {
    if (tours/1000 == round(tours/1000) && vitesse < vitesseMax ) { 
      ////Accéléeration du moteur
      vitesse = vitesse+50; moteur.setSpeed(vitesse); 
      Serial.print  ("Nouvelle vitesse fixée à "); 
      Serial.println(vitesse);  
    }
    ////Fin de course atteinte, on met un terme au movement.
    if ((digitalRead(pinSW2) == LOW && libre == "ouvrons") || (digitalRead(pinSW1) == LOW && libre == "fermons")) {libre = "oui"; } 
    moteur.step(sens * pas);
    delay(10);
    tours=tours+1;
  }

  //Mise au repos du moteur  
  digitalWrite(pinMO1, LOW);
  digitalWrite(pinMO2, LOW);
  digitalWrite(pinMO3, LOW);
  digitalWrite(pinMO4, LOW);

  //Indication de l'état du verrou
  if (digitalRead(pinSW1) == HIGH) {
    ////La porte peut être ouverte
    digitalWrite(pinDER, LOW);
    digitalWrite(pinDEV, HIGH);
  }
  if (digitalRead(pinSW2) == HIGH) {
    ////La porte est verrouillée
    digitalWrite(pinDER, HIGH);
    digitalWrite(pinDEV, LOW);
  }
  delay(1900);
  digitalWrite(pinDER, LOW);
  digitalWrite(pinDEV, LOW);
  digitalWrite(pinDEB, LOW);
  codeEntree = "";
  libre = "oui";
} //Fin de loop()


bool carteValide(byte *buffer, byte bufferSize) {
  String pat = "";
  for (byte i = 0; i < bufferSize; i++) {
    pat = pat + String(buffer[i] < 0x10 ? " 0" : " ");
    pat = pat + String(buffer[i], HEX);
  }
  pat.toUpperCase();
  pat.trim();
  return (pat=="89 A3 F0 97") ?  true : false;
}
