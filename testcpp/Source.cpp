#include "Header.h"

void mainStruct::push(int busNumber, int raceNumber, string FIO, List* tempList)
{
	Bus* newNode = new Bus(busNumber, raceNumber, FIO);
	if (isEmpty(tempList))
	{
		tempList->listTop = newNode;
		tempList->listBottom = newNode;
	}
	else
	{
		newNode->next = tempList->listBottom;
		tempList->listBottom = newNode;
	}
}

void mainStruct::push(Bus* newNode, List* tempList)
{
	if (isEmpty(tempList))
	{
		tempList->listTop = newNode;
		tempList->listBottom = newNode;
	}
	else
	{
		newNode->next = tempList->listBottom;
		tempList->listBottom = newNode;
	}
}

void mainStruct::Swap(int busNumber) {
	if (isFound(busNumber, _parkStr)) {
		push(pop(busNumber, _parkStr), _raceStr);
		cout << "bus # " << busNumber << " is leave the park\n";
	}
	else if (isFound(busNumber, _raceStr)) {
		push(pop(busNumber, _raceStr), _parkStr);
		cout << "bus # " << busNumber << " is enter the park\n";
	}
	else cout << "that bus is not exist\n"; 
}

void mainStruct::printAll() {
	print(_parkStr);
	print(_raceStr);
	cout << "-------------------------------------------------------------\n";
}

bool mainStruct::isEmpty(List* tempList)
{
	return tempList->listBottom == nullptr;
}

bool mainStruct::isFound(int busNumber, List* tempList) {
	currNode = tempList->listBottom;
	prevNode = nullptr;
	if (isEmpty(tempList)) return false;
	while (currNode->_busNumber != busNumber) {
		if (currNode->next == nullptr) {
			return false;
		}
		else {
			prevNode = currNode;
			currNode = currNode->next;
		}
	}
	return true;
}

Bus* mainStruct::pop(int busNumber, List* tempList)
{
	currNode = tempList->listBottom;
	prevNode = nullptr;
	if (isEmpty(tempList))throw exception();
	else if (isFound(busNumber, tempList)) {
		if (currNode == tempList->listBottom) {
			Bus* temp = tempList->listBottom->next;
			tempList->listBottom->next = nullptr;
			tempList->listBottom = temp;
		}
		else if (currNode == tempList->listTop) {
			if (prevNode != nullptr) {
				tempList->listTop = prevNode;
				tempList->listTop->next = nullptr;
			}
			else tempList->listTop = nullptr;
		}
		else { 
			prevNode->next = currNode->next; 
			currNode->next = nullptr;
		}
		return currNode;
	}
	else {
		return nullptr;
	}
}

Bus* mainStruct::returnValue(Bus* tempStr, List* tempList)
{
	if (tempStr->next != nullptr) returnValue(tempStr->next, tempList);
	//if (tempStr->_busNumber == tempList->listTop->_busNumber) return nullptr;
	return tempStr;
}

void mainStruct::print(List* tempList)
{
	if (isEmpty(tempList)) cout << tempList->listName << " is Empty\n";
	else {
		Bus* tempBus = returnValue(tempList->listBottom, tempList);
		cout << tempList->listName << endl;
		while (tempBus != nullptr) {
			printf("%d %d", tempBus->_busNumber, tempBus->_raceNumber);
			cout << " " << tempBus->_FIO << endl;
			tempBus = tempBus->next;
		} 
	}
}

bool mainStruct::printToFile(string& filename) {

	ofstream outputFile;
	outputFile.open(filename);

	if (!outputFile.is_open()) {
		cout << "Error open file" << endl;
		return false;
	}

	outputFile << _parkStr->listName << endl;
	if (!isEmpty(_parkStr)) {
		Bus* tempBus = returnValue(_parkStr->listBottom, _parkStr);
		while (tempBus != nullptr) {
			outputFile << tempBus->_busNumber << " " << tempBus->_raceNumber << " " << tempBus->_FIO << endl;
			tempBus = tempBus->next;
		}
	}

	outputFile << _raceStr->listName << endl;
	if (!isEmpty(_raceStr)) {
		Bus* tempBus = returnValue(_raceStr->listBottom, _raceStr);
		while (tempBus != nullptr) {
			outputFile << tempBus->_busNumber << " " << tempBus->_raceNumber << " " << tempBus->_FIO << endl;
			tempBus = tempBus->next;
		}
	}

	outputFile.close();
	return true;
}
