#pragma once
#include <string>
#include <vector>
#include "Condition.h"
#include "Object.h"

class Trigger{
private:
	std::string type;
	std::string command;
public:
	Trigger();
	//std::vector<Condition*> conditions;
	Condition* trig_cond;
	void setType(std::string type);
	std::string trigger_action;
	std::vector<std::string> trigger_actions;
	void setCommand(std::string command);
	void setPrint(std::string _print);
	void setTriggerAction(std::string trigger_action);
	void addAction(std::string _action);
	void addCondition(Condition* condition);
	void endTrigger();
	Object* parseConditions(std::string object, std::string type);
	void parseConditionsUpdate(std::string object, std::string status);
	void parseConditionsDelete(std::string object);

	std::string getType();
	std::string getCommand();
	std::string getTriggerAction();
};
