#ifndef CARTEOBJECTIF_H
#define CARTEOBJECTIF_H

#include "Carte.h"
#include "CarteObjectif.h"
#include "ConditionScore.h"

using namespace Codex;

enum class TypeObjectif {
    SECRET,
    COMMUN
};
// Une carte Objectif n'est pas une carte a placer sur le plateau.
class CarteObjectif : public Carte {
private:
    const ConditionScore* conditionScore;
    int points;
    TypeObjectif type;

public:
    CarteObjectif(int i, const ConditionScore* condition,
                  int p, TypeObjectif t);

    const ConditionScore* getConditionScore() const {
        return conditionScore;
    }

    int getPoints() const {
        return points;
    }

    TypeObjectif getType() const {
        return type;
    }

    void afficher(std::ostream& f) const override;
};


#endif
