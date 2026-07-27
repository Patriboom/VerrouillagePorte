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

Voici la liste des connexions à effectuer entre les différents composants et RaspPico:

## Liste des GPIO attribués au projet ci-bas
* 00 clavier 4x4 - fil blanc-brun
* 01 clavier 4x4 - fil brun
* 02 Moteur - fil blanc-orange
* 03 Moteur - fil blanc-bleu
* 04 Moteur - fil blanc-vert
* 05 Moteur - fil blanc-brun
* 06
* 07 clavier 4x4 - blanc-orange
* 08 clavier 4x4 - orange
* 09 clavier 4x4 - blanc-bleu
* 10 clavier 4x4 - bleu
* 11 clavier 4x4 - blanc-vert
* 12
* 13 DEL tricolor - rouge
* 14 DEL tricolor - vert
* 15 DEL tricolor - bleu
* 16 Carte identification    - fil blanc-vert
* 17 Carte identification    - fil blanc-bleu
* 18 Carte identification    - fil blanc-brun
* 19 Carte identification    - fil bleu
* 20 clavier 4x4 - vert
* 21 Carte identification    - fil vert
* 22 Bouton d'activation de la barrure, côté maison
* 26 pinSW1 - Interrupteur fermé lorsque la porte est fermée
* 27 pinSW2 - Interrupteur fermé lorsque la porte est ouverte
* 28
* 29




[Câblage](04_Cablage.md)  <<<  [Table des matières](README.md)   >>>    [Impression 3d](06_Impression_3d.md)
