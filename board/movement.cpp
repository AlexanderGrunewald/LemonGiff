#include "movement.h"

U64 Movement::moveNorth(U64 piece, int times) {
    return piece << 8 *times;
}

U64 Movement::moveEast(U64 piece, int times) {
    return piece >> 1 * times;
}

U64 Movement::moveWest(U64 piece, int times) {
    return piece << 1 * times;
}

U64 Movement::moveSouth(U64 piece, int times) {
    return piece >> 8 * times;
}

U64 Movement::moveNorthEast(U64 piece, int times) {
    return piece >> 7 * times;
}

U64 Movement::moveNorthWest(U64 piece, int times) {
    return piece >> 9 * times;
}

U64 Movement::moveSouthEast(U64 piece, int times) {
    return piece >> 9 * times;
}

U64 Movement::moveSouthWest(U64 piece, int times) {
    return piece >> 7 * times;
}