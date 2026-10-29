#if !defined(OBJET_H)
#define OBJET_H

#include <iostream>
#include <string>

/*
 * Objet («Stereotype» dans l'UML) : un objet du jeu, identifié par son nom
 * (ex. "Plume", "Encrier", "Parchemin").
 *
 * Deux objets sont égaux s'ils ont le même nom.
 */

namespace Codex {

    class Objet {
    private:
        std::string nom;

    public:
        explicit Objet(const std::string& n);

        // Accesseur **en lecture uniquement**
        const std::string& getNom() const;

        // Pour comparer, regarder le nom
        bool operator==(const Objet& o) const;
        bool operator!=(const Objet& o) const;
    };

    std::ostream& operator<<(std::ostream& f, const Objet& o);

}

#endif
