#include"Game.h"
#include<memory>

#include<direct.h>
#include<iostream>

#include"Utils.h"


int main(int argc, char** argv) {
	
	std::shared_ptr<Game> game = std::make_shared<Game>();
	game->start();

	return 0;

}



