#ifndef TTILE_H
#define TTILE_H

enum STAGE {
	INVALID_STAGE = -1,
	STAGE_ONE,
	STAGE_TWO,
	STAGE_THREE
};
STAGE& operator++(STAGE& stage);
STAGE operator++(STAGE& stage, int);

class TTile {
	private: // Facilities
		char _border_symbol;
		char _selected_border_symbol;
		bool _padding;
		char _content;
		// States
		bool _is_rendering;
		bool _render_all_mode;
		bool _select_state;
	public: // Constructs
		TTile();
		TTile(char border_symbol, char _selected_border_symbol, char content, bool padding = true);
		~TTile();
	private: // Utilities
		bool renderBorder();
		bool renderBorderSymbol();
		bool renderContent();
	public: // Utilities
		bool IsRendering();
		bool setRenderingMode(bool);
		bool flipSelectedState();
		bool OnStageRender(STAGE stage);
		bool setBorderSymbol(char symbol);
		char getBorderSymbol();
		bool setSelectedBorderSymbol(char symbol);
		bool setContent(char content);
};

#endif