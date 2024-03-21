#ifndef TCHESSBOARD_H
#define TCHESSBOARD_H

#include <string>
#include "TTile.h"

class TChessBoard {
	private: // Facilities
		TTile _boardTiles[64];
		int _cursor;
		int _selectedCursor;
	public: // Constructs
		TChessBoard();
		~TChessBoard();
	private: // Utilities
		bool checkCoordinates(std::string);
		int coordinatesToCursor(int, int);
		bool constructLinearCursor(std::string);
	public: // Utilities
		bool OnInit();
		bool OnRender();
		bool selectTile(std::string);
		bool deselectTile();
		bool setCursor(int);
};

#endif