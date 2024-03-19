#ifndef TTILE_H
#define TTILE_H

enum STAGE {
	INVALID_STAGE = -1,
	STAGE_ONE,
	STAGE_TWO,
	STAGE_THREE
};

class TTile {
	private: // Facilities
		char _border_symbol;
		bool _padding;
		char _content;
	public: // Constructs
		TTile();
		TTile(char border_symbol, char content, bool padding = true);
		~TTile();
	public: // Utilities
		bool OnStageRender(STAGE stage);
		bool setBorderSymbol(char symbol);
		bool setContent(char content);
};

#endif