J’ai repris l’UML de Hans.

En gros j’ai changé ça :

- pour les coins, avant on mettait directement une Ressource, sauf qu’un coin peut être vide ou contenir un objet aussi, donc j’ai ajouté un petit concept Coin.
- pour le plateau, avant c’était juste une liste de cartes. J’ai ajouté la position + recto/verso, sinon on peut pas vraiment gérer les placements et les recouvrements.
- pour la main du joueur, j’ai remplacé Carte par CarteDePlacement, parce qu’on ne va pas avoir des cartes objectif ou départ dans la main. J’ai aussi séparé l’objectif secret.
- pour les Dorures/Objectifs, la condition était seulement un vector<Ressource>, alors que toutes les conditions ne dépendent pas uniquement des ressources, donc j’ai mis une ConditionScore plus générale.
- pour les pioches, j’ai surtout corrigé des petits trucs : noms des constructeurs, piocher() qui ne peut pas être const, doublons de nb, cartesDepart, etc.
- dans le Manager, j’ai ajouté juste ce qu’il faut pour représenter une partie : les 2 cartes Ressource visibles, les 2 Dorures visibles, les objectifs communs, le joueur courant, le tour et la fin de partie.
- pour le solo, j’ai juste ajouté Tybor avec ses ressources, son score et jouerTour(). Comme ça on ne le traite pas comme un joueur normal et on pourra éventuellement ajouter une autre IA plus tard.
- j’ai aussi corrigé le doublon piocheRessource dans le Manager, la deuxième devait être piocheDorure.
