 /*

от передаваемых в нее данных может печатать информацию как в файл, так и на консоль

*/

#include "Header.h"

int main()
{
	mainStruct* mainStr = new mainStruct;

	mainStr->push(1, 1, "SDM", mainStr->_parkStr);
	mainStr->push(2, 1, "DHR", mainStr->_parkStr);
	mainStr->push(3, 2, "BTD", mainStr->_parkStr);
	mainStr->push(4, 3, "KYF", mainStr->_parkStr);
	mainStr->push(5, 4, "XHR", mainStr->_parkStr);
	mainStr->push(6, 4, "ZXC", mainStr->_parkStr);

	while (true) {
		int whatToDo = 0, busNumber = 0, raceNumber = 0;
		cout << "Swap - 1, print - 2, push - 3 , exit - 4\n";

		cin.clear(); // ignore erroneous line of input:
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cin >> whatToDo;

		string FIO;
		string fileName;

		switch (whatToDo)
		{
		case(1):
			cout << "Enter Bus Number\n"; 

			cin.clear(); // ignore erroneous line of input:
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cin >> busNumber;
			if (busNumber == 0) {
				cout << "number cant be 0";
				break;
			}
			mainStr->Swap(busNumber);
			break;
		case(2):
			cout << "console(1) or file(2)? \n";

			cin.clear(); // ignore erroneous line of input:
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cin >> whatToDo;

			switch (whatToDo)
			{
			case(1):
				mainStr->printAll();
				break;
			case(2):

				cout << "enter file name \n";

				cin.clear(); // ignore erroneous line of input:
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cin >> fileName;

				if(mainStr->printToFile(fileName)) cout << "succesful input in " << fileName << endl;
				break;
			default:
				break;
			}
			break;
		case(3):

			cout << "Enter bus number, race number, FIO\n";
			cin >> busNumber;
			cin >> raceNumber;
			cin >> FIO;

			if (mainStr->isFound(busNumber, mainStr->_parkStr) || mainStr->isFound(busNumber, mainStr->_raceStr)) {
				cout << "bus with same number already exist\n";
			}
			else {
				mainStr->push(busNumber, raceNumber, FIO, mainStr->_parkStr);
				cout << busNumber  << " " << raceNumber  << " " << FIO << " is added to park" << endl;
			}
			break;

		case(4):
			return 0;
		default:
			return 0;
		}
	}
}