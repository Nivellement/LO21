//
// Created by hans on 17/11/2026.
//

#ifndef CODEX_NATURALIS_PLATEAU_H
#define CODEX_NATURALIS_PLATEAU_H
#include "carte/Carte.h"


class Plateau {
     Codex::Coin matrice[100][100];

    public :
    explicit Plateau(const Codex::CarteDepart& cd, Face f);
    std::vector<Position> positionAjoutPossible(const Codex::CartePlacement& cd, Face f);
    void ajouterCarte(const Codex::CartePlacement& c, Face f, const int& i, const int& j);
};


#endif //CODEX_NATURALIS_PLATEAU_H
