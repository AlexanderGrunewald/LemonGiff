#include <stdint-gcc.h>
#include <iostream>

/**
 * @class ChessBoard
 * @brief Represents a chess board with the current state of the chess pieces
 *
 * This class represents a chess board with the current state of the chess pieces.
 * It provides methods to initialize the board, print the board and retrieve the piece at a specific square.
 */
class ChessBoard {

public:

    ChessBoard()
            : whitePawns(0x00FF000000000000), whiteKnights(0x4200000000000000), whiteBishops(0x2400000000000000),
              whiteRooks(0x8100000000000000), whiteQueens(0x0800000000000000), whiteKing(0x1000000000000000),
              blackPawns(0x000000000000FF00), blackKnights(0x0000000000000042), blackBishops(0x0000000000000024),
              blackRooks(0x0000000000000081), blackQueens(0x0000000000000008), blackKing(0x0000000000000010) {

        whitePieces = whitePawns | whiteKnights | whiteBishops | whiteRooks | whiteQueens | whiteKing;
        blackPieces = blackPawns | blackKnights | blackBishops | blackRooks | blackQueens | blackKing;
        allPieces = whitePieces | blackPieces;
    }

    ~ChessBoard() {
    }

    /**
     * @brief Prints the current state of the chess board.
     *
     * This method prints the current state of the chess board, with the pieces represented
     * by their corresponding characters. The board is printed with ranks from 8 to 1,
     * and files from a to h. The black pieces are represented in lowercase and white pieces
     * in uppercase. An empty square is represented by a dot ('.').
     */
    void printBoard() {
        for (int rank = 7; rank >= 0; --rank) {
            for (int file = 0; file < 8; ++file) {
                int square = rank * 8 + file; // finds the index of the square
                char piece = getPieceAt(square);
                std::cout << piece << " ";
            }
            std::cout << "\n";
        }
    }

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

    char getPieceAt(int square) const {
        U64 mask = 1ULL << square; // shifts the 1 to the square we are looking for
        if (whitePawns & mask) return 'P'; // the code below well then see if there is a piece on the square
        if (whiteKnights & mask) return 'N';
        if (whiteBishops & mask) return 'B';
        if (whiteRooks & mask) return 'R';
        if (whiteQueens & mask) return 'Q';
        if (whiteKing & mask) return 'K';
        if (blackPawns & mask) return 'p';
        if (blackKnights & mask) return 'n';
        if (blackBishops & mask) return 'b';
        if (blackRooks & mask) return 'r';
        if (blackQueens & mask) return 'q';
        if (blackKing & mask) return 'k';
        return '.';
    }
};

int main() {
    ChessBoard board;
    board.printBoard();
    return 0;
}
