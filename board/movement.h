#ifndef MOVEMENT_H
#define MOVEMENT_H
#include <cstdint>
typedef uint64_t U64;

class Movement {
public:
    static U64 moveNorth(U64 piece, int times);
    static U64 moveSouth(U64 piece);
    static U64 moveWest(U64 piece);
    static U64 moveEast(U64 piece);
    static U64 moveNorthEast(U64 piece);
    static U64 moveNorthWest(U64 piece);
    static U64 moveSouthEast(U64 piece);
    static U64 moveSouthWest(U64 piece);
};

#endif
