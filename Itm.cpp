#include "Itm.h"
#include <iostream>

Itm::Itm(){
}

void Itm::setItmName(std::string itm_name) {
	this->itm_name = itm_name;
	//std::cout << "    Name: " << itm_name << std::endl;
}

void Itm::setItmStatus(std::string itm_status) {
	this->itm_status = itm_status;
	if (itm_status != "")
	{
		//std::cout << "    Status: " << itm_status << std::endl;
	}
}

void Itm::setItmWriting(std::string itm_writing) {
	this->itm_writing = itm_writing;
}

void Itm::addTurnon(Turnon* turnon) {
	this->itm_turnon = turnon;
	//turnons.push_back(turnon);
}

void Itm::printItmWriting() {
	if (this->itm_writing!= "")
	{
		std::cout << "    Writing: " << this->itm_writing << std::endl;
	}
}

std::string Itm::getItmName() {
	return itm_name;
}

std::string Itm::getItmStatus() {
	return itm_status;
}

std::string Itm::getItmWriting() {
	return itm_writing;
}
