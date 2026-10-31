#include "CarteObjectif.h"

namespace Codex {

CarteObjectif::CarteObjectif(
    int i,
    const ConditionScore* condition,
    int p,
    TypeObjectif t
) : Carte(i), conditionScore(condition), points(p), type(t) {}

void CarteObjectif::afficher(std::ostream& f) const {
    f << "Objectif " << getId() << " (";
    f << (type == TypeObjectif::SECRET ? "secret" : "commun");
    f << "), " << points << " points";
}

}
