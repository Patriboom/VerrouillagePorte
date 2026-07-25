# 7. Programmation
La programmation est basée sur [Arduino](https://www.arduino.cc/).  L'outils ArduinoIDE est bien connu, répandu et docummenté.
Le code tout entier est disponible dans la banque de bibliothèques de ArduinoIDE.

Ici, je vous explique les différentes parties du code afin que vous puissiez le comprendre ou l'adapter à vos besoins.
Au travers du code, vous trouverez une foule de commentaires et même des repères et vérifications envoyés à la console afin que vous puissiez superviser la progression de la mise en oeuvre en direct.  Je ne reproduira pas ici les commentaires du code.

## Appel des bibliothèques nécessaires
>	  #include <Stepper.h>
>	  #include <SPI.h>
>	  #include <MFRC522.h>


## Définition des variables de contrôle
>	  int delai = 60000;
>	  int pas = 20;
>	  int sens = 1;
>	  int vitesseMax = 700;
>	  String libre = "oui";
>	  bool tourne = false;
>	  bool initOUV = false;
>	  bool initFER = false;
>	  int compteLOW = 0;
>	  int compteDEL = 0;
>	  int pinSW1 = 27;
>	  int pinSW2 = 26;
>	  int pinMO1 = 2;
>	  int pinMO2 = 3;
>	  int pinMO3 = 4;
>	  int pinMO4 = 5;
>	  int pinDER = 13;
>	  int pinDEV = 14;
>	  int pinDEB = 15;
>	  int pinBOUT = 22;
>	  byte CRT_RST = 21;
>	  byte CRT_SSC = 17;

## Définition des variables de travail
> int rendu = 0;


## Création des objets
>	  Stepper moteur(32, pinMO1, pinMO3, pinMO2, pinMO4);
>	  MFRC522 cartes(CRT_SSC, CRT_RST);

## Définitions communes (setup)
>	    Serial.begin(115200);
>	    delay(1550);
>	    Serial.println("");
>	    Serial.println("Bonjour à vous; voici vos informations de suivi ... ");
>	    SPI.begin();              // Init SPI bus
>	    Serial.println("SPI est démarré.");
>	    cartes.PCD_Init(); // Init each MFRC522 card
>	    cartes.PCD_DumpVersionToSerial();
>	    Serial.println("---------------------------------------");
>	    pinMode(pinSW1, INPUT);   //Interrupteur fermé lorsque la porte est ouverte  => DEL vert
>	    pinMode(pinSW2, INPUT);   //Interrupteur fermé lorsque la porte est fermée   => DEL rouge
>	    pinMode(pinMO1, OUTPUT);  //Moteur 1
>	    pinMode(pinMO2, OUTPUT);  //Moteur 2
>	    pinMode(pinMO3, OUTPUT);  //Moteur 3
>	    pinMode(pinMO4, OUTPUT);  //Moteur 4
>	    pinMode(pinDER, OUTPUT);  //rouge de la DEL
>	    pinMode(pinDEV, OUTPUT);  //vert de la DEL
>	    pinMode(pinDEB, OUTPUT);  //bleu de la DEL
>	    pinMode(pinBOUT, INPUT);
>	    digitalWrite(pinMO1, LOW);
>	    digitalWrite(pinMO2, LOW);
>	    digitalWrite(pinMO3, LOW);
>	    digitalWrite(pinMO4, LOW);
>	    digitalWrite(pinDER, HIGH);
>	    digitalWrite(pinDEV, HIGH);
>	    digitalWrite(pinDEB, HIGH);
>	    delay(1000);
>	    if (digitalRead(pinSW1) == digitalRead(pinSW2)) {
>	      Serial.println("Nous avons trouvé le verrou en position médiane; nous ouvrons la porte.");
>	      mouvonsMoteur(-1, "fermons");
>	    }
>	    Serial.println("Voici que tout est défini.  Il ne reste qu`à jouer de la porte.");
>	  }  // fin de setup()


## Traitement en boucle (loop)
>	    rendu = rendu + 1;
>	    if (rendu < 100 && libre == "oui") {
>	      digitalWrite(pinDER, HIGH);
>	      digitalWrite(pinDEV, LOW);
>	      digitalWrite(pinDEB, LOW);
>	    } else if (rendu < 200 && libre == "oui") {
>	      digitalWrite(pinDER, HIGH);
>	      digitalWrite(pinDEV, HIGH);
>	      digitalWrite(pinDEB, LOW);
>	    } else if (rendu < 300 && libre == "oui") {
>	      digitalWrite(pinDER, LOW);
>	      digitalWrite(pinDEV, HIGH);
>	      digitalWrite(pinDEB, LOW);
>	    } else if (rendu < 400 && libre == "oui") {
>	      digitalWrite(pinDER, LOW);
>	      digitalWrite(pinDEV, HIGH);
>	      digitalWrite(pinDEB, HIGH);
>	    } else if (rendu < 500 && libre == "oui") {
>	      digitalWrite(pinDER, LOW);
>	      digitalWrite(pinDEV, LOW);
>	      digitalWrite(pinDEB, HIGH);
>	    } else if (rendu < 600 && libre == "oui") {
>	      digitalWrite(pinDER, HIGH);
>	      digitalWrite(pinDEV, LOW);
>	      digitalWrite(pinDEB, HIGH);
>	    } else {
>	      rendu = -1;
>	      Serial.println("Nous voici en début de boucle.");
>	    }
>	    if (libre != "oui") { return; }
>	    compteLOW = (digitalRead(pinBOUT) == HIGH) ? ++compteLOW : 0;
>	    if (compteLOW > 10 ) { compteLOW = 0; mouvonsMoteur(0, ""); }
>	    if ( (!cartes.PICC_IsNewCardPresent() || !cartes.PICC_ReadCardSerial())) {
>	      return;
>	    } else if (carteValide(cartes.uid.uidByte, cartes.uid.size)) {
>	      mouvonsMoteur(0, "");
>	    }
>	  } //Fin de loop()

