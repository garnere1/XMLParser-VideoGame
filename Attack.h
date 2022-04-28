#pragma once
#include <string>
#include <vector>
#include "Condition.h"

class Attack{
private:
	//std::string attack_print;
	std::string action;
	//std::vector<Condition*> attack_conditions;

public:
	Attack();
	Condition* atk_cond;
	std::vector<std::string> actions;
	std::string attack_print;
	void setAttackPrint(std::string attack_print);
	void setAction(std::string action);
	void addAttackCondition(Condition* condition);

	std::string getAttackPrint();
	std::string getAction();
};

