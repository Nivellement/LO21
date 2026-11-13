#include "pioche.h"

const Codex::Carte& Pioche::piocher() {
    if(estVide()){
        throw PiocheException("La pioche est vide, on ne peut plus piocher de cartes !!! \n");
    }
    Codex::Carte* c = cartes.back();
    cartes.pop_back();  

    return *c;
}



