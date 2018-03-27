#include <iostream>
#include <fstream>
using namespace std;
//Function prototypes
void lookup_name(ifstream&, string&, string&); //prototype
int main()
{
    //Declare variables
    ifstream myfile;
    string phoneNumber; //used to store phone number
    string first, last, fullName;
    char yesOrNo;
    do {
            first = " ";
            last = " ";
            phoneNumber = " ";
            //Prompts user to enter first name
            cout << "Enter first name: " << endl;
            cin >> first;
            //Prompts user to enter last name
            cout << "Enter last name: " << endl;
            cin >> last;
            //Concatenates first and last name with space in between
            fullName = first + " " + last;
            //call lookup_name function, passing the full name and phone number as parameters
            lookup_name(myfile, fullName, phoneNumber);
            //If the phone number is not found, "not found" message from function is printed
            if (phoneNumber == "Not found")
            {
                cout << phoneNumber << endl;
            }
            //If the phone number is found, the phone number is printed
            else
            {
                cout << "The telephone number you requested is " << phoneNumber << endl;
            }
            //Asks if the user wants to lookup another name
            cout << "Do you want to look up another name in the directory? (Y/N)" << endl;
            cin >> yesOrNo;
            myfile.close();
    } while (yesOrNo == 'Y'); //If 'Y' is entered, program continues, else, program breaks
    return 0;
}
//Void function to look up name and phone number from the file
void lookup_name(ifstream& myfile, string& fullName, string& phoneNumber)
{
    //Declare variables for first and last name in the file
    myfile.open("infile.txt");
    string firstName, lastName, name;
    //Takes in names from file
    myfile >> firstName >> lastName >> phoneNumber;
    //Concatenates name together with space
    name = firstName + " " + lastName;
    //While loop to run through file and find the name the user entered
    while(myfile)
    {
        //If the name the user enters matches the first name in the file, the phone number is returned
        if (name == fullName){
            return;
        }
        //If the name the user enters does not match, the second full name and phone number is searched
        else if (name!= fullName)
        {
            //Second name and phone number are taken in
            myfile >> firstName >> lastName >> phoneNumber;
            name = firstName + " " + lastName;
            //If the names match, the phone number is returned
            if (name == fullName)
            {
                return;
            }
            //If the entered name does not match the second name in the file, the third name and phone number are searched
            else if (name != fullName)
            {
                //Third name and phone number are taken in
                myfile >> firstName >> lastName >> phoneNumber;
                name = firstName + " " + lastName;
                //If the entered name matches the third name, the third phone number is returned
                if (name == fullName)
                {
                    return;
                }
                //If the entered name does not match, the fourth name and number are searched
                else if (name != fullName)
                {
                    //The fourth name and number are taken in
                    myfile >> firstName >> lastName >> phoneNumber;
                    name = firstName + " " + lastName;
                    //If the entered name matches the fourth name, then the fourth phone number is returned
                    if (name == fullName)
                    {
                        return;
                    }
                    //If the entered name does not match the fourth name, the fifth name and number are searched
                    else if (name != fullName)
                    {
                        //Fifth name and number are taken in
                        myfile >> firstName >> lastName >> phoneNumber;
                        name = firstName + " " + lastName;
                        //If the entered name matches the fifth name, the fifth number is returned
                        if (name == fullName)
                        {
                            return;
                        }
                        //If the name does not match, the string "not found" is returned, because the name is not in the directory.
                        else if (name != fullName)
                        {
                            phoneNumber = "Not found";
                        }
                    }
                }
            }
        }
    }
}

/*
Enter first name:
Harry
Enter last name:
Keeling
The telephone number you requested is (202)806-4830
Do you want to look up another name in the directory? (Y/N)
Y
Enter first name:
Frank
Enter last name:
James
The telephone number you requested is (301)123-3459
Do you want to look up another name in the directory? (Y/N)
Y
Enter first name:
Arthur
Enter last name:
Paul
The telephone number you requested is (202)865-9090
Do you want to look up another name in the directory? (Y/N)
Y
Enter first name:
Todd
Enter last name:
Shurn
The telephone number you requested is (410)560-8909
Do you want to look up another name in the directory? (Y/N)
Y
Enter first name:
Random
Enter last name:
Person
The telephone number you requested is (555)555-5555
Do you want to look up another name in the directory? (Y/N)
Y
Enter first name:
Alex
Enter last name:
Whitlow
Not found
Do you want to look up another name in the directory? (Y/N)
N

Process returned 0 (0x0)   execution time : 29.562 s
Press any key to continue.
*/
