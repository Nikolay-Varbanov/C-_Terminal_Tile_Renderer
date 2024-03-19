#ifndef TCHESSBOARD_H
#define TCHESSBOARD_H

#include <string>
#include "TTile.h"

class TChessBoard {
	private: // Facilities
		TTile _boardTiles[64];
		std::string _tile_address;
		int _cursor;
		char _selectedTileBorderCache;
		int _selectedTileCursorCache;
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