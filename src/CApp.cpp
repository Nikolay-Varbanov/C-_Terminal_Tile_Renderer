#include <iostream>
#include "TTile.h"

int main()
{
	std::cout << "Hey I'm working here!!!" << std::endl;
	
	TTile my_tile;
	
	my_tile.OnStageRender(STAGE_ONE);
	my_tile.OnStageRender(STAGE_TWO);
	my_tile.OnStageRender(STAGE_THREE);
	
	return 0;
}