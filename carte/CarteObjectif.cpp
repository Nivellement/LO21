#include "CarteObjectif.h"


CarteObjectif::CarteObjectif(
    int i,
    const Codex::ConditionScore* condition,
    int p,
    TypeObjectif t
) : Carte(i), conditionScore(condition), points(p), type(t) {}

void CarteObjectif::afficher(std::ostream& f) const {
    f << "Objectif " << getId() << " (";
    f << (type == TypeObjectif::SECRET ? "secret" : "commun");
    f << "), " << points << " points";
}

