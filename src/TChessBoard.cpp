#include <iostream>
#include <string>

#include "TChessBoard.h"
#include "TTile.h"

TChessBoard::TChessBoard() : _cursor(0),
														 _selectedCursor(-1),
														 _selectedTileBorderCache(' ') {
	std::cout << "Constructing a default TChessBoard" << std::endl;
};

TChessBoard::~TChessBoard() {
		std::cout << "Destructing a default TChessBoard" << std::endl;
};

bool TChessBoard::checkCoordinates(std::string raw_input) {
	
	bool coordinate_state = false;
	// first coordinate
	if(std::isalpha(raw_input[0]) && (raw_input[0] > 96 && raw_input[0] < 105 )) {
		coordinate_state = true;
	} else {
		std::cout << "In TChessBoard::checkCoordinates(std::string raw_input) First position in address is malformed" << std::endl;
		coordinate_state = false;
	}
	// second coordinate
	if(std::isdigit(raw_input[1]) && (raw_input[1] > 48 && raw_input[1] < 57)) {
		coordinate_state = true;
	} else {
		std::cout << "In TChessBoard::checkCoordinates(std::string raw_input) Second position in address is malformed" << std::endl;
		coordinate_state = false;
	}
	
	return coordinate_state;
	
}

int TChessBoard::coordinatesToCursor(int first, int second) {
	return first + (second * 8);
};

bool TChessBoard::constructLinearCursor(std::string raw_input) {
	bool input_state = false;
	
	input_state = checkCoordinates(raw_input);
	
	if(input_state) {
		_cursor = coordinatesToCursor(int(raw_input[0]) - 97, atoi(&raw_input[1]) - 1);
	} else {
		std::cout << "In TChessBoard::constructLinearCursor(std::string) input is malformed" << std::endl;
	}
	
	return input_state;
}

bool TChessBoard::OnInit() {
	bool init_state = false;
	char border = ' ';
	char selected_border = '*';
	for(int rows = 0; rows < 8; rows++) {
		for(int columns = 0; columns < 8; columns++) {
		if( (rows + 1) % 2 == 0) {
			// row is even
			if( (columns + 1) % 2 == 0) { // Odds are white even are black
				// column is even
				border = '-'; // that is black
			} else {
				// column is odd
				border = '+'; // that is white
				
			}
		} else {
			// row is even
			if( (columns + 1) % 2 == 0) { // Odds are black even are white
				// column is even
				border = '+'; // that is white
			} else {
				// column is odd
				border = '-'; // that is black
				
			}
		}
			_cursor = coordinatesToCursor(columns, rows);
			init_state = _boardTiles[_cursor].setBorderSymbol(border);
			init_state = _boardTiles[_cursor].setSelectedBorderSymbol(selected_border);
		}
	}
	
	return init_state;
}

bool TChessBoard::OnRender() {
	/*
	* Note that the rows are reversed
	*	That is because we render from top to bottom
	* But the Board counts from bottom to top
	*/
	bool render_state = false;
	
	for(int rows = 7; rows >=0; rows--) {
		
		//for(STAGE stage = STAGE_ONE; stage < ALL_STAGES; stage++) {
		do {	
			for(int columns = 0; columns < 8; columns++) {
			
				_cursor = coordinatesToCursor(columns, rows);
				_boardTiles[_cursor].OnRender();
			
			}
			std::cout << std::endl;
		} while(_boardTiles[_cursor].IsRendering());
		std::cout << std::endl;
	}
	
	return render_state;
	
}

bool TChessBoard::selectTile(std::string raw_input) {
	bool select_status = false;
	// Check if there is already a selected tile
	if(_selectedCursor != -1) {
		select_status = deselectTile();
		if(select_status)
			std::cout << "Deselect called from selectTile failed" << std::endl;
	}
	
	if(constructLinearCursor(raw_input)) {
		_selectedCursor = _cursor;
		select_status = _boardTiles[_selectedCursor].flipSelectedState();
	}
	return select_status;
}

bool TChessBoard::deselectTile() {
	bool deselect_status = false;
	// Check if there is a selected tile
	if(_selectedCursor != -1) {
		deselect_status = _boardTiles[_selectedCursor].flipSelectedState();
		_selectedCursor = -1;
	} else {
		deselect_status = false;
	}
	
	return deselect_status;
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