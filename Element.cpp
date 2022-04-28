#include "Element.h"
#include <iostream>

Element::Element(std::string name) {
	this->name = name;
	std::cout << "Element Constructor with name " << name << std::endl;
}
