#include "Carte.h"
namespace Codex {
    Carte::~Carte() = default;
}
using namespace Codex;


//***Carte***///

std::ostream& operator<<(std::ostream& f, const Carte& c) {
    f <<"Id = " << c.getId() << endl;
    return f;
}

//***Carte***///

//***CartePlacement***///
CartePlacement::CartePlacement(const int i, const string& c, Coin& vhg, Coin& vhd, Coin& vbg, Coin& vbd
        , Coin& rhg, Coin& rhd, Coin& rbg, Coin& rbd, Coin& vm, Coin& rm) :
        Carte(i), couleur(c), verso{vhg, vhd, vbg, vbd}, recto{rhg, rhd, rbg, rbd}, milieuVerso(vm), milieuRecto(rm) {
    vhg.setPosition(Position::HG); vhd.setPosition(Position::HD); vbg.setPosition(Position::BG); vbd.setPosition(Position::BD);
    rhg.setPosition(Position::HG); rhd.setPosition(Position::HD); rbg.setPosition(Position::BG); rbd.setPosition(Position::BD);
    vm.setPosition(Position::M); rm.setPosition(Position::M);
}        //L'attribut position des coins est instancie dans le constructeur de CartePlacement => CartePlace plus tres utile !?



ostream& operator<<(ostream& f, const CartePlacement& cp){
    f <<"Id = " << cp.getId() << endl;
    f <<"Verso : " << endl;
    f <<cp.getCoin(Position::HG, Face::Verso)<<"\t"<<cp.getCoin(Position::HD, Face::Verso)<<endl;
    f <<"\t"<<cp.getCoin(Position::M, Face::Verso)<<"----------"<<endl;
    f <<cp.getCoin(Position::BG, Face::Verso)<<"\t"<<cp.getCoin(Position::BG, Face::Verso)<<endl;
    f <<"Recto : " << endl;
    f <<cp.getCoin(Position::HG, Face::Recto)<<"\t"<<cp.getCoin(Position::HD, Face::Recto)<<endl;
    f <<"\t"<<cp.getCoin(Position::M, Face::Recto)<<"----------"<<endl;
    f <<cp.getCoin(Position::BG, Face::Recto)<<"\t"<<cp.getCoin(Position::BG, Face::Recto)<<endl;

    return f;
}

const Coin& CartePlacement::getCoin(Position p, Face f) const {
    if (p == Position::NaN) {
        throw CarteException("On ne pas acceder a une position NaN d'une carte.\nNaN est utilise uniquement a l'instanciation de l'attribut position d'un coin \n");
    }

    if (f == Face::Verso) {
        if (p == Position::HG) {
            return verso[0];
        }
        else if (p == Position::HD) {
            return verso[1];
        }
        else if (p == Position::BG) {
            return verso[2];
        }
        else if (p == Position::BD) {
            return verso[3];
        }
        else if (p == Position::M) {
            return milieuVerso;
        }
    }
    else {
        if (p == Position::HG) {
            return recto[0];
        }
        else if (p == Position::HD) {
            return recto[1];
        }
        else if (p == Position::BG) {
            return recto[2];
        }
        else if (p == Position::BD) {
            return recto[3];
        }
        else if (p == Position::M) {
            return milieuRecto;
        }

    }
    throw CarteException("PROBLEME DE CODE DE LA METHODE"); //SIMPLE ERROR DE VERIF DE CODE
}

//***CartePlacement***///
