#include "Creat.h"
#include <iostream>

Creat::Creat(){
	std::cout << "  Creature:" << std::endl;
}

void Creat::setCreatName(std::string creat_name) {
	this->creat_name = creat_name;
	std::cout << "    Name: " << creat_name << std::endl;
}

void Creat::setVun(std::string vun) {
	this->vun = vun;
	std::cout << "    Vulnerability: " << vun << std::endl;
}

void Creat::addVun(std::string vun) {
	vuns.push_back(vun);
	//attacks.push_back(attack);
	//std::cout << attacks[0]->getAction() <<std::endl;
}

void Creat::setAttack(Attack* _attack) {
	this->atk = _attack;
}

void Creat::addCreatTrigger(Trigger* creat_trigger) {
	//creat_triggers.push_back(creat_trigger);
	this->creat_trig = creat_trigger;
}

void Creat::creatDone() {
	std::cout << "\n" << std::endl;
}

std::string Creat::getCreatName() {
	return creat_name;
}

std::string Creat::getVun() {
	return vun;
}

void Creat::printCreatO() {
	std::cout << "    Owner: Main Cavern" << std::endl;
}
