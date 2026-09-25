# Compte Rendu 1 - Projet Codex Naturalis

**Date de rendu :** Semaine du 21 septembre  
**Auteur responsable du livrable :** Ulysse Virlogeux--Chabaille (GI01)  
**Membres du groupe :**
1. Ulysse Virlogeux--Chabaille
2. Hans Vinçon
3. Victor Pottier
4. Zeineb Mokded

---

## 1. Liste des tâches et durée pour atteindre l'objectif de la semaine 1

L'objectif est de fournir un Compte rendu détaillé du travail fourni. Ce travail consistait à établir une analyse conceptuel complète pour débroussailler le terrain de l'UML (semaine 2).

| ID | Tâche Macro | Complexité estimée | Durée estimée | Responsable (Affectation a priori) |
| :--- | :--- | :--- | :--- | :--- |
| T1 | Appropriation du jeu | Faible | 2h? | Tous les membres |
| T2 | Note en Gdoc du travail fourni | Elever | Toute la semaine (travail étaler) | Hans Vinçon |
| T3 | Configuration de l'environnement Git et squelette projet | Basse | 1h | Ulysse Virlogeux--Chabaille |
| T4 | Brainstorming de l'Analyse Conceptuel (AC) | Haute | 3h | Tous les membres |
| T5 | Mise sur papier des concepts du jeu/AC | Basse | durant le brainstorming | Hans Vinçon - Ulysse Virlogeux--Chabaille |
| T6 | Redaction propre du CR1 + Analyse conceptuel | Elever | 2~3h | Ulysse Virlogeux--Chabaille |
| T7 | Review du CR | Basse | 30min | Hans Vinçon - Victor Pottier - Zeineb Mokded |

---

## 2. Bilan sur la cohésion de groupe et l'implication

**État de la cohésion :**  
Le groupe s’est principalement organisé via Instagram pour les échanges et discussions quotidiennes, qui n’avaient pas vocation à être conservés ou relus par la suite.

Afin de centraliser le travail et de faciliter son organisation, nous avons également mis en place un repository GitHub ainsi qu’un GitHub Project. Ces outils nous ont permis de répartir les tâches, de suivre leur avancement et de permettre à chacun de prendre en charge les missions qu’il souhaitait réaliser, tout en gardant une bonne visibilité sur le travail des autres membres.

Cette organisation nous a ainsi permis de centraliser les informations importantes et de faciliter la collaboration tout au long du projet.

**Implication des membres :**
* **Ulysse Virlogeux--Chabaille** : Malgré une maladie durant la première semaine, il a principalement pris en charge l’organisation du groupe. Il a notamment mis en place le repository GitHub et le GitHub Project afin de structurer le travail et de faciliter la répartition des tâches. Il a également défini l’objectif et le cadre de l’analyse conceptuelle, permettant ainsi au groupe d’avoir une direction claire pour cette partie du projet, et a organisé le meeting de brainstomring sur l'analyse conceptuel. Mais il n'a pas fourni de travail concret sur la dite-analyse ni aider à la rédaction du Gdoc à cause de sa maladie.
* **Hans Vinçon** : Il a créé et tenu à jour le Google Docs général du groupe. Il y a consigné l’ensemble des informations récoltées et des éléments produits au cours du projet, faisant de ce document le principal support de référence pour le groupe. Les différents membres pouvaient ainsi s’y référer pour retrouver facilement les informations et suivre l’avancement du travail. Hans a également participé à l’analyse conceptuelle.
* **Victor Pottier** : Il a participé à la rédaction et à la mise à jour du Google Docs en apportant les informations qu’il avait recueillies. Il a également travaillé sur l’analyse conceptuelle avec Hans Vinçon et les autres membres du groupe.
* **Zeineb Mokded** : Elle a participé à la rédaction et à la mise à jour du Google Docs en y ajoutant les informations recueillies au cours du travail. Elle a également contribué à l’élaboration de l’analyse conceptuelle avec les autres membres du groupe.

---

## 3. Analyse conceptuelle de Codex Naturalis

