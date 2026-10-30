#if !defined(CARTE_H)
#define CARTE_H

#include <iostream>

/*
 * Carte : classe abstraite, racine de la hiérarchie du diagramme UML.
 * (Les sous-classes - CarteDePlacement, CarteObjectif... - ne sont pas encore écrites.)
 *
 * Carte ne contient que ce qui est commun à toutes les cartes : l'identifiant.
 * Tout ce qui est propre à un type de carte (coins, points, conditions...)
 * sera dans les sous-classes.
 *
 * Recto / verso : le côté posé n'est pas dans la carte, il est mémorisé par
 * CartePlacee (attribut recto) au moment où le joueur pose la carte.
 *
 * Les cartes sont créées et détruites par Jeu ; les autres classes (Pioche,
 * Joueur, Plateau...) n'utilisent que des pointeurs const vers ces cartes.
 * Chaque carte est unique : on interdit donc de la dupliquer.
 */

namespace Codex {

    class Carte {
    private:
        int id;   // identifiant de la carte (unique dans le jeu)

    public:
        explicit Carte(int i);//Pour éviter des conversions automatique qui n'arrange pas

        virtual ~Carte();// Destructeur virtuel

        // Interdiction de duplication (construction par recopie et affectation)
        Carte(const Carte&) = delete;
        Carte& operator=(const Carte&) = delete;

        // Accesseur en lecture
        int getId() const;

        // Méthode virtuelle : chaque type de carte sait s'afficher
        virtual void afficher(std::ostream& f) const = 0;

        // Deux cartes sont égales si elles ont le même identifiant, tenez en compte dans la défintion de ces méthodes
        bool operator==(const Carte& c) const;
        bool operator!=(const Carte& c) const;
    };

    // Affichage d'une carte de n'importe quel type sur un flux (appelle afficher)
    std::ostream& operator<<(std::ostream& f, const Carte& c);

}

#endif
