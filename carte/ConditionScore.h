#ifndef CONDITIONSCORE_H
#define CONDITIONSCORE_H

#include <cstddef>

namespace Codex {

class Plateau;

class ConditionScore {
public:
    virtual ~ConditionScore() = default;

    virtual std::size_t calculer(const Plateau& plateau) const = 0;
};

}

#endif
