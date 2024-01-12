// ChessBoard.h

#ifndef CHESSBOARD_H
#define CHESSBOARD_H

#include <cstdint>
#include <iostream>
#include <map>
#include <stdint-gcc.h>

class ChessBoard {
public:
    typedef uint64_t U64;
    ChessBoard();
    ~ChessBoard();
    void printBoard();
    void setBitAt(int square, char piece);

    void setBitAt(int startSquare, int endSquare, char piece);

private:

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

    std::map<char, U64 > pieceMap;

    void removeBit(int square);
    int getBit(int square) const;
    void updateAggregateBitboards();

    char getPieceAt(int square) const;
};

#endif // CHESSBOARD_H
