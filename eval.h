#ifndef EVAL_H
#define EVAL_H

#include <vector>

namespace eval {
	void initPieceTables();

	int evaluate(bitboard::Position *board);

	bool insufMat(std::vector<char>* pieces);
	int kingLocationEval(int endPhase);
}

#endif
