#ifndef TCHESSBOARD_H
#define TCHESSBOARD_H

#include <string>
#include "TTile.h"

class TChessBoard {
	private: // Facilities
		TTile _boardTiles[64];
		std::string _tile_address;
		int _cursor;
	public: // Constructs
		TChessBoard();
		~TChessBoard();
	private: // Utilities
		bool constructLinearCursor(std::string);
	public: // Utilities
		bool selectTile(std::string);
		bool setCursor(int);
};

#endif