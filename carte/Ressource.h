#if !defined(RESSOURCE_H)
#define RESSOURCE_H

/*
 * Ressource («Stereotype» dans l'UML) : une ressource du jeu, identifiée par son
 * nom (ex. "Animal", "Vegetal", "Champignon", "Insecte").
 *
 * Deux ressources sont égales si elles ont le même nom : c'est ce qui permet de
 * compter les ressources d'un joueur ou de vérifier un coût (ex. 3 champignons).
*/

/*
 *Nouvelles suggestions => considerer Ressource comme un Enum car beaucoup plus simple
*/

enum class RessourceType {Ch, Pap, Loup, Plume, Parch, Potion, Feuille,Vide, NaN};
//NaN permet d'avoir une valeur par defaut pour les class utilisant cet enum
//Vide est different de NaN !!! NaN <=> NULL et Vide correspond a un coin vide comme on peut en rencontrer dans le jeu
/*
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
*/

#endif
