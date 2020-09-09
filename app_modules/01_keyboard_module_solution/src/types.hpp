#pragma once

#include <vector>

using std::vector;

namespace command {
    enum class Key {
        FORWARD
    };

    static vector<Key> ALL_KEYS {Key::FORWARD};
}

namespace mathematical {
    class Function {
    public:
        [[nodiscard]] virtual int calc(int min, int max, int time) const = 0;
    };
}

namespace std {
    template <> struct hash<command::Key> {
        size_t operator() (const command::Key &t) const { return size_t(t); }
    };
}