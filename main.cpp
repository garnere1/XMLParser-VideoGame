#include <iostream>
#include <string>
#include <vector>
#include "XMLParser.h"

#include "Move.h"
#include "Player.h"

int main(int argc, char** args) {
	std::string filename;
	bool shouldPause = true;

	if (argc >= 2) {
		filename = args[1];
		std::cout << "File name is: " << filename << std::endl;
		shouldPause = false;
	}
	else {
		std::cout << "Enter filename: ";
		std::cin >> filename;
		std::cin.get();
		std::cout << "File name is: " << filename << std::endl;
	}

	XMLParser parser;
	std::cout << "\n" << std::endl;
	std::vector<Map*> map = parser.parseXML(filename);

	if(shouldPause) std::cin.get();

	Player *player1 = new Player();

	play(map, player1);

	return 0;
}
