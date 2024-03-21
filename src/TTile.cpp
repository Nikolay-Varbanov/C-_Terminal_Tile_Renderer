#include <iostream>
#include "TTile.h"

// ++Operator for the enum
// prefix (++stage)
STAGE& operator++(STAGE& stage) {
	// check for overflow
	if(stage != STAGE_THREE) {
		stage = static_cast<STAGE>(stage + 1); // static_cast required
	} else {
		stage = STAGE_ONE;
	}
	return stage;
}
// postfix (stage++)
STAGE operator++(STAGE& stage, int) {
	STAGE rVal = stage;
	++stage;
	return rVal;
}

TTile::TTile() : _border_symbol('*'),
								 _content('A'),
								 _padding(true),
								 _is_rendering(false),
								 _render_all_mode(false),
								 _render_stage(STAGE_ONE),
								 _select_state(false),
								 _selected_border_symbol('-') {
	std::cout << "Constructing a default TTile!!!" << std::endl;
}

TTile::TTile(char border_symbol, 
						 char _selected_border_symbol, 
						 char content, 
						 bool padding) : _border_symbol(border_symbol),
														 _content(content),
														 _padding(padding),
														 _is_rendering(false),
														 _render_all_mode(false),
														 _render_stage(STAGE_ONE),
														 _select_state(false),
														 _selected_border_symbol('-') {
	std::cout << "Constructing a TTile!!!" << std::endl;
}

TTile::~TTile() {
	std::cout << "Deconstructing a TTile!!!" << std::endl;
}

bool TTile::renderBorder() {
	for(int i=0; i<3;i++) {
		renderBorderSymbol();
		if(_padding)
			std::cout << " ";
	}
	if(_padding)
			std::cout << " ";
		return true;
}

bool TTile::renderBorderSymbol() {
	if(_select_state) {
		std::cout << _selected_border_symbol;
	} else {
		std::cout << _border_symbol;
	}
	return true;
}

bool TTile::renderContent() {
	for(int i=0; i<3;i++) {
		if(i==1) {
			std::cout << _content;
		} else {
			renderBorderSymbol();
		}
		if(_padding)
			std::cout << " ";
	}
	if(_padding)
			std::cout << " ";
	return true;
}

bool TTile::IsRendering() {
	return _is_rendering;
}

bool TTile::setRenderingMode(bool render_all) {
	bool set_state = false;
	// Check if Tile is done rendering
	if(!IsRendering()) {
		_render_all_mode = render_all;
		set_state = true;
	}
	
	return set_state;
}

bool TTile::flipSelectedState() {
	if(_select_state) {
		_select_state = false;
	} else {
		_select_state = true;
	}
	return true;
}

bool TTile::OnStageRender() {
	switch(_render_stage) {
		case STAGE_ONE:
			// stage 1
			renderBorder();
			_render_stage++;
			_is_rendering = true;
			break;
		case STAGE_TWO:
			// stage 2
			renderContent();
			_render_stage++;
			break;
		case STAGE_THREE:
			// Stage 3
			renderBorder();
			_render_stage++;
			_is_rendering = false;
			break;
		/*case ALL_STAGES:
			renderBorder();
			std::cout << std::endl;
			renderContent();
			std::cout << std::endl;
			renderBorder();
			std::cout << std::endl;
			break;*/
		default:
			std::cout << "In TTile::OnStageRender() invalid stage given: " << _render_stage << std::endl;
			break;
	}
	return true;
}

bool TTile::setBorderSymbol(char symbol) {
	_border_symbol = symbol;
	return true;	
}

char TTile::getBorderSymbol() {
	return _border_symbol;
}

bool TTile::setSelectedBorderSymbol(char symbol) {
	_selected_border_symbol = symbol;
	return true;
}

bool TTile::setContent(char content) {
	_content = content;
	return true;
}