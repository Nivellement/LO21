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

namespace Codex {

    class Coin {
    private:
        const Ressource* ressource;   // nullptr si le coin ne contient pas de ressource
        const Objet* objet;           // nullptr si le coin ne contient pas d'objet

    public:
        // Coin vide
        Coin();

        // Coin un constructeur pour chaque possibilité de coin faisable. Le bon sera appeler automatiquement.
        explicit Coin(const Ressource& r);
        explicit Coin(const Objet& o);

        // Truc qui sera sûrement utile
        bool estVide() const;
        bool aRessource() const;
        bool aObjet() const;

        // Accesseurs **en lecture uniquement**: renvoient nullptr si le coin ne contient pas ce type d'élément
        const Ressource* getRessource() const;
        const Objet* getObjet() const;
    };

    std::ostream& operator<<(std::ostream& f, const Coin& c);

}

#endif
