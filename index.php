<html>
<head>
<title>Anthropologie</title>
</head>
<body color="#FFFFFF" bgcolor="#000000" link="#FF9900" vlink="#FFCC00">
<h1 style="text-align: center; color: yellow; ">Sous-sous-répertoire VerrouillagePorte</h1>
<br /><br />
 <table class="Patrick" width="100%" >
<?php
function alpha($var) {
	return (!is_numeric($var));
}
function PasVide($var) {
	return (strlen($var) > 1);
}
function permis($var) {
	return (!in_array($var, array(".", "..","BanqueDeCodes")));
}
function purete($var) {
	return (in_array(substr($var, -4), array(".php",".htm","html")));
}
function Repertoire($var) {
	return (strpos($var, ".") == 0);
}
function sansHTM($var) {
	return (in_array(substr($var, -4), array(".php")));
}


$SousMenu = scandir(".", SCANDIR_SORT_ASCENDING);
$SousMenu = array_filter($SousMenu, "alpha");
$SousMenu = array_filter($SousMenu, "permis");
$SousMenu = array_filter($SousMenu, "PasVide");
$Outils = array_filter($SousMenu, "purete");
$Outils = array_filter($SousMenu, "sansHTM");
$SousMenu = array_diff($SousMenu, $Outils);
$SousMenu = array_filter($SousMenu, "Repertoire");

$compte = 0;
echo '<td align="center" width="20%"><a href="../index.php"><img src="../../../images/dossier2.png" width="100" /><br clear="all">..</a><br /></td>';
foreach ( $SousMenu as $ind => $Projet ) {
	if (++$compte >= 5) { echo '</tr><tr>'; $compte = 0; }
	echo '<td align="center" width="20%"><a href="'.$Projet.'/index.php"><img src="../../../images/dossier.png" width="100" /><br clear="all">'.$Projet.'</a><br /></td>';
}
for ($x=$compte; $x<4; $x++) {
	echo '</td><td>'; $compte = 0;
}
?>
        	</td>
        	</tr>
        </table>
</body>
</html>
