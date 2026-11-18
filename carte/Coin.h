#if !defined(COIN_H)
#define COIN_H

#include <iostream>
#include "Ressource.h"
#include "Objet.h"

/*
 * Coin : un coin d'une carte.
 *
 * Un coin peut être vide ; sinon il contient UNE ressource ou UN objet
 * (jamais les deux).
 *
 * Le coin ne possède ni la ressource ni l'objet : il garde seulement leur
 * adresse. Les objets Ressource / Objet passés au constructeur doivent donc
 * exister plus longtemps que le coin (pas de temporaire).
 */
enum class Position {NaN, HG, HD, M, BG, BD};//Pour donner la position d'un coin sur une carte
//ATTENTION : l'attribut position de coin est instancie a la creation de la carte
//+ Utiliser en parametre a la palce de int position pour renvoyer un coin precis de la partie verso ou recto d'une carte


namespace Codex {

    class Coin {
    private:
        const Ressource* ressource;   // nullptr si le coin ne contient pas de ressource
        const Objet* objet;           // nullptr si le coin ne contient pas d'objet
        Position position;            // position ne sera instancie que lorsque est asscoie a une carte (et donc a un coin)
    public:
        // Coin vide
        explicit Coin() : ressource(nullptr), objet(nullptr), position(Position::NaN) {}

        // Coin un constructeur pour chaque possibilité de coin faisable. Le bon sera appeler automatiquement.
        explicit Coin(const Ressource& r) : ressource(&r), objet(nullptr), position(Position::NaN) {}
        explicit Coin(const Objet& o) : ressource(nullptr), objet(&o), position(Position::NaN) {}

        // Truc qui sera sûrement utile
        bool estVide() const;
        bool aRessource() const;
        bool aObjet() const;

        // Accesseurs **en lecture uniquement**: renvoient nullptr si le coin ne contient pas ce type d'élément
        const Ressource* getRessource() const {return ressource;}
        const Objet* getObjet() const {return objet;};
        Position getPosition() const {return position;}
        void setPosition(const Position& p) {position = p;}
    };

    std::ostream& operator<<(std::ostream& f, const Coin& c);

}

#endif
