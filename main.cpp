#include <iostream>
#include <chrono>
#include <string>
#include <vector>

#include "bitboard.h"
#include "maps.h"
#include "move.h"
#include "moveGen.h"
#include "perft.h"

int main() {
	maps::init();

	std::string fen;
	getline(std::cin, fen);
	bitboard::decode(fen);

	int depth;
	std::cin >> depth;

	perft::test(&bitboard::board, depth);

	return 0;
}