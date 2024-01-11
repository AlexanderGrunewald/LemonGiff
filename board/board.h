// ChessBoard.h

#ifndef CHESSBOARD_H
#define CHESSBOARD_H

#include <cstdint>
#include <iostream>
#include <stdint-gcc.h>

class ChessBoard {
public:
    ChessBoard();
    ~ChessBoard();
    void printBoard();

private:
    typedef uint64_t U64;

    U64 whitePawns;
    U64 whiteKnights;
    U64 whiteBishops;
    U64 whiteRooks;
    U64 whiteQueens;
    U64 whiteKing;

    U64 blackPawns;
    U64 blackKnights;
    U64 blackBishops;
    U64 blackRooks;
    U64 blackQueens;
    U64 blackKing;

    U64 whitePieces;
    U64 blackPieces;
    U64 allPieces;

    char getPieceAt(int square) const;
};

#endif // CHESSBOARD_H
