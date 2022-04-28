#include "Condition.h"
#include <iostream>

Condition::Condition(){
	//std::cout << "    Condition: " << std::endl;
}

void Condition::printCondition() {
	std::cout << "      Condition: " << std::endl;
}
	
void Condition::setHas(std::string has) {
	if (has == "no" | has == "")
	{
		this->has = 0;
		//std::cout << "        Has: 0" << std::endl;
	}
	else 
	{
		this->has = 1;
		//std::cout << "        Has: 1" << std::endl;
	}
}

void Condition::setObjName(std::string objName, std::string i) {
	this->objName = objName;
	if (objName != "")
	{
		//std::cout << "        Object: " << i << " " << objName << std::endl;
	}
}

void Condition::setObjStatus(std::string objStatus) {
	this->objStatus = objStatus;
	/*if (objStatus != "")
	{
		std::cout << "        Status: " << objStatus << std::endl;
	}*/
}

void Condition::printStatus() {
	if (objStatus != "")
	{
		std::cout << "        Status: " << objStatus << std::endl;
	}
}

void Condition::setOwnerName(std::string ownerName) {
	this->ownerName = ownerName;
	if (ownerName != "")
	{
		std::cout << "        Owner: Container " << ownerName << std::endl;
	}
}


int Condition::getHas() {
	return has;
}

std::string Condition::getObjName() {
	return objName;
}

std::string Condition::getObjStatus() {
	return objStatus;
}

std::string Condition::getOwnerName() {
	return ownerName;
}

void Condition::addObject(Object* obj) {
	objects.push_back(obj);
}

Object* Condition::parseObjects(std::string object, std::string type) {
	if (objects[0]->name == object)
	{
		return objects[0];
	}
	else
	{
		return NULL;
	}
}

void Condition::parseObjectsDelete(std::string object) {
	if (objects[0]-> name == object)
	{
		objects.erase(objects.begin()+0);
	}
}
