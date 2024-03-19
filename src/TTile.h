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
		char _border_symbow;
		bool _padding;
		char _content;
	public: // Constructs
		TTile();
		~TTile();
	public: // Utilities
		bool OnStageRender(STAGE stage);
};

#endif