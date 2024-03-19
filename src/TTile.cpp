#include <iostream>
#include "TTile.h"

TTile::TTile() : _border_symbol('*'),
								 _content('A'),
								 _padding(true)	{
	std::cout << "Constructing a default TTile!!!" << std::endl;
}

TTile::TTile(char border_symbol, char content, bool padding) : _border_symbol(border_symbol),
																																			_content(content),
																																			_padding(padding) {
	std::cout << "Constructing a TTile!!!" << std::endl;
}

TTile::~TTile() {
	std::cout << "Deconstructing a TTile!!!" << std::endl;
}

bool TTile::renderBoarder() {
	for(int i=0; i<3;i++) {
		std::cout << _border_symbol;
		if(_padding)
			std::cout << " ";
	}
	if(_padding)
			std::cout << " ";
		return true;
}

bool TTile::renderContent() {
	for(int i=0; i<3;i++) {
		if(i==1) {
			std::cout << _content;
		} else {
			std::cout << _border_symbol;
		}
		if(_padding)
			std::cout << " ";
	}
	if(_padding)
			std::cout << " ";
	return true;
}

bool TTile::OnStageRender(STAGE stage) {
	switch(stage) {
		case STAGE_ONE:
			// stage 1
			renderBoarder();
			break;
		case STAGE_TWO:
			// stage 2
			renderContent();
			break;
		case STAGE_THREE:
			// Stage 3
			renderBoarder();
			break;
		case ALL_STAGES:
			renderBoarder();
			std::cout << std::endl;
			renderContent();
			std::cout << std::endl;
			renderBoarder();
			std::cout << std::endl;
			break;
		default:
			std::cout << "In TTile::OnStageRender(...) invalid stage given: " << stage << std::endl;
			break;
	}
	return true;
}

bool TTile::setBorderSymbol(char symbol) {
	_border_symbol = symbol;
	return true;	
}

bool TTile::setContent(char content) {
	_content = content;
	return true;
}