#include "Cont.h"
#include <iostream>

Cont::Cont(){
	std::cout << "  Container:" << std::endl;
	this->open = false;
}

void Cont::setContName(std::string cont_name, std::string own) {
	this->cont_name = cont_name;
	std::cout << "    Name: " << cont_name << std::endl;
}

void Cont::setContItem(std::string cont_item) {
	cont_items.push_back(cont_item);
	std::cout << "    Item: " << cont_item << std::endl;
}

void Cont::setContItem2(std::string cont_item) {
	cont_items.push_back(cont_item);
}

void Cont::setContStatus(std::string cont_status) {
	this->cont_status = cont_status;
	std::cout << "    Status: " << cont_status << std::endl;
}

void Cont::setAccept(std::string accept) {
	this->accept = accept;
}

void Cont::addContTrigger(Trigger* cont_trigger) {
	//cont_triggers.push_back(cont_trigger);
	this->cont_trig = cont_trigger;
}

void Cont::setOwner(std::string n) {
	this->owner = n;
	std::cout << "    Owner: " << n << std::endl;
}

std::string Cont::getContName() {
	return cont_name;
}

bool Cont::getOpen() {
	return open;
}

std::vector<std::string> Cont::getContItem() {
	return cont_items;
}

std::string Cont::getContStatus() {
	return cont_status;
}

std::string Cont::getAccept() {
	return accept;
}

std::string Cont::getOwner() {
	return owner;
}

void Cont::printAccepts() {
	if (this->accept != "")
	{
		std::cout << "    Accepts: " << this->accept << std::endl;
	}
}

void Cont::setHasTrigger(std::string has_t) {
	this->has_trigger = has_t;
}

std::string Cont::getHasTrigger() {
	return has_trigger;
}

//std::string Cont::parseContTriggers(std::string object)
Object* Cont::parseContTriggers(std::string object)
{
	//Trigger* trig1 = cont_triggers[0];
	Trigger* trig1 = cont_trig;
	//std::string obj1 = trig1->parseConditions(object);
	Object* obj1 = trig1->parseConditions(object, "cont");
	return obj1;
}

void Cont::parseContTriggersUpdate(std::string object, std::string status) {
	//cont_triggers[0]->parseConditionsUpdate(object, status);
	cont_trig->parseConditionsUpdate(object, status);
}

void Cont::parseContTriggersDelete(std::string object) {
	//cont_triggers[0]->parseConditionsDelete(object);
	cont_trig->parseConditionsDelete(object);
}


void Cont::setContOpen() {
	this->open = true;
}

bool Cont::getContOpen() {
	return open;
}


void Cont::removeCit(std::string item) {
	int idx;
	for(int i = 0; i < cont_items.size(); i++) {
		if(cont_items[i] == item) {
				idx = i;
		}
	}
	cont_items.erase(cont_items.begin() + idx);
}


