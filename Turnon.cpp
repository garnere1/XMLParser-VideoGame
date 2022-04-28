#include "Turnon.h"
#include <iostream>

Turnon::Turnon() {
	std::cout << "    Turnon:" << std::endl;
	std::cout << "      Permenant: 0" << print << std::endl;
	std::cout << "      Used: 0" << print << std::endl;
}

void Turnon::setPrint(std::string print) {
	this->print = print;
	if (print != "")
	{
		std::cout << "      Print: " << print << std::endl;
	}
}

void Turnon::setAction(std::string action) {
	this->action = action;
	if (action != "")
	{
		std::cout << "      Action: " << action << std::endl;
	}
}

void Turnon::printTurnon() {
	/*if (this->print != "")
	{
		std::cout << "Print: " << this->print << std::endl;
	}*/
	if (this->action != "")
	{
		std::cout << this->action << std::endl;
	}
}
	

std::string Turnon::getPrint() {
	return print;
}

std::string Turnon::getAction() {
	return action;
}

void Turnon::setUsed(int _used) {
	this->used = _used;
}

int Turnon::getUsed() {
	return this->used;
}
