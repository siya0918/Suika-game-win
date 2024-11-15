# Dépôt de Suika Game

- [**Description et Objectif du Jeu**](https://github.com/SWMR-Siya/Suika-game-win?tab=readme-ov-file#description-et-objectif-du-jeu)
- [**Installation**](https://github.com/SWMR-Siya/Suika-game-win?tab=readme-ov-file#installation-)
- [**Explication de l'interface**](https://github.com/SWMR-Siya/Suika-game-win?tab=readme-ov-file#explication-de-linterface-)
- [**Mode de jeu**](https://github.com/SWMR-Siya/Suika-game-win?tab=readme-ov-file#mode-de-jeu-)
- [**Comment jouer ?**](https://github.com/SWMR-Siya/Suika-game-win?tab=readme-ov-file#comment-jouer--)
- [**Contribution ?**](https://github.com/SWMR-Siya/Suika-game-win?tab=readme-ov-file#contribution--)


## Description et Objectif du Jeu

Sukia Game est un jeu où le joueur doit placer des fruits dans un récipient. Au début, le joueur dispose de fruits de petite taille, dans notre cas, une myrtille. En fusionnant deux fruits de même type, le joueur obtient un fruit de taille supérieure, jusqu'à atteindre une pastèque. Le joueur perd lorsque le contenu dépasse la limite du récipient. Une ligne rouge apparaît et le joueur dispose de 3 secondes pour ajuster ses fruits, sans quoi il perd la partie. À chaque fusion, votre score augmente en fonction des points attribués à chaque fruit (affichés dans le jeu et expliqués dans 'Explication de l'interface').

### Ordre des Fruits (du plus petit au plus grand)
- Myrtille
- Cerise
- Fraise
- Mandarine
- Orange
- Pomme
- Pêche
- Poire
- Melon
- Ananas
- Pastèque

## Installation :
Vous pouvez installer le jeu en téléchargeant le zip de ce projet via le bouton vert **Code** -> **Download ZIP** ou [**via ce lien**](https://github.com/SWMR-Siya/Suika-game-win/archive/refs/heads/main.zip).

Ensuite, vous devez extraire le fichier téléchargé, soit par le logiciel de base de Windows, soit par un autre logiciel tiers comme WinZip.

Une fois l'ensemble des fichiers extrait, un exécutable nommé `Suika-game` se trouvera dans le dossier principal. Aucune installation n'est requise et aucune sauvegarde ne sera stockée sur votre ordinateur.

Si Windows empêche l'exécution du jeu avec un message du type "Windows a protégé votre ordinateur", vous pouvez cliquer sur "Informations complémentaires" -> "Exécuter quand même".

Bonne partie !



## Explication de l'interface :
À gauche, vous trouverez `les images des 11 fruits` avec `leurs noms` et `leurs scores`, qui seront pris en compte lors des fusions.

Juste en dessous des images des 11 fruits, vous trouverez 3 paragraphes de texte.
- le but de jeu.
- les commandes
- Explication de mode de jeu.

Sur la gauche de l'écran de jeu  :
- Le temps au format : hh.mm.ss.
- Record : affiche votre record à partir du fichier /doc/.record.txt et se met à jour lorsqu'un nouveau record est établi (à l'écran et dans le fichier).
- Score : se met à jour en temps réel à chaque gain de score.

`Fond du récipient` : représente le fond du récipient, où le bas indique la limite du récipient et les bords gauche/droit du récipient où vos fruits seront bloqués.

Le fruit le plus haut est `le fruit jouable`, que vous pouvez déplacer vers la droite ou la gauche.

La ligne rouge horizontale au-dessous du fruit jouable est un avertissement que vous avez dépassé la limite du récipient. Dans ce cas, un compte à rebours de 3 secondes apparaît au centre de la fenêtre

`Fruit Actuel` : NOM DE FRUIT -> répresent le nom de fruit que vous jouez.

`Fruit Next` : NOM DE FRUIT + IMAGE DE FRUIT -> répresent le nom de fruit que vous allez jouez aprés le fruit actuel.

Entre les deux sections "Fruit Actuel" et "Fruit Next", un texte indique deux statuts :
 - `OK` : Vous pouvez lancer le fruit jouable.
 - `WAIT` : Vous ne pouvez pas lancer de fruit, il faut attendre que le statut passe en `OK`.

## Mode de jeu :
Au début du jeu, vous serez invité à choisir l'un des trois modes de jeu en saisissant le numéro correspondant sur le terminal :

- `Mode 0` : Mode normal sans limite. C'est le mode officiel de Sukia Game où vous ne gagnez pas et l'objectif est de battre votre propre record.
- `Mode 1` : Mode normal. Vous gagnez dès l'obtention d'une pastèque.
- `Mode 2` : Mode chaos sans limite. Similaire au mode normal, mais les fruits tombent automatiquement et plus rapidement. Vous devez simplement vous déplacer à droite et à gauche pour jouer.
- `Mode 3` : Mode Melon. Les fruits ne commencent pas par la myrtille mais par le melon, ce qui vous permet d'obtenir facilement des pastèques et de gagner rapidement.

## Comment jouer ? :
Vous avez 4 touches affectées pour jouer :

- `d` : Déplace le fruit jouable vers la droite.
- `q` : Déplace le fruit jouable vers la gauche.
- `barre espace` : Permet de faire tomber le fruit. Dans le mode chaos sans limite, la touche espace est désactivée.
- `o` : Fait perdre le joueur. Cela permet de quitter le jeu plus rapidement.
- 

***Mise à jour***
Vous pouvez maintenant jouer avec votre souris. Maintenez le bouton gauche enfoncé pour déplacer le fruit. Relâchez pour faire tomber le fruit.

##Contribution
3 étudiants dont moi sur ce projet
