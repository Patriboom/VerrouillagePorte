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
Voir toutes les utilités possibles de RaspPico en [cliquant ici](https</td><td> //pico.pinout.xyz/)

<table>
<tr><td>Broche 1</td><td>  GPIO-00 </td><td>  clavier 4x4 -> 8</td><td> fil blanc-brun</td></tr>
<tr><td>Broche 2</td><td>  GPIO-01 </td><td>  clavier 4x4 -> 7</td><td> fil brun</td></tr>
<tr><td>Broche 3</td><td>  GND</td></tr>
<tr><td>Broche 4</td><td>  GPIO-02 </td><td>  Moteur -> 4</td><td> fil blanc-orange</td></tr>
<tr><td>Broche 5</td><td>  GPIO-03 </td><td>  Moteur -> 3</td><td> fil blanc-bleu</td></tr>
<tr><td>Broche 6</td><td>  GPIO-04 </td><td>  Moteur -> 2</td><td> fil blanc-vert</td></tr>
<tr><td>Broche 7</td><td>  GPIO-05 </td><td>  Moteur -> 1</td><td> fil blanc-brun</td></tr>
<tr><td>Broche 8</td><td>  GND</td></tr>
<tr><td>Broche 9</td><td> </td></tr>
<tr><td>Broche 10</td><td>  GPIO-07 </td><td>   clavier 4x4 -> 6</td><td>fil blanc-orange</td></tr>
<tr><td>Broche 11</td><td>  GPIO-08 </td><td>   clavier 4x4 -> 5</td><td>fil orange</td></tr>
<tr><td>Broche 12</td><td>  GPIO-09 </td><td>   clavier 4x4 -> 4</td><td>fil blanc-bleu</td></tr>
<tr><td>Broche 13</td><td>  GND</td></tr>
<tr><td>Broche 14</td><td>  GPIO-10 </td><td>   clavier 4x4 -> 3</td><td>fil bleu</td></tr>
<tr><td>Broche 15</td><td>  GPIO-11 </td><td>   clavier 4x4 -> 2</td><td>fil blanc-vert</td></tr>
<tr><td>Broche 16</td><td> </td></tr>
<tr><td>Broche 17</td><td>  GPIO-13 </td><td>  DEL tricolor -> rouge</td><td>fil orange</td></tr>
<tr><td>Broche 18</td><td>  GND</td></tr>
<tr><td>Broche 19</td><td>  GPIO-14 </td><td>  DEL tricolor -> vert</td><td>fil vert</td></tr>
<tr><td>Broche 20</td><td>  GPIO-15 </td><td>  DEL tricolor -> bleu</td><td>fil bleu</td></tr>
<tr><td>Broche 21</td><td>  SPI -> RX </td><td>  Carte identification -> MISO  </td><td> fil blanc-vert</td></tr>
<tr><td>Broche 22</td><td>  SPI -> CS </td><td>  Carte identification -> SDA  </td><td> fil blanc-bleu</td></tr>
<tr><td>Broche 23</td><td>  GND</td></tr>
<tr><td>Broche 24</td><td>  SPI -> CLK </td><td>  Carte identification -> SCK  </td><td> fil blanc-brun</td></tr>
<tr><td>Broche 25</td><td>  SPI -> TX </td><td>  Carte identification -> MOSI  </td><td> fil bleu</td></tr>
<tr><td>Broche 26</td><td>  GPIO-20 </td><td>  clavier 4x4 -> 1</td><td> vert</td></tr>
<tr><td>Broche 27</td><td>  GPIO-21 </td><td>  Carte identification -> RST </td><td> fil vert</td></tr>
<tr><td>Broche 28</td><td>  GND</td></tr>
<tr><td>Broche 29</td><td>  GPIO-22 </td><td>  Bouton d'activation de la barrure, côté maison</td<td>>fil bleu</td></tr>
<tr><td>Broche 30</td><td>  GPIO-26 </td><td>  Interrupteur fermé lorsque la porte est fermée -> SGN</td><td>fil blanc-vert</td></tr>
<tr><td>Broche 31</td><td>  GPIO-27 </td><td>  Interrupteur fermé lorsque la porte est ouverte -> SGN</td><td>fil vert</td></tr>
<tr><td>Broche 32</td><td>  GND</td></tr>
<tr><td>Broche 33</td><td> </td></tr>
<tr><td>Broche 34</td><td> </td></tr>
<tr><td>Broche 35</td><td> </td></tr>
<tr><td>Broche 36</td><td>  3.3 VCC </td><td>  Alimentation de divers composants en 3.3 volts</td><td>fils oranges</td></tr>
<tr><td>Broche 37</td><td> </td></tr>
<tr><td>Broche 38</td><td>  GND </td><td>  Mise à terre</td>fils bruns</tr>
<tr><td>Broche 39</td><td>  5VCC </td><td>  Alimentation du Rasp Pico</td><td>fil rouge</td></tr>
<tr><td>Broche 40</td><td> </td></tr>
</table>





[Câblage](04_Cablage.md)  <<<  [Table des matières](README.md)   >>>    [Impression 3d](06_Impression_3d.md)
