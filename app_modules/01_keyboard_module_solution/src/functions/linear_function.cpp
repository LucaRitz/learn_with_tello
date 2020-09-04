#include "linear_function.hpp"

#include <algorithm>

int mathematical::LinearFunction::calc(int min, int max, int time) const {
    int y = 2 * time + 2;
    y = std::max(min, y);
    return std::min(max, y);
}