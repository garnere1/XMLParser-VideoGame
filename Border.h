#pragma once
#include <string>

class Border{
private:
	std::string direction;
	std::string name;

public:
	Border();
	void setDirection(std::string direction, std::string name);
	void setName(std::string name);
	void printBorder();

	std::string getDirection();
	std::string getName();
};
