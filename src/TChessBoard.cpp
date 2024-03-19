#include <iostream>
#include <string>

#include "TChessBoard.h"
#include "TTile.h"

TChessBoard::TChessBoard() : _tile_address("a1"),
														 _cursor(0) {
	std::cout << "Constructing a default TChessBoard" << std::endl;
};

TChessBoard::~TChessBoard() {
		std::cout << "Destructing a default TChessBoard" << std::endl;
};

bool TChessBoard::constructLinearCursor(std::string raw_input) {
	if(std::isalpha(raw_input[0]) && (raw_input[0] > 60 && raw_input[0] < 105 ))
		std::cout << "In TChessBoard::constructLinearCursor(std::string raw_input) first position is char!!! and it is in ragen a to h" << std::endl;
	
	return true;
}

bool TChessBoard::selectTile(std::string raw_input) {
	if(constructLinearCursor(raw_input)) {
		std::cout << "Selection successful cursor is: " << _cursor << std::endl;
		return true;
	} else {
		std::cout << "Selection failed" << std::endl;
		return false;
	}
}