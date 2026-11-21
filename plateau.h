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
    bool peutAjouterCarte(const Codex::CartePlacement& cd, Face f, const size_t& i, const size_t& j) const;
    bool verifInsereHG(const Codex::CartePlacement& cAjouter, const Face& f, const size_t& i, const size_t& j) const;
    bool verifInsereHD(const Codex::CartePlacement& cAjouter, const Face& f, const size_t& i, const size_t& j) const;
    bool verifInsereBG(const Codex::CartePlacement& cAjouter, const Face& f, const size_t& i, const size_t& j) const;
    bool verifInsereBD(const Codex::CartePlacement& cAjouter, const Face& f, const size_t& i, const size_t& j) const;
    void insererHG(const Codex::CartePlacement& c, Face f, const size_t& i, const size_t& j);
    void insererHD(const Codex::CartePlacement& c, Face f, const size_t& i, const size_t& j);
    void insererBG(const Codex::CartePlacement& c, Face f, const size_t& i, const size_t& j);
    void insererBD(const Codex::CartePlacement& c, Face f, const size_t& i, const size_t& j);

    void ajouterCarte(const Codex::CartePlacement& c, Face f, const size_t& i, const size_t& j);

};


#endif //CODEX_NATURALIS_PLATEAU_H
