#include <iostream>
#include <string>
#include "TTile.h"
#include "TChessBoard.h"

int main()
{
	std::cout << "Hey I'm working here!!!" << std::endl;
	
	std::string input = " ";
	
	TChessBoard _myChessBoard;
	_myChessBoard.OnInit();
	
	std::cout << "Select a position on the board by giving the letter first and the number second" 
						<< std::endl;
						
	std::cin >> input;
	
	_myChessBoard.selectTile(input);
	_myChessBoard.OnRender();
	_myChessBoard.deselectTile();
	std::cout << "After deselectTile" << std::endl;
	_myChessBoard.OnRender();
	
	
	//_myChessBoard.selectTile("e4");
	
	/*
	TTile my_tile_list[4];
	for(int i=0;i<4;i++) {
		if(i%2 == 0) {
			my_tile_list[i].setBorderSymbol('-');
		} else {
			my_tile_list[i].setBorderSymbol('+');
		}
		my_tile_list[i].setContent(65 + i);
	}
	
	for(int i=0;i<4;i++) {
		my_tile_list[i].OnStageRender(STAGE_ONE);
	}
	
	std::cout << std::endl;
	
	for(int i=0;i<4;i++) {
		my_tile_list[i].OnStageRender(STAGE_TWO);
	}
	
	std::cout << std::endl;
	
	for(int i=0;i<4;i++) {
		my_tile_list[i].OnStageRender(STAGE_THREE);
	}
	
	std::cout << std::endl;
	
	
	TTile my_tile('-','C');
	*/
	/*
	my_tile.OnStageRender(STAGE_ONE);
	my_tile.OnStageRender(STAGE_TWO);
	my_tile.OnStageRender(STAGE_THREE);
	*/
	//my_tile.OnStageRender(ALL_STAGES);
	return 0;
}