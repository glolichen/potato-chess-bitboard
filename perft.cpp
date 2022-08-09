#include <chrono>
#include <cstring>
#include <iostream>
#include <vector>

#include "bitboard.h"
#include "move.h"
#include "moveGen.h"
#include "perft.h"

void perft::test(bitboard::Position *board, int depth) {
	std::cout << bitboard::encode(board) << ", perft " << depth << "\n";

	ull start = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
	ull nodes = perft::perft(&bitboard::board, depth, true);
	std::cout << "nodes: " << nodes << "\n";
	ull after = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
	
	std::cout << "time: " << after - start << "ms\n";
	std::cout << "nodes per second: " << (ull)((double)nodes / (after - start) * 1000) << "nps\n";
}

ull perft::perft(bitboard::Position *board, int depth, bool first) {
	std::vector<int> moves;
	moveGen::moveGen(board, &moves);

	if (depth == 1)
		return moves.size();

	ull old = 0;
	ull positions = 0;

	for (int move : moves) {
		if (first) {
			move::printMove(move, false);
			std::cout << ": ";
		}

		bitboard::Position newBoard;
		memcpy(&newBoard, board, sizeof(*board));
		move::makeMove(&newBoard, move);

		positions += perft(&newBoard, depth - 1, false);

		if (first) {
			std::cout << positions - old << std::endl;
			old = positions;
		}
	}

	return positions;
}
