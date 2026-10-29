#if !defined(RESSOURCE_H)
#define RESSOURCE_H

#include <iostream>
#include <string>

/*
 * Ressource («Stereotype» dans l'UML) : une ressource du jeu, identifiée par son
 * nom (ex. "Animal", "Vegetal", "Champignon", "Insecte").
 *
 * Deux ressources sont égales si elles ont le même nom : c'est ce qui permet de
 * compter les ressources d'un joueur ou de vérifier un coût (ex. 3 champignons).
 */

namespace Codex {

    class Ressource {
    private:
        std::string nom;

    public:
        explicit Ressource(const std::string& n);

        // Accesseur **en lecture uniquement**
        const std::string& getNom() const;

        // Comparer avec le nom
        bool operator==(const Ressource& r) const;
        bool operator!=(const Ressource& r) const;
    };

    std::ostream& operator<<(std::ostream& f, const Ressource& r);

}

#endif
