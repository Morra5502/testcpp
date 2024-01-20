#pragma once

#include <iostream>
#include <fstream>
#include <iostream>

using namespace std;

struct Bus
{
	Bus* next;
	int _busNumber, _raceNumber;
	string _FIO;
	Bus(int busNumber, int raceNumber, string FIO) :_busNumber(busNumber), _raceNumber(raceNumber), _FIO(FIO), next(nullptr) {}
};

struct List
{
	string listName;
	Bus* listTop;
	Bus* listBottom;
	List(string name) :listTop(nullptr), listBottom(nullptr), listName(name) {}
};

struct mainStruct
{
	mainStruct() {};

	List* _parkStr = new List("Park");
	List* _raceStr = new List("Race");
	Bus* currNode;
	Bus* prevNode;
public:
	bool printToFile(string& filename);
	void push(int busNumber, int raceNumber, string FIO, List* tempList);
	void push(Bus* newNode, List* tempList);
	void Swap(int busNumber);
	void printAll();
	bool isEmpty(List* tempList);

	bool isFound(int busNumber, List* tempList);

	Bus* pop(int busNumber, List* tempList);
	Bus* returnValue(Bus* tempStr, List* tempList);
	void print(List* tempList);
};