L'analyse conceptuelle permet d'identifier les principaux concepts nécessaires pour représenter le fonctionnement de **Codex Naturalis**. Le jeu est principalement organisé autour d'une **Partie**, de plusieurs **Joueurs**, de leurs **Cartes** et de leurs **Objectifs**.

### Partie

La **Partie** représente une partie complète de Codex Naturalis. Elle constitue le point central du modèle et regroupe les joueurs, les objectifs et les cartes utilisées pendant la partie.

```text
PARTIE
 ├── 2 à 4 JOUEURS
 ├── OBJECTIFS
 └── CARTES
```

### Joueur

Le **Joueur** représente un participant à la partie. Il possède les éléments nécessaires pour effectuer ses actions et suivre sa progression : une main de cartes, une aire de jeu, un objectif secret et un score.

```text
JOUEUR
 ├── 1 AIRE DE JEU
 ├── 1 MAIN
 ├── 1 OBJECTIF SECRET
 └── 1 SCORE
```

### Aire de jeu

L'**Aire de jeu** représente le Codex construit progressivement par un joueur. Elle contient les cartes posées par celui-ci et permet notamment de déterminer les ressources et objets actuellement disponibles.

```text
AIRE DE JEU
 └── CARTES POSÉES
```

### Main

La **Main** représente les cartes actuellement disponibles pour le joueur. Elle évolue au cours de la partie en fonction des cartes jouées et piochées.

```text
MAIN
 └── CARTES
```

### Carte

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

### Ressource

Les **Ressources** sont les éléments représentés sur les cartes et nécessaires à certaines actions, notamment au placement de certaines cartes Dorure. Leur disponibilité dépend des cartes visibles dans l'aire de jeu.

```text
RESSOURCE
 ├── VÉGÉTAL
 ├── ANIMAL
 ├── FONGIQUE
 └── INSECTE
```

### Objet

Les **Objets** sont des éléments présents sur certaines cartes. Ils peuvent être pris en compte dans certaines conditions de score.

```text
OBJET
 ├── PLUME
 ├── ENCRIER
 └── MANUSCRIT
```

### Objectif

Un **Objectif** définit une condition permettant au joueur d'obtenir des points supplémentaires. Les objectifs peuvent être communs à l'ensemble des joueurs ou attribués individuellement sous la forme d'un objectif secret.

```text
OBJECTIF
 ├── CONDITION
 └── VALEUR EN POINTS
```

### Score

Le **Score** représente les points accumulés par un joueur au cours de la partie. Il est notamment alimenté par les cartes jouées et les objectifs réalisés.

```text
SCORE
 └── NOMBRE DE POINTS
```

### Vue d'ensemble

Les concepts identifiés peuvent finalement être regroupés de la manière suivante :
*Notons que ce ne sont que des prémisses de liaison. nous ferons un véritable UML la semaine suivante.*
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

---

## 4. Planification et objectifs pour le Compte Rendu 2 (Semaine du 3 novembre)

Pour le second livrable, l'objectif est d'aboutir à un début d'architecture concrète et d'implémentation. Notre stratégie repose sur la mise en place préalable de la persistance des données du jeu (gestion de bases de données / tables relationnelles avec Clés Primaires (PK) et Clés Étrangères (FK)), indispensable avant d'attaquer la logique métier complète.

Afin de garantir l'intégrité référentielle, les bases indépendantes (sans FK) sont conçues et vérifiées avant les bases dépendantes (qui contiennent des FK pointant vers les premières).

### 4.1. Tableau prévisionnel des tâches jusqu'au CR2

