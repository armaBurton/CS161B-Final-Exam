//implememtation file for struct PersonType
#include "person.h"

void greeting(){
    cout << "Welcome to my Citizen's Database.\n"
         << endl
         << "Here's your list so far:\n"
         << endl;
}

//function to read from file and populate list
void populatePersons(PersonType list[], int& count, const char fileName[])
{
    ifstream        inFile;
    char            name[MAX_CHAR];
    char            citizen[MAX_CHAR];
    int age = 0;

    inFile.open(fileName);
    if(!inFile)
    {
        cerr << "Fail to open " << fileName << " to populate inventory!" << endl;
        exit(1);
    }
    inFile >> name;
    while(!inFile.eof())
    {
        inFile >> citizen;
        inFile >> age;
        strcpy(list[count].name, name);
        strcpy(list[count].citizenship, citizen);
        list[count].age = age;
        count++;

        inFile >> name;
    }
    inFile.close();
}

//function to print list
void printPersons(const PersonType list[], int count)
{

    for(int index = 0; index < count; index++)
    {
        cout << list[index].name << ";" << list[index].citizenship;
        cout << ";" << list[index].age << endl;
    }
}

//add your function here
//add citizen to array in user designated position
//checks for valid age
//checks for correct position
void addCitizen(PersonType list[], int &count){
    char nameBuffer[MAX_CHAR], citizenshipBuffer[MAX_CHAR];
    int ageBuffer, positionBuffer;
    PersonType person;
    readCstring("Enter your name:", nameBuffer);
    readCstring("Enter your citizenship:", citizenshipBuffer);

    //check for valid age
    do{
        readInt("Enter your age:", ageBuffer);
        if(ageBuffer < 1 || ageBuffer > 115){
            cout << "You have entered an invalid age\n";
        }
    }while(ageBuffer < 1 || ageBuffer > 115);


    readInt("Enter position number:", positionBuffer);
    //Checkl for valid position
    if(checkPosition(count, positionBuffer)){
        strcpy(person.name, nameBuffer);
        strcpy(person.citizenship, citizenshipBuffer);
        person.age = ageBuffer;

        insertCitizen(list, count, person, positionBuffer);
        cout << endl	
		 << "After adding a person, the list is:\n"
		 << endl;
	    printPersons(list, count);
    } else {
        cout << endl
             << "Error! Invalid position.\n"
             << endl;
    }  
}

//input from user
void readCstring(const char *prompt, char input[]){
    cout << prompt << endl;
    cin.getline(input, MAX_CHAR, '\n');
}

//input from user with validation
void readInt(const char *prompt, int &num){
    int inputBuffer = 0;

    do {
        cout << prompt << endl;
        if(cin >> inputBuffer){
            if (inputBuffer < 0){
                cout << "Input must be a positive integer\n";\
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            } else {
                num = inputBuffer;
            }
        } else {
            cout << "User input failure\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }while (inputBuffer < 0 && !inputBuffer);
}

//check if the user entered position is valid
bool checkPosition(const int count, const int position){
    if (position > -1 && position <= count && count < 20){
        return true;
    } 
    return false;
}

//shifts the array one to the right from the user provided position
//and inserts new person into position
//increments count
void insertCitizen(PersonType list[], int &count, const PersonType person, int position){
    for (int i = count; i > position; i--){
        list[i] = list [i - 1];
    }
    list[position] = person;
    count++;
}


//salutations
void goodBye(){
    cout << endl
         << "Thank you for using my Citizen Database!!\n";
}
