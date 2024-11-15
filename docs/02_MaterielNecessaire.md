# 2. Liste du matériel, des bibliothèques et outils nécessaires

## Électrique
* Transformateur 120 VAC -> 5 VDC
* Plusieurs sections de fil (un câble réseau peut fournir tout cela, en 8 couleurs)
* Fils à connecteurs Dupont

## Électronique

<table width="100%" border="0">
	<tr><td></td><td>Carte perforée aux dimensions appropriées ( au moins 10 par 24 trous espacés de 2.54 mm)</td></tr>
<tr><td><img src="../images/composants/tri-color-led.jpg" height="100" align="middle" /></td><td>DEL trois couleurs (RVB) à anode commune</td></tr>
<tr><td></td><td> Deux interrupteurs</td></tr>
<tr><td><img src="../images/composants/controleur_evidence.jpg" height="100" align="middle" /> </td><td>Module de pilote de moteur pas à pas ULN2003</td></tr>
<tr><td><img src="https://external-content.duckduckgo.com/iu/?u=https%3A%2F%2Ftse1.mm.bing.net%2Fth%3Fid%3DOIP.Z8VwK4ozSmAyzHd_4jV9HgHaHa%26pid%3DApi&f=1&ipt=95ebf6e0bbe265e8812947de3e8391b4048b1301b2ddf30e26ec032f864f3014&ipo=images" height="100" alt="Image d'internet: Carte magnétique" align="middle" /></td><td>Module RF5 RC522  (lecteur de cartes magnétiques)</td></tr>
<tr><td><img src="../images/composants/moteur_evidence.jpg" height="100" align="middle" /></td><td>Moteur pas à pas 28BVJ-48 (5 Volts)</td></tr>
<tr><td><img src="https://www.electronics-lab.com/wp-content/uploads/2021/01/Hands_On_with_the_RP2040_and_Pico_the_First_In_House_Silicon_and_Microcontroller_From_Raspberry_Pi_Hackster_io.jpg " height="100" align="middle" alt="Image d`internet: Rasp PI pico" /></td><td>Raspberry PI Pico</td></tr>
<tr><td><img src="../images/composants/clavierMembrane_4x4.jpg" width="100" align="middle" alt="Image d'internet: Clavier à membrane" /></td><td>(option clavier à membrane) .. et oui ! ... le clavier à membrane</td></tr>
</table>
  
  

## Impression 3d
<table width="100%" border="0">
<tr><td colspan="2">Imprimer les quatre composantes du support en PLA</td></tr>
	<tr><td>Une base (structure)</td><td><img src="../images/impression3d/base.jpg" height="100" align="middle" /></td></tr>
    <tr><td>Une vis sans fin (boulon)</td><td><img src="../images/impression3d/boulon.jpg" height="100" align="middle" /></td></tr>
    <tr><td>Un butoir</td><td><img src="../images/impression3d/butoir.jpg" height="100" align="middle" /></td></tr>
    <tr><td>Un curseur</td><td><img src="../images/impression3d/curseur.jpg" height="100" align="middle" /></td></tr>
<tr><td colspan="2">option: boîtier pour clavier en trois sections</td></tr>
    <tr><td>Boîtier</td><td></td></tr>
    <tr><td>Dessus</td><td></td></tr>
    <tr><td>Couvercle</td><td></td></tr>
C'est ici le modèle gratuitementt par [kolec sur cults3d](https://cults3d.com/fr/mod%C3%A8le-3d/gadget/arduino-keypad-4x4-panel)
</td></tr>
</table>

## Informatique
* Éditeur et compilateur de code [Arduino IDE](https://www.arduino.cc/en/software)
* [Bibliothèques installées](../tree/main/src/bibliotheques): 
    * Stepper.h
    * SPI.h
    * MFRC522.h
    * (pour l'option clavier à membrane): Keypad.h
* Pilote de carte: Raspberry PI Pico -> utilisez votre interface Arduino-IDE pour cela

## Mécanique
* Verrou
* Vis à bois

## Outils
* Kit à souder  <img ggggsrc="https://www.cdiscount.com/pdt2/6/0/7/1/700x700/mon4895179938607/rw/fer-a-souder-electronique-temperature-reglable-60w.jpg" height="100" align="middle" />
    * fer à souder 
    * étain
* Perceuse & forêts à bois <img src="https://www.cdiscount.com/pdt2/3/2/0/1/700x700/auc2008563793320/rw/xuy-15pcs-jeu-de-forets-a-bois-plat-a-pique-hexago.jpg" height="100" align="middle" />
* Pistolet à colle chaude et colle chaude <img src="https://www.malinelle.com/ressources/cache/imgcorner/3/9/39110_1_1024x1024.jpg" height="100" align="middle" />
* Tous les petits outils habituels permettant de couper et dégainer les fils
* Tourne-vis

---

[Introduction](01_Introduction_Presentation.md)  <<<  [Table des matières](README.md)   >>>    [Montage](03_Montage.md)
