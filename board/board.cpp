#include <stdint-gcc.h>
#include <iostream>
#include <map>
#include "board.h"
#include "movement.h"

ChessBoard::ChessBoard()
            : whitePawns(0x00FF000000000000), whiteKnights(0x4200000000000000), whiteBishops(0x2400000000000000),
              whiteRooks(0x8100000000000000), whiteQueens(0x0800000000000000), whiteKing(0x1000000000000000),
              blackPawns(0x000000000000FF00), blackKnights(0x0000000000000042), blackBishops(0x0000000000000024),
              blackRooks(0x0000000000000081), blackQueens(0x0000000000000008), blackKing(0x0000000000000010) {

        whitePieces = whitePawns | whiteKnights | whiteBishops | whiteRooks | whiteQueens | whiteKing;
        blackPieces = blackPawns | blackKnights | blackBishops | blackRooks | blackQueens | blackKing;
        allPieces = whitePieces | blackPieces;
        pieceMap = {
                {'P', whitePawns},
                {'N', whiteKnights},
                {'B', whiteBishops},
                {'R', whiteRooks},
                {'Q', whiteQueens},
                {'K', whiteKing},
                {'p', blackPawns},
                {'n', blackKnights},
                {'b', blackBishops},
                {'r', blackRooks},
                {'q', blackQueens},
                {'k', blackKing}
        };
    }

    ChessBoard::~ChessBoard() {
    }

    void ChessBoard::printBoard() {
        for (int rank = 7; rank >= 0; --rank) {
            for (int file = 0; file < 8; ++file) {
                int square = rank * 8 + file; // Finds the index of the square
                char piece = getPieceAt(square);
                std::cout << piece << " ";
            }
            std::cout << "\n";
        }
    }


    char ChessBoard::getPieceAt(int square) const {
        U64 mask = 1ULL << square;

        for (const std::pair<const char, U64>& pair : pieceMap) {
            char piece = pair.first;
            U64 bitBoard = pair.second;

            if (bitBoard & mask) { // iterates through the boards and looks if the piece exists
                return piece;
            }
        }

        return '.';
    }


    void ChessBoard::setBitAt(int startSquare, int endSquare, char piece) {
        U64 startMask = 1ULL << startSquare;
        U64 endMask = 1ULL << endSquare;


        U64 &bitBoard = pieceMap[piece];
        U64 movementNorth = Movement::moveNorth(startMask,1);
        if (bitBoard & startMask){
            bitBoard = bitBoard | movementNorth; // endMask
            bitBoard = bitBoard & ~ startMask;
            pieceMap[piece] = bitBoard;
        }

    }


    void ChessBoard::updateAggregateBitboards() {

    }


int main() {
    ChessBoard board;
    board.printBoard();
    board.setBitAt(0, 20,'r');
    board.printBoard();
    return 0;
}