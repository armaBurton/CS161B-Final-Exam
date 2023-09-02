//main driver file
//add header comments here.
#include "person.h"
const int CAPACITY = 20;

//function protoypes

//main and then functions.
int main()
{
	PersonType list[CAPACITY];
	int 	   count  = 0;
	char	   fileName[] = "persons.txt";

	greeting();
	populatePersons(list, count, fileName);
	printPersons(list, count);

	//call your functions here to do what is required.
	cout << endl;
	addCitizen(list, count);
	printPersons(list, count);
	return 0;
}


