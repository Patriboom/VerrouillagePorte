# 1.Introduction et présentation du projet
Ma résidence dispose - heureusement en cas d'urgence! - de deux portes d'accès.  Une d'entre elles mène vers un espace commun.  Elle ne pouvait pas être verrouillée.  L'autre mène à l'extérieur et se verrouille à clef.  Cependant, l'installation laisse à désirer; il est facile de forcer la serrure et d'entrer.  Je l'ai d'ailleurs fait à quelques reprises lorsque j'ai oublié ma clef!  Je voulais donc plus de sécurité et la possibilité de me « forcer » à ne pas oublier ma clef avant de partir.

## Présentation

Ce projet a été réalisé avec les composants électroniques que j'avais sous la main.  Bien sûr, il pourrait être meilleur, plus beau ou plus performant, mais ce sont les composants dans je disposais qui ont été assemblés et réunis afin de réaliser une opération utile à la sécurisation de ma résidence.

Sans surprise, la sécurité étant ce qui est visé lors de l'ajout d'un verrou, la sécurité doit aussi être visée lors de sa motorisation.  L'image ci-bas montre les composants AVANT la finition esthétique de la porte, ceux-ci étant installés dans la structure même de la porte.
<br clear="all">

<img src="../images/EnsemblePorte_Details.jpg" alt="Avant finition de la porte" width="300" />
<br clear="all">

## Fonctionnement
Ce système est basé sur un Raspberry Pi Pico qui gère l'activation d'un moteur par la lecture d'une carte magnétique.

<img src="https://www.electronics-lab.com/wp-content/uploads/2021/01/Hands_On_with_the_RP2040_and_Pico_the_First_In_House_Silicon_and_Microcontroller_From_Raspberry_Pi_Hackster_io.jpg " height="300" alt="Image d`internet: Rasp PI pico" /> 

<img src="https://external-content.duckduckgo.com/iu/?u=https%3A%2F%2Ftse1.mm.bing.net%2Fth%3Fid%3DOIP.Z8VwK4ozSmAyzHd_4jV9HgHaHa%26pid%3DApi&f=1&ipt=95ebf6e0bbe265e8812947de3e8391b4048b1301b2ddf30e26ec032f864f3014&ipo=images" height="300" alt="Image d'internet: Carte magnétique" />

<img src="https://www.fatalerrors.org/images/blog/1c6c31c44eaa0ae484c33991acc1eb0c.jpg" height="300" alt="Image d'internet: moteur à pas" />
<br clear="all">
<br clear="all">
Le système est appelé à gérer aussi la vérification d'un code d'accès introduit à l'aide d'un clavier à membrane.
<br clear="all"><br />
<img src="../images/composants/clavierMembrane_4x4.jpg" width="300" alt="Image d'internet: Clavier à membrane" />
<br clear="all"><br clear="all">
Le système électronique meut la barre d'un verrou en acier, barre d'environ 1cm de diamètre.

-----
[Table des matières](README.md)   >>>  [Le nécessaire](02_MaterielNecessaire.md)
