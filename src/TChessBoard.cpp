#include <iostream>
#include <string>

#include "TChessBoard.h"
#include "TTile.h"

TChessBoard::TChessBoard() : _tile_address("a1"),
														 _cursor(0),
														 _selectedTileBorderCache(' '),
														 _selectedTileCursorCache(-1) {
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
	char padding = ' ';
	for(int rows = 0; rows < 8; rows++) {
		for(int columns = 0; columns < 8; columns++) {
		if( (rows + 1) % 2 == 0) {
			// row is even
			if( (columns + 1) % 2 == 0) { // Odds are white even are black
				// column is even
				padding = '-'; // that is black
			} else {
				// column is odd
				padding = '+'; // that is white
				
			}
		} else {
			// row is even
			if( (columns + 1) % 2 == 0) { // Odds are black even are white
				// column is even
				padding = '+'; // that is white
			} else {
				// column is odd
				padding = '-'; // that is black
				
			}
		}
			_cursor = coordinatesToCursor(columns, rows);
			init_state = _boardTiles[_cursor].setBorderSymbol(padding);
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
		
		for(STAGE stage = STAGE_ONE; stage < ALL_STAGES; stage++) {
			
			for(int columns = 0; columns < 8; columns++) {
			
				_cursor = coordinatesToCursor(columns, rows);
				_boardTiles[_cursor].OnStageRender(stage);
			
			}
			std::cout << std::endl;
		}
		std::cout << std::endl;
	}
	
	return render_state;
	
}

bool TChessBoard::selectTile(std::string raw_input) {
	bool select_state = false;
	//deselectTile();
	if(constructLinearCursor(raw_input)) {
		std::cout << "Selection successful cursor is: " << _cursor << std::endl;
		_selectedTileBorderCache = _boardTiles[_cursor].getBorderSymbol();
		_selectedTileCursorCache = _cursor;
		std::cout << "In TChessBoard::selectTile(std::string() cache is: " 
							<< _selectedTileBorderCache 
							<< std::endl;
		if(_boardTiles[_cursor].setBorderSymbol('*'))
			select_state = true;
	} else {
		std::cout << "Selection failed" << std::endl;
		select_state = false;
	}
	return select_state;
}

bool TChessBoard::deselectTile() {
	bool deselect_state = false;
	
	if(_selectedTileBorderCache != ' ' || _selectedTileCursorCache < 0 ) {
		deselect_state = _boardTiles[_selectedTileCursorCache].setBorderSymbol(_selectedTileBorderCache);
		_selectedTileBorderCache = ' ';
		_selectedTileCursorCache = -1;
	}
	if(deselect_state != true)
		std::cout << "deselect_state is false but why?" << std::endl;
	
	return deselect_state;
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