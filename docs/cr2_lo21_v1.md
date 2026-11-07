
**!!!TODO : inclure screens Github, discord, UML, etc, tout ce puisse paraître pertinent. Ce CR est uniquement une première version, sa vocation est d'être modifié.!!!!**

# Compte Rendu 1 - Projet Codex Naturalis

**Date de rendu :** Semaine du 3 novembre  
**Auteur responsable du livrable :** Victor Pottier
**Membres du groupe :**
1. Ulysse Virlogeux--Chabaille
2. Hans Vinçon
3. Victor Pottier
4. Zeineb Mokded

---

## 1. Tâches réalisées au cours de cette 2e phase

L'objectif principal est de définir une architecture théorique suffisamment complète pour permettre, durant la phase 3, d'implémenter un premier prototype de Codex Naturalis jouable sur terminal.

| ID | Tâche Macro | Complexité estimée | Durée estimée | Responsable (Affectation a priori) | Date de réalisation
| :--- | :--- | :--- | :--- | :--- | :--- |
| T1 | Définition plus approfondie de l'UML décrivant l'architecture du projet | Élevée | 4h | Hans Vinçon - Zeineb Mokded | 19/10/2026
| T1bis | Réunion et discussions autour de l'UML afin de le valider | Faible | 1h30 | Tous les membres | 26/10/2026
| T2 | Mise en place d'un environnement Github et Discord pour l'organisation du travail | Moyenne | 2h | Ulysse Virlogeux--Chabaille | 26/10/2026
| T3 | Programmation d'un premier modèle pour la classe abstraite Carte et de ses dépendances | Moyenne | 4h30 | Ulysse Virlogeux--Chabaille - Hans Vinçon| 30/10/2026
| T4 | Création d'un premier modèle de classe pour CarteObjectif et ConditionScore | Moyenne | 2h | Zeineb Mokded | 31/10/2026
| T5 | Rédaction du deuxième compte-rendu | Élevée | 3h | Victor Pottier | 06/11/2026
| T6 | Rectifications et validation du deuxième compte-rendu | Moyenne | 1h / membre | Tous les membres | 07/11/2026

---

## 2. Bilan sur la cohésion de groupe et l'implication