### Contrôle de la validité de la carte
>	  bool carteValide(byte *buffer, byte bufferSize) {
>	    Serial.print  ("Carte présente et lisible; voici sa valeur : ");
>	    String pat = "";
>	    for (byte i = 0; i < bufferSize; i++) {
>	      pat = pat + String(buffer[i] < 0x10 ? " 0" : " ");
>	      pat = pat + String(buffer[i], HEX);
>	    }
>	    pat.toUpperCase();
>	    pat.trim();
>	    if (pat == "") { Serial.println(" nulle."); return false; }
>	    Serial.print  (pat);
>	      for (byte i = 0; i < cartes.uid.size; i++) {
>	        cartes.uid.uidByte[i] = 0;
>	      }
>	    if (pat=="89 A3 F0 97") { Serial.println(" (valide)."); return true; }
>	    if (pat=="D3 B8 BD 38") { Serial.println(" (valide)."); return true; }
>	    if (pat=="72 67 B1 AB") { Serial.println(" (valide)."); return true; }
>	    Serial.println(" --- non valide.");
>	    return false;
>	  }

### Mouvement du moteur
>	  void mouvonsMoteur(int Sens, String SensMvt) {
>	    libre = (Sens == 0) ? "ouvrons" : SensMvt;
>	    sens = (Sens == 0) ? 1 : Sens;
>	    Serial.println("Activons les mouvements du moteur");
>	    if (digitalRead(pinSW2) == LOW) {
>	      sens = -1;
>	      libre = "fermons";
>	    }
>	    digitalWrite(pinDER, HIGH);
>	    digitalWrite(pinDEV, HIGH);
>	    digitalWrite(pinDEB, HIGH);
>	    if (Sens != 0) {
>	        for (int x=0; x<5; x++) {
>	            digitalWrite(pinDEB, LOW);
>	            delay(250);
>	            digitalWrite(pinDEB, HIGH);
>	            delay(250);
>	        }
>	    }
>	    Serial.print  ("État de la situation: ");
>	    Serial.print  ((libre == "ouvrons") ? "Femeture demandée. " : "Ouverture demandée. ");
>	    if (libre == "ouvrons") {
>	      digitalWrite(pinDER, LOW);
>	      digitalWrite(pinDEV, HIGH);
>	    } else {
>	      digitalWrite(pinDER, HIGH);
>	        digitalWrite(pinDEV, LOW);
>	    }
>	    digitalWrite(pinDEB, LOW);
>	    Serial.print  ("\tVitesse du moteur: ");
>	    Serial.print  (vitesseMax);
>	    Serial.print  ("\tPas du moteur: ");
>	    Serial.println(pas);
>	    int tours = 1;
>	    int vitesse = 100;
>	    //Mouvement
>	    while (libre == "ouvrons" || libre == "fermons") {
>	      if (tours/2500 == round(tours/2500) && vitesse < vitesseMax ) {
>	        ////Accéléeration du moteur
>	        vitesse = vitesse+50; moteur.setSpeed(vitesse);
>	      }
>	      ////Fin de course atteinte, on met un terme au movement.
>	      if ((digitalRead(pinSW2) == LOW && libre == "ouvrons") || (digitalRead(pinSW1) == LOW && libre == "fermons")) {libre = "annoncons"; }
>	      moteur.step(sens * pas);
>	      delay(10);
>	      tours=tours+1;
>	    }
>	    //Mise au repos du moteur
>	    digitalWrite(pinMO1, LOW);
>	    digitalWrite(pinMO2, LOW);
>	    digitalWrite(pinMO3, LOW);
>	    digitalWrite(pinMO4, LOW);
>	    //Indication de l'état du verrou
>	    digitalWrite(pinDER, HIGH);
>	    digitalWrite(pinDEV, HIGH);
>	    digitalWrite(pinDEB, HIGH);
>	    for (int x=0; x<5; x++) {
>	      if (digitalRead(pinSW1) == HIGH) {
>	        ////La porte peut être ouverte
>	        digitalWrite(pinDER, LOW);
>	        Serial.println("Porte verrouilée; partez l`esprit tranquille, car votre porte est sécurisée.");
>	      }
>	      if (digitalRead(pinSW2) == HIGH) {
>	        ////La porte est verrouillée
>	        digitalWrite(pinDEV, LOW);
>	        Serial.println("Porte déverrouillée; entrez!");
>	      }
>	      delay (250);
>	      digitalWrite(pinDER, HIGH);
>	      digitalWrite(pinDEV, HIGH);
>	      delay (250);
>	      libre = "oui";
>	    }
>	    delay(1900);
>	    digitalWrite(pinDER, HIGH);
>	    digitalWrite(pinDEV, HIGH);
>	    digitalWrite(pinDEB, HIGH);
>	    libre = "oui";
>	  }


---
[Impression 3d](06_Impression_3d.md) <<<  [Table des matières](README.md)  >>>  [Premier test](08_PremierTest.md)