| ID | Tâche / Sous-tâche | Priorité | Complexité | Dépendances | Durée estimée | Responsable (Affectation a priori) |
| :--- | :--- | :--- | :--- | :--- | :--- | :--- |
| **T8** | **Brainstorming UML & Schéma relationnel BDD**<br>• Identification des tables, attributs, PK et FK<br>• Établissement des liaisons entité-association | Indispensable | Haute | T4 | 4 h | Tous les membres |
| **T9** | **Phase de maturation & Rédaction propre de l'UML**<br>• Sessions de jeu complémentaires pour réfléchir et se laisser le temps de valider notre UML<br>• Ajustement et validation collégiale du modèle conceptuel si personne n'a rien à ajouter + Création du fichier UML | Moyenne | Basse | T8 | 2 d | Tous les membres + Ulysse Virlogeux--Chabaille (pour redaction) |
| **T10** | **Création BDD Joueurs**<br>• Schéma de la table Joueur (PK `id_joueur`, pseudo, couleur de pion, etc.) | Indispensable | Moyenne | T9 | 2 h | Hans Vinçon |
| **T11** | **Review BDD Joueurs**<br>• Tests d'insertion, mise à jour et suppression de profils (directement en terminal) pour valider le travail | Indispensable | Basse | T10 | 1 h | Victor Pottier |
| **T12** | **Création BDD Cartes (Référentiel)**<br>• Schéma (PK `id_carte`, type, coins recto/verso, ressources fournies, coût de pose, points) | Indispensable | Haute | T9 | 4 h | Victor Pottier |
| **T13** | **Review BDD Cartes**<br>• Insertion d'un échantillon représentatif de cartes de chaque règne pour valider (directement en terminal) | Indispensable | Basse | T12 | 2 h | Zeineb Mokded |
| **T14** | **Création BDD Objectifs (Référentiel)**<br>• Schéma (PK `id_objectif`, type de condition [motif/collection], points accordés) | Indispensable | Haute | T9 | 3 h | Zeineb Mokded |
| **T15** | **Review BDD Objectifs**<br>• Tests d'insertion et validation des types de critères d'objectifs (directement en terminal) | Indispensable | Basse | T14 | 1 h 30 | Hans Vinçon |
| **T16** | **Création BDD État de Partie & Manuscrit**<br>• Schéma dépendant (PK `id_action`, FK `id_partie`, FK `id_joueur`, FK `id_carte`, position `(x, y, z)`, face visible) | Indispensable | Haute | T10, T12, T14 | 5 h | Ulysse Virlogeux--Chabaille |
| **T17** | **Review BDD État de Partie & Manuscrit**<br>• Vérification des contraintes d'intégrité référentielle (rejet si FK invalide) et tests d'ajouts  | Indispensable | Basse | T16 | 2 h | Hans Vinçon |
| **T18** | **Développement des fonctions de contrôle BDD (Gestion globale)**<br>• Implémentation en C++ de fonction d'accès aux données (méthodes d'ajout, suppression, consultation programmatique sans passer par le terminal) | Indispensable | Haute | T11, T13, T15, T17 | 8 h ? | Victor Pottier, Ulysse Virlogeux--Chabaille |
| **T19** | **Review et tests des fonctions de contrôle BDD**<br>• Validation du bon fonctionnement des méthodes C++ sur l'ensemble des BDD créées | Importante | Moyenne | T18 | 1 h | Zeineb Mokded, Hans Vinçon |
| **T20** | **Rédaction et mise en forme du Compte Rendu 2**<br>• Création du rapport: diagrammes UML de classes et schéma BDD | Indispensable | Moyenne | T18, T19 | 4 h | Responsable CR2 (rotation) |
| **T21** | **Réunion final**<br>• Relecture collective, mise à jour du GitHub Project + repas récompense pour le travail bien accompli en groupe + lecture de tout les membres du CR2| Basse | Basse | T20 | 1 h 30 | Tous les membres |

### 4.2. Synthèse de la logique d'ordonnancement
* **Gestion des dépendances PK / FK :** Les tables de référence (`Joueur`, `Carte`, `Objectif`) sont modélisées et testées de avant d'aborder la table de l'état du jeu (`Manuscrit/Partie`), évitant ainsi tout blocage lors de la définition des contraintes relationnelles.
* **Assurance qualité par "Review croisée" :** Chaque base créée par un membre est systématiquement revue et testée par un autre membre du groupe (insertion/suppression de données).
* **Interface logicielle :** La tâche T18 permet d'encapsuler ces accès aux bases au sein du code de l'application, fournissant une API claire pour le futur moteur de jeu.
