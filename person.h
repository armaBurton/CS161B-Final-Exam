//struct for PersonType
#pragma once
#include <iostream>
#include <cstring>
#include <fstream>
#include <limits>
using namespace std;

const int MAX_CHAR = 101;

struct PersonType
{
	char name[MAX_CHAR];
	char citizenship[MAX_CHAR];
	int age;
};

//function prototypes
void greeting();
void populatePersons(PersonType list[], int& count, const char fileName[]);
void printPersons(const PersonType list[], int count);
void addCitizen(PersonType list[], int &count);
void readCstring(const char *prompt, char input[]);
void readInt(const char *prompt, int &num);
bool checkPosition(const int count, const int positiion);
void insertCitizen(PersonType list[], int &count, const PersonType person, int position);
void goodBye();

//add your function prototype here.