**État de la cohésion :**  
Pour des questions d'organisation, le groupe a mis en place un serveur discord, afin de retrouver au mieux l'information relative aux tâches à effectuer (système d'annonce par ticket), à l'information à inclure dans le compte-renudu, etc....;

L'affectation des tâches s'est réalisée à travers Github comme prévu dans le premier compte-rendu.

Les mouvements sociaux et le report des examens médians ont généré une pression supplémentaire qui nous a contraint à réajuster l'organisation du groupe.

L'architecture du projet étant établie, un travail de programmation considérable reste à faire jusqu'au prochain compte-rendu.

**Implication des membres :**

**!!!!ICI remplissez vous-même la partie qui vous concerne, j'ai écrit vite fait quelques idées rapides mais vous être libres et responsables de modifier et ré-écrire proprement tout ce qui vous concerne!!!!!**
* **Ulysse Virlogeux--Chabaille** : Annonce des tâches à réaliser à travers Discord et organisation du projet. Une meilleur présence est à noter suite à la fin de la maladie.
* **Hans Vinçon** : Développement de l'UML et bonne implication dans le projet pendant les vacances. 
* **Victor Pottier** : Rédaction du compte-rendu. Ne disposant pas de Visual Studio ni de CodeBlocks sur son ordinateur personnel, des installations seront à prévoir rapidement en anticipation du fort travail de programmation qui devra être réalisé. Peu de travail de conception fourni pendant les vacances mais un plus grand effort sera fourni pendant la 3e phase du projet.
* **Zeineb Mokded** : Travail sur l'UML et les déclaration de classes. Un travail à distanciel est à noter.

Bilan : très bonne entente du groupe, la prise de décision peut toutefois être ralentie du fait des occasionnelles difficultés à se mettre d'accord. Une solide base organisationnelle a été posée, ce qui facilitera la programmation plus poussée du projet.

---

## 3. Etat d'avancement par rapport au Compte Rendu 1


Le point le plus important concerne la définition plus poussée de l'architecture théorique du projet.

En effet, l'UML associé à cette architecture a été et davantage détaillé lors de cette 2e phase du projet. Notamment, les associations et les héritages entre les classes du projet ont été proprement explicités.

Nous avons ensuite débuté la programmation du projet, en implémentant concrètement l'architecture théorique  en définissant le "squelette" des classes décrites dans l'UML.



---

## 4. Planification et objectifs pour le Compte Rendu 3 (Semaine du 30 novembre)

Pour le troisième livrable, l'objectif serait de pouvoir conclure une première version jouable sur terminal du projet. Nous nous concentrerons donc sur la programmation des fonctionnalités essentielles au bon déroulement d'une partie de Codex Naturalis.

Une architecture détaillée ayant été dévéloppée au cours de la phase 2, la programmation des classes et de leurs fonctionnalités au cours de la prochaine phase sera nettement facilitée.

### 4.1. Tableau prévisionnel des tâches jusqu'au CR2



**A NOTER : les affectations sont pour l'instant arbitraires, chacun peut modifier ses tâches selon sa volonté. En particulier, certaines tâches affectées à "Tous les membres" peuvent avoir un responsable désigné.**
| ID | Tâche / Sous-tâche | Priorité | Complexité | Dépendances | Durée estimée | Responsable (Affectation a priori) |
| **T1** | **Programmation du squelette de toutes les classes restantes (fichiers .h)**<br>•Besoin de définir classes Position, CartePlacee, CarteDorure, PiocheDorure, etc. | Indispensable | Moyenne | Aucune | 2h | Tous les membres |
| **T2** | **Fonctionnalités de la classe Plateau***<br>• La méthode peutAjouter vérifiant la permission de placement d'une carte nécessite une attention particulière, l'affichage avec print() est également à considérer | Indispensable | Haute | T1 | 5~6h | Victor Pottier |
| **T3** | **Fonctionnalités de la classe Joueur**<br>• Fonctionnalité de calcul du score particulièrement complexe | Indispensable | Haute | T2 | 5~6h | Ulysse Virlogeux--Chabaille |
| **T4** | **Instanciation de toutes les cartes du jeu**<br>• Toutes les cartes du jeu original doivent être instanciées, ce sera un procédé répétitif mais nécessaire pour la définition du constructeur Jeu(). A noter que ces cartes seront sûrement stockées dans une base de données par la suite. | Moyenne | Basse | T1 | 1~2h | Victor Pottier |
| **T5** | **Fonctionnalités de la classe Jeu***<br>• Une attention particulière sera portée sur la définition du constructeur Jeu(). | Indispensable | Moyenne | T4 | 2~3h | Tous les membres |
| **T6** | **Fonctionnalités des différentes pioches***<br>• Accès aux cartes instanciées dans Jeu via passage par paramètre, prise en compte de la dimension aléatoire pour la méthode piocher() | Haute | Moyenne | T5 | 1h | Zeineb Mokded |
| **T7** | **Fonctionnalités de la classe Manager**<br>• La méthode jouerTour() nécessitera une attention particulière | Haute | Haute | T6, T3 | 5~6h | Hans Vinçon |
| **T8** | **Tests des différentes fonctionnalités**<br>• Validation du bon fonctionnement des méthodes C++ implémentées, une réunion sera organisée à l'issue de ces tests | Moyenne | Moyenne | T7 | 1h / membre | Tous les membres |
| **T9** | **Implémentation du mode de Jeu contre l'ordinateur Tybor**<br>• Commencer l'implémentation des stratégies de Tybor et de la sous-classes ManagerSolo | Moyenne | Haute | T7 | 6~7h | Zeineb Mokded + autres membres |
| **T10** | **Rédaction et mise en forme du Compte Rendu 3**<br>• Création du rapport: détails sur les différents modules du projet et sur les interactions que ces modules ont avec le reste de l'application | Indispensable | Moyenne | ? | 4~5h | Zeineb Mokded ou Hans Vinçon |
| **T11** | **Réunion finale et validation CR3**<br>• Relecture collective, mise à jour du GitHub Project, lecture et validation par tous les membres du CR3| Basse | Basse | T10 | 1 h 30 | Tous les membres |