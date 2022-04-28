#include "Trigger.h"
#include <iostream>

Trigger::Trigger() {
}

void Trigger::setType(std::string type) {
	//this->type = type;
	std::cout << "    Trigger:" << std::endl;
	if (type == "permanent")
	{
		std::cout << "      Permenant: 1" << std::endl;
	}
	else
	{
		std::cout << "      Permenant: 0" << std::endl;
	}
	std::cout << "      Used: 0" << std::endl;
}

void Trigger::setCommand(std::string command) {
	this->command = command;
	if (command != "")
	{
		std::cout << "      Command: " << command << std::endl;
	}
}

void Trigger::setTriggerAction(std::string trigger_action) {
	this->trigger_action = trigger_action;
	if (trigger_action != "")
	{
		std::cout << "      Action: " << trigger_action << std::endl;
	}
}

void Trigger::addAction(std::string _action) {
	trigger_actions.push_back(_action);
}

void Trigger::setPrint(std::string _print) {
	//std::cout << "here" << std::endl;
	this->type = _print;
	std::cout << "      Print: " << _print << std::endl;
}

std::string Trigger::getType() {
	return type;
}

std::string Trigger::getCommand() {
	return command;
}

std::string Trigger::getTriggerAction() {
	return trigger_action;
}

void Trigger::addCondition(Condition* condition) {
	//conditions.push_back(condition);
	this->trig_cond = condition;
}

Object* Trigger::parseConditions(std::string object, std::string type) {
	//return conditions[0]->parseObjects(object, type);
	return trig_cond->parseObjects(object, type);
}

void Trigger::parseConditionsUpdate(std::string object, std::string status) {
	//conditions[0]->setObjStatus(status);
	trig_cond->setObjStatus(status);
}

void Trigger::parseConditionsDelete(std::string object) {
	//conditions[0]->parseObjectsDelete(object);
	trig_cond->parseObjectsDelete(object);
}
