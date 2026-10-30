#include "Carte.h"

using namespace Codex;


//***Carte***///

std::ostream& operator<<(std::ostream& f, const Carte& c) {
    f <<"Id = " << c.getId() << endl;
    return f;
}

//***Carte***///

//***CartePlacement***///
CartePlacement::CartePlacement(int i, const string& c, const Coin& vhg, const Coin& vhd, const Coin& vbg, const Coin& vbd
        , const Coin& rhg, const Coin& rhd, const Coin& rbg, const Coin& rbd, const Coin& vm, const Coin& rm) :
        Carte(i), couleur(c), verso{vhg, vhd, vbg, vbd}, recto{rhg, rhd, rbg, rbd}, milieuVerso(vm), milieuRecto(rm) {}


ostream& operator<<(ostream& f, const CartePlacement& cp){
    f <<"Id = " << cp.getId() << endl;
    f <<"Verso : " << endl;
    f <<cp.getCoinVerso(1)<<"\t"<<cp.getCoinVerso(2)<<endl;
    f <<"\t"<<cp.getMilieuVerso()<<"----------"<<endl;
    f <<cp.getCoinVerso(3)<<"\t"<<cp.getCoinVerso(4)<<endl;
    f <<"Recto : " << endl;
    f <<cp.getCoinRecto(1)<<"\t"<<cp.getCoinVerso(2)<<endl;
    f <<"\t"<<cp.getMilieuRecto()<<"\t"<<endl;
    f <<cp.getCoinVerso(3)<<"\t"<<cp.getCoinVerso(4)<<endl;

    return f;
}


//***CartePlacement***///
