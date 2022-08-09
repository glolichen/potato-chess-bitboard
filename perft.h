#ifndef PERFT_H
#define PERFT_H

#include "bitboard.h"

namespace perft {
	void test(bitboard::Position *board, int depth);
	ull perft(bitboard::Position *board, int depth, bool first);
}

#endif
