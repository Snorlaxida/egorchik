#include "Premain.h"
#include "StrTeh.h"
#include "CargoCar.h"
#include "WorkersCar.h"

void ReadVector(vector<StrTeh*> transport)
{
	if (transport.empty()) {
		cout << "\nThe list is empty!\n";
	}
	cout << setfill('-') << setw(103) << ' ' << "\n| N | Transport Name | Transport speed | Trasport cost | Trasport kg of cargo | Number of passengers |\n";
	cout << setfill('-') << setw(103) << ' ' << "\n";
	for (int i = 0; i < transport.size(); i++)
	{
		transport[i]->show_info(i + 1);
		cout << setfill('-') << setw(103) << right << ' ' << "\n";
	}
}

template <typename T>
int getType(T& obj) {
	if (typeid(obj) == typeid(CargoCar))
		return 1;
	else return 2;
}

void Sort(vector<StrTeh*>& vec) {
	for (int i = 1; i < vec.size(); i++) {
		for (int j = i; j > 0 && strcmp(vec[j - 1]->getName(), vec[j]->getName()) > 0; j--) {
			StrTeh* tmp = vec[j - 1];
			vec[j - 1] = vec[j];
			vec[j] = tmp;
		}
	}
}

istream& operator>>(istream& s, vector<StrTeh*>& vec)
{
	int size = 0;
	int i = 0;
	int ptype;
	vec.clear();
	while (1)
	{
		s.read((char*)&ptype, sizeof(ptype));
		if (s.eof()) break;
		switch (ptype)
		{
		case 1:
			size = sizeof(CargoCar);
			vec.push_back(new CargoCar);
			break;
		case 2:
			size = sizeof(WorkersCar);
			vec.push_back(new WorkersCar);
			break;
		}
		s.read((char*)&(*vec[i]), size);
		i++;
	}
	return s;
}

ostream& operator<<(ostream& s, vector<StrTeh*>& vec)
{
	int size = 0;
	int ptype;
	for (int i = 0; i < vec.size(); i++) {
		ptype = getType(*vec[i]);
		s.write((char*)&ptype, sizeof(ptype));
		switch (ptype) {
		case 1:
			size = sizeof(CargoCar); break;
		case 2:
			size = sizeof(WorkersCar); break;
		}
		s.write((char*)&(*vec[i]), size);
	}
	return s;
}

int main()
{
	vector<StrTeh*> transport;
	ofstream ofs;
	ifstream ifs;
	int n, m = 0, i = 0, count = 0;
	int size = 0;
	while (1) {
		cout << "1 - Add transport.\n2 - Read transport.\n3 - Delete transport.\n4 - Add info to file.\n5 - Read the file.\n6 - Change trasport.\n7 - Search transport speed.\n8 - Sort transport.\n9 - Exit.\n";
		n = CheckInt(9);
		switch (n) {
		case 1: {
			cout << "\nHow many?\n";
			count = CheckInt(5);
			while (i < count)
			{
				cout << "\nWhat is the type of " << i + 1 << " transport(1 - CargoCar, 2 - WorkersCar)?\n";
				m = CheckInt(2);
				if (m == 1)
				{
					CargoCar* cc = new CargoCar;
					cc->input_info();
					transport.push_back(cc);
				}
				if (m == 2)
				{
					WorkersCar* wc = new WorkersCar;
					wc->input_info();
					transport.push_back(wc);
				}
				i++;
			}
			i = 0;
			cout << endl;
			break;
		}
		case 2: {
			ReadVector(transport);
			break;
		}
		case 3: {
			cout << "\nWhat is the of deleting u want?(1 - Delete all transport, 2 - Delete one transport)?\n";
			m = CheckInt(2);
			if (m == 1)
			{
				transport.clear();
				cout << "\nList succesfully deleted!\n";
			}
			if (m == 2)
			{
				ReadVector(transport);
				int f;
				cout << "\nEnter the number of transport you want to delete:\n ";
				f = CheckInt(transport.size());
				transport.erase(transport.begin() + f - 1);
				cout << "\nSuccesfully deleted!\n";
				ReadVector(transport);
			}
			break;
		}
		case 4: {
			ofs.open("Transport.txt", ios::binary);
			ofs << transport;
			ofs.close();
			break;
		}
		case 5: {
			ifs.open("Transport.txt", ios::binary);
			ifs >> transport;
			ifs.close();
			break;
		}
		case 6: {

			ReadVector(transport);
			int f;
			cout << "\nEnter the number of transport you want to change:\n ";
			f = CheckInt(transport.size());
			transport[f - 1]->input_info();
			cout << "\nSuccesfully changed!\n";
			ReadVector(transport);
			break;
		}
		
		case 7: {
			map <string, int> tofind;
			string name;
			for ( i = 0; i < transport.size(); i++)
			{
				tofind.insert(pair<string, int>(transport[i]->getName(), transport[i]->getSpeed()));
			}
			map<string, int>::iterator mapPtr;
			ReadVector(transport);
			
			cout << "Enter the name of transport u wanna show speed: ";
			cin >> name;
			mapPtr = tofind.find(name);
			if (mapPtr != tofind.end()) {
				cout << "Speed of this transport: " << mapPtr->second << endl;
				break;
			}
			else cout << "There is no transport with this name!\n";
			break;
		}
		case 8: {
			ReadVector(transport);
			Sort(transport);
			cout << "Sortiiiiing...." << endl;
			ReadVector(transport);
			break;
		}
		case 9: {
			cout << "\n\n\t-----EXIT-----\n\n\n";
			return 0;
		}
		}
	}
}