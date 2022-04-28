#include "Border.h"
#include <iostream>

Border::Border(){
	//std::cout << "Border Constructor" << std::endl;
}

void Border::setDirection(std::string direction, std::string name) {
	this->direction = direction;
}

void Border::setName(std::string name) {
	this->name = name;
}

std::string Border::getDirection() {
	return direction;
}

std::string Border::getName() {
	return name;
}

void Border::printBorder()
{
	std::cout << "    " << this->direction << ": " << this->name << std::endl;
}
