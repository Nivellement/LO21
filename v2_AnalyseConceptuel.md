# Analyse conceptuelle de Codex Naturalis

L'analyse conceptuelle permet d'identifier les principaux concepts nécessaires pour représenter le fonctionnement de **Codex Naturalis**. Le jeu est principalement organisé autour d'une **Partie**, de plusieurs **Joueurs**, de leurs **Cartes** et de leurs **Objectifs**.

## Partie

La **Partie** représente une partie complète de Codex Naturalis. Elle constitue le point central du modèle et regroupe les joueurs, les objectifs et les cartes utilisées pendant la partie.

```text
PARTIE
 ├── 2 à 4 JOUEURS
 ├── OBJECTIFS
 └── CARTES
```

## Joueur

Le **Joueur** représente un participant à la partie. Il possède les éléments nécessaires pour effectuer ses actions et suivre sa progression : une main de cartes, une aire de jeu, un objectif secret et un score.

```text
JOUEUR
 ├── 1 AIRE DE JEU
 ├── 1 MAIN
 ├── 1 OBJECTIF SECRET
 └── 1 SCORE
```

## Aire de jeu

L'**Aire de jeu** représente le Codex construit progressivement par un joueur. Elle contient les cartes posées par celui-ci et permet notamment de déterminer les ressources et objets actuellement disponibles.

```text
AIRE DE JEU
 └── CARTES POSÉES
```

## Main

La **Main** représente les cartes actuellement disponibles pour le joueur. Elle évolue au cours de la partie en fonction des cartes jouées et piochées.

```text
MAIN
 └── CARTES
```

## Carte

La **Carte** est le principal élément manipulé pendant la partie. Une carte possède plusieurs **coins** pouvant être recouverts lors du placement et peut comporter différents éléments utiles au joueur.

Les cartes sont regroupées en plusieurs catégories :

```text
CARTE
 ├── COINS
 ├── RESSOURCES
 └── OBJETS

CARTE
 ├── CARTE DE DÉPART
 ├── CARTE RESSOURCE
 └── CARTE DORURE
```

Les **Cartes Ressource** permettent notamment de fournir des ressources, tandis que les **Cartes Dorure** peuvent apporter des points et nécessiter certaines ressources pour être jouées. La carte de départ constitue le point initial de construction du Codex d'un joueur.

## Ressource

Les **Ressources** sont les éléments représentés sur les cartes et nécessaires à certaines actions, notamment au placement de certaines cartes Dorure. Leur disponibilité dépend des cartes visibles dans l'aire de jeu.

```text
RESSOURCE
 ├── VÉGÉTAL
 ├── ANIMAL
 ├── FONGIQUE
 └── INSECTE
```

## Objet

Les **Objets** sont des éléments présents sur certaines cartes. Ils peuvent être pris en compte dans certaines conditions de score.

```text
OBJET
 ├── PLUME
 ├── ENCRIER
 └── MANUSCRIT
```

## Objectif

Un **Objectif** définit une condition permettant au joueur d'obtenir des points supplémentaires. Les objectifs peuvent être communs à l'ensemble des joueurs ou attribués individuellement sous la forme d'un objectif secret.

```text
OBJECTIF
 ├── CONDITION
 └── VALEUR EN POINTS
```

## Score

Le **Score** représente les points accumulés par un joueur au cours de la partie. Il est notamment alimenté par les cartes jouées et les objectifs réalisés.

```text
SCORE
 └── NOMBRE DE POINTS
```

## Vue d'ensemble

Les concepts identifiés peuvent finalement être regroupés de la manière suivante :

```text
PARTIE
 │
 ├── JOUEURS
 │    ├── MAIN
 │    │    └── CARTES
 │    │
 │    ├── AIRE DE JEU
 │    │    └── CARTES
 │    │         ├── COINS
 │    │         ├── RESSOURCES
 │    │         └── OBJETS
 │    │
 │    ├── OBJECTIF SECRET
 │    └── SCORE
 │
 ├── OBJECTIFS
 │    ├── CONDITION
 │    └── VALEUR EN POINTS
 │
 └── CARTES
      ├── CARTE DE DÉPART
      ├── CARTE RESSOURCE
      └── CARTE DORURE
```
