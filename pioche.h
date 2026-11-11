#ifndef PIOCHE_H_INCLUDED
#define PIOCHE_H_INCLUDED
#include "Carte.h"
#include "CarteObjectif.h"
using namespace std;

/*
 * RAPPEL : méthodes virtual
 *
 * - Sans virtual : la méthode appelée dépend du TYPE DU POINTEUR (Carte*).
 * - Avec virtual : elle dépend du TYPE RÉEL DE L'OBJET (CarteRessource, etc.).
 *   Ça ne marche que via un pointeur ou une référence.
 *
 * Quand mettre virtual ?
 *   - Comportement différent selon la classe fille (ex : afficher)  -> virtual
 *   - Chaque fille DOIT le fournir                                  -> virtual ... = 0
 *     (la classe devient abstraite, impossible à instancier)
 *   - Code identique pour toutes les filles (ex : getters)          -> méthode normale
 *   - Destructeur d'une classe de base                              -> TOUJOURS virtual
 *
 * Bonnes pratiques :
 *   - Mettre override dans les classes filles (le compilateur vérifie la signature).
 *   - La signature (paramètres et const) doit être identique à celle de la mère.
 *   - Un constructeur ou un attribut ne peut pas être virtual.
 *   - Ne pas appeler de méthode virtual dans un constructeur/destructeur.
 */

 /*
 * override demande au compilateur de vérifier que la méthode redéfinit bien une méthode virtual de la classe mère. 
 * Si ce n’est pas le cas, il refuse de compiler.
 */

class PiocheException{
    string info;

    public : 
        PiocheException(const string& i) : info(i) {}
        const string& getInfo() const {return info;}
};

class Pioche {
protected:
    vector<Codex::Carte*> cartes;

    //Constructeur dans protected pour ne pas permettre d'etre instancie par n'importe qui
    explicit Pioche(const vector<Codex::Carte*>& c) : cartes(c) {} //J'utilise vector car il  nous permet de convertir CarteFille vers Carte
    //mais puisque ce sont des pointeurs on garde bien les informations propres a la classe fille
public:
    

    virtual ~Pioche() = default;
    bool estVide() const { return cartes.empty(); } //non virtual car identique pour chaque class fille
    const Codex::Carte& piocher();
};

class PiocheRessource : public Pioche {
public:
    PiocheRessource(Codex::CarteRessource** c, size_t nb)
        : Pioche(vector<Codex::Carte*>(c, c + nb)) {}
    
    ~PiocheRessource() = default;

};

class PiocheDepart : public Pioche {

public:
    PiocheDepart(Codex::CarteDepart** c, size_t nb)
        : Pioche(vector<Codex::Carte*>(c, c + nb)) {}

    ~PiocheDepart() = default;

};

class PiocheObjectif : public Pioche {

public:
    PiocheObjectif(CarteObjectif** c, size_t nb)
        : Pioche(vector<Codex::Carte*>(c, c + nb)) {}

    ~PiocheObjectif() = default;

};
#endif // PIOCHE_H_INCLUDED