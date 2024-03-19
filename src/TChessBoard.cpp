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
	bool input_state = false;
	if(std::isalpha(raw_input[0]) && (raw_input[0] > 97 && raw_input[0] < 105 )) {
		std::cout << "In TChessBoard::constructLinearCursor(std::string raw_input) first position is char!!! and it is in ragen a to h" << std::endl;
		input_state = true;
	} else {
		std::cout << "First position in address is malformed";
		input_state = false;
	}
	if(std::isdigit(raw_input[1]) && (raw_input[1] > 48 && raw_input[1] < 57)) {
		std::cout << "In TChessBoard::constructLinearCursor(std::string raw_input) second position is digit and is not a zero" << std::endl;
		input_state = true;
	} else {
		std::cout << "Second position in address is malformed";
		input_state = false;
	}
	if(input_state) {
		_cursor = 0;
		_cursor = int(raw_input[0]) - 97;
		std::cout << "cursor after first address is: " << _cursor << std::endl;
		char temp = raw_input[1];
		_cursor += ( atoi(&raw_input[1]) - 1) * 8; // row multiplyed by number columns
		std::cout << "cursor after second address is: " << _cursor << std::endl;
	}
	
	return input_state;
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

bool TChessBoard::setCursor(int cursor) {
	bool argument_state = false;
	if(cursor >= 0 && cursor < 64) {
		std::cout << "In  TChessBoard::setCursor(int) cursor good: " << cursor << std::endl;
		argument_state = true;
	} else {
		std::cout << "In  TChessBoard::setCursor(int) cursor malformed" << std::endl;
	}
	return argument_state;
};