#pragma once
#include "Premain.h"
#include "StrTeh.h"

class WorkersCar : public StrTeh
{
	int pass;

public:
	void setPass();
	int getPass();
	void input_info()
	{
		this->setName();
		this->setSpeed();
		this->setCost();
		this->setPass();
	}
	void show_info(int n)
	{
		cout << "|" << " " << n << " " << "|" << " " << setfill(' ') << left << setw(15) << this->getName() << '|' << " " << left << setw(16) << this->getSpeed() << '|' << " " << left << setw(14) << this->getCost()
			<< '|' << " " << left << setw(21) << "-" << '|' << " " << left << setw(21) << this->getPass() << '|' << "\n";
	}
};

void WorkersCar::setPass()
{
	cout << "\n\t\tEnter the number of passengers of the transport:  ";
	cin >> pass;
}
int WorkersCar::getPass() { return pass; }
