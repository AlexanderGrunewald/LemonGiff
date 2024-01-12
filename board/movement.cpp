#include "movement.h"

U64 Movement::moveNorth(U64 piece, int times) {
    return piece << 8 *times;
}
