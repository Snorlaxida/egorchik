#pragma once
#include "Premain.h"
#include "StrTeh.h"

class CargoCar: public StrTeh
{
	int ckg;
public:
	void setCkg();
	int getCkg();
	void input_info()
	{
		this->setName();
		this->setSpeed();
		this->setCost();
		this->setCkg();
	}
	void show_info(int n)
	{
		cout << "|" << " " << n << " " << "|" << " " << setfill(' ') << left << setw(15) << this->getName() << '|' << " " << left << setw(16) << this->getSpeed() << '|' << " " << left << setw(14) << this->getCost()
			<< '|' << " " << left << setw(21) << this->getCkg() << '|' << " " << left << setw(21) << "-" << '|' << "\n";
	}
};

void CargoCar::setCkg()
{
	cout << "\n\t\tEnter the kg of cargo of the transport:  ";
	cin >> ckg;
}
int CargoCar::getCkg() { return ckg; }
