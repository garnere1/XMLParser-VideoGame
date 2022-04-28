#include "Room.h"
#include <iostream>

Room::Room() {
	std::cout << "  Room: " << std::endl;
}

void Room::setName(std::string name) {
	this->name = name;
	std::cout << "    Name: " << name << std::endl;
}

void Room::setDescription(std::string description) {
	this->description = description;
	std::cout << "    Description: " << description << std::endl;
}

void Room::setItem(std::string item) {
	room_items.push_back(item);
	if (item != "")
	{
	}
}

void Room::setItem2(std::string item) {
	room_items.push_back(item);
}


void Room::setContainer(std::string container) {
	room_containers.push_back(container);
	if (container != "")
	{
		std::cout << "Item: " << container << std::endl;
	}
}

void Room::setCreature(std::string rcreat) {
	room_creats.push_back(rcreat);
	//this->creature = rcreat;
}

void Room::setRoomType(std::string room_type) {
	this->room_type = room_type;
}

void Room::printRoomType() {
	if (this->room_type != "")
	{
		std::cout << "    Type: " << this->room_type << std::endl;
	}
	else 
	{
		std::cout << "    Type: regular" << std::endl;
	}
}

std::string Room::getName() {
	return name;
}

std::string Room::getDescription() {
	return description;
}

std::vector<std::string> Room::getItems() {
	return room_items;
}

std::vector<std::string> Room::getContainers() {
	return room_containers;
}

int Room::parseCreatures(std::string rcreat) {
	int check = 0;
	for (int i = 0; i < room_creats.size(); i++) {
		if (room_creats[i] == rcreat) {
			check = 1;
		}
	}
	return check;
}

std::string Room::getRoomType() {
	return room_type;
}

void Room::addTrigger(Trigger* trigger) {
	this->room_trig = trigger;
}

void Room::addBorder(Border* border) {
	borders.push_back(border);
}

void Room::printItem()
{
	for(int i = 0; i < room_items.size(); i++) {
		std::cout << room_items[i] << std::endl;
	}
}


std::vector<std::string> Room::getRoomCont() {
	return room_containers;
}


std::string Room::getBorder(std::string name) {
	std::string name1;
	if(name == "n") 
		name1 = "north";
	if(name == "s") 
		name1 = "south";
	if(name == "e") 
		name1 = "east";
	if(name == "w") 
		name1 = "west";
	std::vector<Border*>::iterator iter;
	for (iter = borders.begin(); iter != borders.end(); iter++) {
		if(name1 == (*iter)->getDirection())
			return (*iter)->getName();
	}
	return "no";
}

Object* Room::parseTriggers(std::string object)
{
	return room_trig->parseConditions(object, "room");
}

void Room::parseTriggersUpdate(std::string object, std::string status) {
	//triggers[0]->parseConditionsUpdate(object, status);
	room_trig->parseConditionsUpdate(object, status);
}

void Room::parseTriggersDelete(std::string object) {
	//triggers[0]->parseConditionsDelete(object);
	room_trig->parseConditionsDelete(object);
}

void Room::removeIt(std::string item) {
	int idx;
	for(int i = 0; i < room_items.size(); i++) {
		if(room_items[i] == item) {
				idx = i;
		}
	}
	room_items.erase(room_items.begin() + idx);
}



