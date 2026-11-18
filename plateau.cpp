//
// Created by hans on 17/11/2026.
//

#include "plateau.h"

#include "player.h"


Plateau::Plateau(const Codex::CarteDepart& cd, const Face f) {
    if (f == Face::Verso) {
        matrice[50][50] = cd.getCoin(Position::M, Face::Verso);
        matrice[51][49] = cd.getCoin(Position::HG, Face::Verso);
        matrice[51][51] = cd.getCoin(Position::HD, Face::Verso);
        matrice[49][49] = cd.getCoin(Position::BG, Face::Verso);
        matrice[49][51] = cd.getCoin(Position::BD, Face::Verso);
    }
    else {
        matrice[50][50] = cd.getCoin(Position::M, Face::Recto);
        matrice[51][49] = cd.getCoin(Position::HG, Face::Recto);
        matrice[51][51] = cd.getCoin(Position::HD, Face::Recto);
        matrice[49][49] = cd.getCoin(Position::BG, Face::Recto);
        matrice[49][51] = cd.getCoin(Position::BD, Face::Recto);
    }
}

std::vector<Position> Plateau::positionAjoutPossible(const Codex::CarteDepart& cd, Face f) {
    vector<Position> positions;

}

