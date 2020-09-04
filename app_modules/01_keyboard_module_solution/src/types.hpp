#pragma once

#include <vector>

using std::vector;

namespace command {
    enum class Key {
        FORWARD
    };

    static vector<Key> ALL_KEYS {Key::FORWARD};
}

namespace std {
    template <> struct hash<command::Key> {
        size_t operator() (const command::Key &t) const { return size_t(t); }
    };
}