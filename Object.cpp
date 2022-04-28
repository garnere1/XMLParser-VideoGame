#include "Object.h"
#include <iostream>

Object::Object() {
	//std::cout << "    Trigger:" << std::endl;
}

void Object::setName(std::string _name) {
	this->name = _name;
}

/*void Object::setObjOwner(std::string _owner) {
	objOwner = _owner;
}*/

/*std::string Object::getObjOwner() {
	return owner;
}*/

std::string Object::getName() {
	return this->name;
}
