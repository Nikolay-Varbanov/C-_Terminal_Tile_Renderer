#ifndef TTILE_H
#define TTILE_H

enum STAGE {
	INVALID_STAGE = -1,
	STAGE_ONE,
	STAGE_TWO,
	STAGE_THREE,
	ALL_STAGES
};
STAGE& operator++(STAGE& stage);
STAGE operator++(STAGE& stage, int);

class TTile {
	private: // Facilities
		char _border_symbol;
		bool _padding;
		char _content;
	public: // Constructs
		TTile();
		TTile(char border_symbol, char content, bool padding = true);
		~TTile();
	private: // Utilities
		bool renderBorder();
		bool renderContent();
	public: // Utilities
		bool OnStageRender(STAGE stage);
		bool setBorderSymbol(char symbol);
		char getBorderSymbol();
		bool setContent(char content);
};

#endif