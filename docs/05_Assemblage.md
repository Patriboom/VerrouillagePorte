# 5. L'assemblage
---

Une carte spécialisée peut vous accommoder.

<img src="../images/docs_05/CarteSpecialisee.jpg" alt="Carte spécialisée disponible, écrivez-moi" width="400" />

Je l'ai créée pour mes besoins, mais j'ai quelques copies disponibles.  Écrivez-moi à foi02@cartefoi.net


Sur une carte spécialisée ou une carte gérérique perforée, le montage sera le même.

La numérotation des broches de Rasp Pico est importante.  Lorsque vous regardez le micro-contrôleur en le plaçant verticalement, le connecteur USB vers le haut, les numéros vont comme suit.
La broche 1 est en haut à gauche.  En descendant sur le côté gauche, vous aurez ainsi les broches 1 à 20.
Puis, en remontant sur la droite, vous aurez les broches 21 à 40; la broche 40 étant l'alimentation 5 VCC du module et la 39 la mise à terre principale.
Normalement, les numéros 1, 2 et 39 sont imprimés sur la carte, comme le montre l'image suivante.
<img src="../images/docs_05/PicoNumPin.jpg" alt="Numérotation" heigh="400" />

## Description des broches de RaspPi, selon l'utilité de ce projet.
Voir toutes les utilités possibles de RaspPico en [cliquant ici](https://pico.pinout.xyz/)

* Broche 1: GPIO-00 ... clavier 4x4 - fil blanc-brun
* Broche 2: GPIO-01 ... clavier 4x4 - fil brun
* Broche 3: GND
* Broche 4: GPIO-02 ... Moteur - fil blanc-orange
* Broche 5: GPIO-03 ... Moteur - fil blanc-bleu
* Broche 6: GPIO-04 ... Moteur - fil blanc-vert
* Broche 7: GPIO-05 ... Moteur - fil blanc-brun
* Broche 8: GND
* Broche 9:
* Broche 10: GPIO-07 ...  clavier 4x4 - blanc-orange
* Broche 11: GPIO-08 ...  clavier 4x4 - orange
* Broche 12: GPIO-09 ...  clavier 4x4 - blanc-bleu
* Broche 13: GND
* Broche 14: GPIO-10 ...  clavier 4x4 - bleu
* Broche 15: GPIO-11 ...  clavier 4x4 - blanc-vert
* Broche 16:
* Broche 17: GPIO-13 ... DEL tricolor - rouge
* Broche 18: GND
* Broche 19: GPIO-14 ... DEL tricolor - vert
* Broche 20: GPIO-15 ... DEL tricolor - bleu
* Broche 21: SPI -> MISO ... Carte identification    - fil blanc-vert
* Broche 22: SPI -> SDA ... Carte identification    - fil blanc-bleu
* Broche 23: GND
* Broche 24: SPI -> CLOCK ... Carte identification    - fil blanc-brun
* Broche 25: SPI -> MOSI ... Carte identification    - fil bleu
* Broche 26: GPIO-20 ... clavier 4x4 - vert
* Broche 27: GPIO-21 (RST) ... Carte identification    - fil vert
* Broche 28: GND
* Broche 29: GPIO-22 ... Bouton d'activation de la barrure, côté maison
* Broche 30: GPIO-26 ... Interrupteur fermé lorsque la porte est fermée
* Broche 31: GPIO-27 ... Interrupteur fermé lorsque la porte est ouverte
* Broche 32: GND
* Broche 33:
* Broche 34:
* Broche 35:
* Broche 36: 3.3 VCC ... Alimentation de divers composants en 3.3 volts
* Broche 37:
* Broche 38: GND ... Mise à terre
* Broche 39: 5VCC ... Alimentation du Rasp Pico
* Broche 40:





[Câblage](04_Cablage.md)  <<<  [Table des matières](README.md)   >>>    [Impression 3d](06_Impression_3d.md)
