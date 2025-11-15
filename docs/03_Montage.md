# 3a. Le montage du circuit

## Le Raspberry PI pico sur une carte
Puisque vous serez appelé(e) à programmer ou corriger le programme à quelques reprises afin de répondre à vos besoin, je vous suggère de NE PAS souder le Raspberry PI Pico (ci-bas nommé Pico) directement sur la carte perforée.  Optez plutôt pour des broches mâles sur le Pico et des réceptacles femelles sur la carte perforée.

Si vous souhaitez limiter la consommation de broches et de matériel en général, vous pouvez limiter vos soudures aux seuls éléments utilisés.
<br clear="all" />
<img src="../images/docs_03/Pico_PinsUtilisees.jpg" align="middle" />
<br clear="all" />
<table width="100%">
	<tr><td colspan="5">Soudez les broches mâles sur le Raspberry PI Pico</td></tr>
	<tr>
		<td><img src="../images/docs_03/BrochesMales.jpg" width="200" align="middle" /></td>
		<td><img src="../images/docs_03/plus.png" align="middle" /></td>
		<td><img src="../images/docs_03/PicoSansPin.png" width="200" align="middle" alt="Image d`internet: Rasp PI pico" /></td>
		<td><img src="../images/docs_03/Fleche.png" align="middle" /></td>
		<td><img src="../images/docs_03/RaspPicoBroches.jpg" width="200" align="middle" alt="Raspberry avec broches" /></td>
	</tr>
	<tr><td colspan="5">Soudez les broches femelles sur la carte perforée.</td></tr>
	<tr>
		<td><img src="../images/docs_03/BrochesFemelles.jpg" width="200" align="middle" /></td>
		<td><img src="../images/docs_03/plus.png" align="middle" /></td>
		<td><img src="../images/docs_03/carteCircuit.png" height="200" align="middle" alt="Image d`internet: Rasp PI pico" /></td>
		<td><img src="../images/docs_03/Fleche.png" align="middle" /></td>
		<td><img src="../images/docs_03/carteMere_02.jpg" width="200" align="middle" alt="Carte mère" /></td>
	</tr>
</table>

Voici comment seront utilisées les broches du Pico dans notre projet.
<br clear="all" />
<img src="../images/docs_03/Pico_PinsComment.jpg" align="middle" />

# 3b. Le montage mécanique
À ce point, il serait bon de considérer l'installation du verrou sur votre porte.
Assurez-vous qu'il coulisse librement et facilement, que le verouillage se fasse sans effort de même que le déverrouillage.
Gardez en tête que le petit moteur développe peu de puissance, que le tout est assemblée avec du plastique imprimé et  - donc - que toutes les composantes sont fragiles.
Le mouvement du verrou doit donc en tous points être facile et fluide.

Les principaux points à vérifier:
* insértion (et retrait) du verrou dans le logement de fermeture: alignement parfait, aisance de mouvement.

	<video width="320" height="240" controls>
      <source src=”../images/videos/deverrouillage.mp4” type="video/mp4">
    </video>

* le tenon du verrou ne doit pas s'engager dans les fentes d'immobilisation.

<img src="../images/docs_03/entreeFourreau_clr.jpg" width="200" align="middle" alt="tenon en fourreau" />
<img src="../images/docs_03/entreeFourreau_des.jpg" width="200" align="middle" alt="tenon en fourreau" />
<img src="../images/docs_03/entreeFourreau_txt.jpg" width="200" align="middle" alt="tenon en fourreau" />
<img src="../images/docs_03/entreeFourreau_esp.jpg" width="200" align="middle" alt="tenon en fourreau" />

---

[Le nécessaire](02_MaterielNecessaire.md)  <<<  [Table des matières](README.md)   >>>    [Le câblage](04_Cablage.md)
