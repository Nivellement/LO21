#if !defined(CARTE_H)
#define CARTE_H

#include <vector>
#include <string>
#include <iostream>
#include "Coin.h"

using namespace std;

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
    protected:
        int id;   // identifiant de la carte (unique dans le jeu)

    public:
        explicit Carte(int i) : id(i) {};//Pour éviter des conversions automatique qui n'arrange pas

        virtual ~Carte();// Destructeur virtuel

        // Interdiction de duplication (construction par recopie et affectation)
        Carte(const Carte&) = delete;
        Carte& operator=(const Carte&) = delete;

        // Accesseur en lecture
        int getId() const { return id;}

        // Méthode virtuelle : chaque type de carte sait s'afficher
        virtual void afficher(std::ostream& f) const = 0;

        // Deux cartes sont égales si elles ont le même identifiant, tenez en compte dans la défintion de ces méthodes
        bool operator==(const Carte& c) const { return id==c.getId(); }
        bool operator!=(const Carte& c) const { return id!= c.getId(); }
    };

    // Affichage d'une carte de n'importe quel type sur un flux (appelle afficher)
    ostream& operator<<(ostream& f, const Carte& c);

    /*
    On cree deux vecteur qui vont contenir les 4 coins de chaque face (recto et verso)
    On devrait utiliser array au lieu de vector car array nous permet de preciser une taille (=> array<Coin, 4>)
    A reflechir si on attribuit pas une position a chaque coin ou on se met d'accord sur l'ordre.
    Pour le moment je me base sur l'ordre suivant :
    - vector[1] = coin haut gauche,  vector[2] = coin haut droit
    - vector[3] = coin bas gauche, vector[3] = coin bas droit
    Je vais pour le moment considerer les milieux comme des coins car la classe Coin repond parfaitement aux demandes (peut etre une ressource ou un objet)

    */

    class CartePlacement : public Carte {
    protected :
        string couleur;
        vector<Coin> verso;
        vector<Coin> recto;
        Coin milieuVerso;
        Coin milieuRecto;

    public :
        CartePlacement(int i, const string& c, const Coin& vhg, const Coin& vhd, const Coin& vbg, const Coin& vbd
        , const Coin& rhg, const Coin& rhd, const Coin& rbg, const Coin& rbd, const Coin& vm, const Coin& rm); // v = verso, r = recto, h = haut, g = gauche, d = droit

        const string& getCouleur() const {return couleur;}
        const Coin& getCoinVerso(int position) const { return verso[position];}
        const Coin& getCoinRecto(int position) const { return recto[position];}
        const Coin& getMilieuVerso() const { return milieuVerso;}
        const Coin& getMilieuRecto() const { return milieuRecto;}

    };

ostream& operator<<(ostream& f, const CartePlacement& cp);

    //CarteDepart prend exactement les meme attributs qu'une carte de placement aucune difference
    class CarteDepart : public CartePlacement {

    public :
        CarteDepart(int i, const string& c, const Coin& vhg, const Coin& vhd, const Coin& vbg, const Coin& vbd
        , const Coin& rhg, const Coin& rhd, const Coin& rbg, const Coin& rbd, const Coin& vm, const Coin& rm) : CartePlacement(i, c, vhg, vhd, vbg, vbd, rhg, rhd, rbg, rbd, vm, rm){}

    };

    class CarteRessource : public CartePlacement {

    public :
        CarteRessource(int i, const string& c, const Coin& vhg, const Coin& vhd, const Coin& vbg, const Coin& vbd
        , const Coin& rhg, const Coin& rhd, const Coin& rbg, const Coin& rbd, const Coin& vm, const Coin& rm) : CartePlacement(i, c, vhg, vhd, vbg, vbd, rhg, rhd, rbg, rbd, vm, rm){}

    };

    class CarteObjectif : public CartePlacement {
        string conditionScore; //Pour le moment je met un string mais il faudra creer une class ConditionScore
        string typeObjectif;
        unsigned int point;
        public :
            CarteObjectif(int i, const string& c, const Coin& vhg, const Coin& vhd, const Coin& vbg, const Coin& vbd
        , const Coin& rhg, const Coin& rhd, const Coin& rbg, const Coin& rbd, const Coin& vm, const Coin& rm, const string& CS, const string& TY, const unsigned int p) : CartePlacement(i, c, vhg, vhd, vbg, vbd, rhg, rhd, rbg, rbd, vm, rm),
        conditionScore(CS), typeObjectif(TY), point(p) {}

    };

}

#endif
