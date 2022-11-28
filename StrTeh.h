#pragma once
#include "Premain.h"
class StrTeh
{
	char name[100];
	int speed;
	int cost;
public:
	virtual void input_info() {};
	virtual void show_info(int n) {};
	void setName();
	char* getName();
	void setSpeed();
	int getSpeed();
	void setCost();
	int getCost();
};

void StrTeh::setName()
{
	cout << "\n\t\tEnter the name of the transport:  ";
	cin >> name;
}
char* StrTeh::getName() { return name; }

void StrTeh::setSpeed()
{
	cout << "\n\t\tEnter the speed of the transport:  ";
	speed = CheckInt(500);
}
int StrTeh::getSpeed() { return speed; }

void StrTeh::setCost()
{
	cout << "\n\t\tEnter the cost of the transport:  ";
	cost = CheckInt(5000);
}
int StrTeh::getCost() { return cost; }