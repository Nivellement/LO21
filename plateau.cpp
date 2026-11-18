//
// Created by hans on 17/11/2026.
//

#include "plateau.h"


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

bool Plateau::verifInsereHG(const Codex::CartePlacement& cAjouter, const Face& f, const size_t& i, const size_t& j) const{
    if ((matrice[i-2][j]).getRessource() == RessourceType::Vide &&
        (matrice[i-2][j-2]).getRessource() == RessourceType::Vide &&
        (matrice[i][j-2]).getRessource() == RessourceType::Vide &&
        cAjouter.getCoin(Position::BD, f).getRessource() != RessourceType::NaN) {
        return true;
    }
    return false;
}

bool Plateau::verifInsereHD(const Codex::CartePlacement& cAjouter, const Face& f, const size_t& i, const size_t& j) const{
    if ((matrice[i-2][j]).getRessource() == RessourceType::Vide &&
        (matrice[i-2][j+2]).getRessource() == RessourceType::Vide &&
        (matrice[i][j+2]).getRessource() == RessourceType::Vide &&
        cAjouter.getCoin(Position::BG, f).getRessource() != RessourceType::NaN) {
        return true;
        }
    return false;
}

bool Plateau::verifInsereBG(const Codex::CartePlacement& cAjouter, const Face& f, const size_t& i, const size_t& j) const{
    if ((matrice[i+2][j]).getRessource() == RessourceType::Vide &&
        (matrice[i+2][j-2]).getRessource() == RessourceType::Vide &&
        (matrice[i][j-2]).getRessource() == RessourceType::Vide &&
        cAjouter.getCoin(Position::HD, f).getRessource() != RessourceType::NaN) {
        return true;
        }
    return false;
}

bool Plateau::verifInsereBD(const Codex::CartePlacement& cAjouter, const Face& f, const size_t& i, const size_t& j) const{
    if ((matrice[i+2][j]).getRessource() == RessourceType::Vide &&
        (matrice[i+2][j+2]).getRessource() == RessourceType::Vide &&
        (matrice[i][j+2]).getRessource() == RessourceType::Vide &&
        cAjouter.getCoin(Position::HG, f).getRessource() != RessourceType::NaN) {
        return true;
        }
    return false;
}
bool Plateau::peutAjouterCarte(const Codex::CartePlacement& cd, Face f, const size_t& i, const size_t& j) const{
    if (i > 100 || j > 100) {
        throw Codex::CarteException("Index incorrect pour ajouter une carte dans un plateau\n");
    }

    Codex::Coin c = matrice[i][j];
    Position p = c.getPosition();
    const RessourceType r = c.getRessource();
    if (r == RessourceType::Vide) {
        if (p == Position::HG) {
            return verifInsereHG(cd, f, i, j);
        }
        else if (p == Position::HD) {
            return verifInsereHD(cd, f, i, j);
        }
        else if (p == Position::BG) {
            return verifInsereBG(cd, f, i, j);
        }
        else if (p == Position::BD) {
            return verifInsereBD(cd, f, i, j);
        }
    }

    return false;
}

/*
 *REMARQUE METHODE insererHG/HD/BG/BD() :
 * - Est ce qu'il serait bien de faire en sorte que cette methode ne soit appelable uniquement depuis ajouterCarte ?
 * Cela eviterait qu'on se trompe a l'utiliser en dehors du cadre prevu + si prof fait des verifs ca pourrait etre une faille potentielle
*/
void Plateau::insererHG(const Codex::CartePlacement& c, Face f, const size_t& i, const size_t& j) {
    matrice[i][j] = c.getCoin(Position::BD, f); //En effet on va bien mettre la coin BD de la nouvelle carte
    //a l'emplacement HG de la carte sur laquelle on pose la nouvelle

    matrice[i][j-2] = c.getCoin(Position::BG, f);
    matrice[i-2][j] = c.getCoin(Position::HD, f);
    matrice[i-2][j-2] = c.getCoin(Position::HG, f);
}

void Plateau::insererHD(const Codex::CartePlacement& c, Face f, const size_t& i, const size_t& j) {
    matrice[i][j] = c.getCoin(Position::BG, f);
    matrice[i][j+2] = c.getCoin(Position::BD, f);
    matrice[i-2][j+2] = c.getCoin(Position::HD, f);
    matrice[i-2][j] = c.getCoin(Position::HG, f);
}

void Plateau::insererBG(const Codex::CartePlacement& c, Face f, const size_t& i, const size_t& j) {
    matrice[i][j] = c.getCoin(Position::HD, f);
    matrice[i][j-2] = c.getCoin(Position::HG, f);
    matrice[i+2][j] = c.getCoin(Position::BD, f);
    matrice[i+2][j-2] = c.getCoin(Position::BG, f);
}

void Plateau::insererBD(const Codex::CartePlacement& c, Face f, const size_t& i, const size_t& j) {
    matrice[i][j] = c.getCoin(Position::HG, f);
    matrice[i][j+2] = c.getCoin(Position::HD, f);
    matrice[i+2][j] = c.getCoin(Position::BG, f);
    matrice[i+2][j+2] = c.getCoin(Position::BD, f);
}


void Plateau::ajouterCarte(const Codex::CartePlacement& c, Face f, const size_t& i, const size_t& j) {
    Codex::Coin coin = matrice[i][j];
    Position p = coin.getPosition();
    if (peutAjouterCarte(c, f, i, j)) {
        if (p == Position::HG) {
            //On insere a l'emplacement HG la nouvelle carte
        }
        if (p == Position::HD) {
            //insererHD
        }
        if (p == Position::BG) {
            //insererBG
        }
        if (p == Position::BD) {
            //insererBD
        }
    }
}
