#include <iostream>
#include <string>
#include <vector>
#include "Player.h"
#include "Room.h"

Player::~Player() {};

void Player::setLocation(Room * room) {
	location = room;
}

Room * Player::getLocation() {
	//std::cout <<location->name<< std::endl;
	return location;
}

void Player::addItem(Itm* item) {
	items.push_back(item);
}

void Player::addObj(Object* obj) {
	objs.push_back(obj);
}

void Player::removeItem(Itm* item) {
	int idx;
	for(int i = 0; i < items.size(); i++) {
		if(items[i]->getItmName() == item->getItmName()) {
				idx = i;
		}
	}
	items.erase(items.begin() + idx);
}

