#include "Attack.h"
#include <iostream>

Attack::Attack() {
	std::cout << "    Attack:" << std::endl;
	std::cout << "      Permenant: 0" << std::endl;
	std::cout << "      Used: 0" << std::endl;
}

void Attack::setAttackPrint(std::string attack_print) {
	this->attack_print = attack_print;
	std::cout << "      Print: " << attack_print << std::endl;
}

void Attack::setAction(std::string action) {
	//this->action = action;
	std::cout << "      Action: " << action << std::endl;
	actions.push_back(action);
}

std::string Attack::getAttackPrint() {
	return attack_print;
}

std::string Attack::getAction() {
	return action;
}

void Attack::addAttackCondition(Condition* condition) {
	//attack_conditions.push_back(condition);
	this->atk_cond = condition;
}
