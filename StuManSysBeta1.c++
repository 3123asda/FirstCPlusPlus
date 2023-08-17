/*

    STUDENT MANAGEMENT SYSTEM


    Objective: Create a program that allow users to manage student records
               using various C++ consepts.


    Features to implement:

        1. Student Structure: 
            Define a structure named 'Student' with attributes
            like 'name', 'rollnumber', 'marks', and 'grade'

        2. Data Input: 
            Prompt the user to input data for multiple students, including
            their name, roll number, and marks. Store this information in 
            an array of Student structures.

        3. Calculate Grade: 
            Based on the marks entered, calculate the grade for each student 
            (e.g., A, B, C, D, F) using conditional statements.

        4. Display Students: 
            Create a function to display all student records, including their 
            name, roll number, marks, and grade.

        5. Search by Roll Number: 
            Implement a function that takes a roll number as input and displays 
            the details of the corresponding student.

        6. Modify Student Data: 
            Allow the user to modify the data of a student (name, roll number, marks).

        7. Delete Student Record: 
            Implement a function to delete a student record by roll number. 
            Use dynamic memory allocation and pointers to manage the array of students.

        8. Menu System: 
            Create a menu system using a loop and switch statements, allowing the user to 
            choose various options such as adding a new student, displaying student records, 
            searching, modifying, and deleting records. Use the break and continue statements 
            appropriately.


    Implementation:

        1. Use arrays for managing student records.
        2. Use a loop to repeatedly display the menu and execute options until the user 
           decides to exit.
        3. Utilize pointers and dynamic memory allocation to manage the array of students 
           effectively.
        4. Make use of conditional statements for calculating grades and handling menu options.
        5. Implement functions for different functionalities to keep your code organized and modular.                                                        

*/

/*

    All Code will start being written below this comment 

*/


#include <iostream>
#include <string>
#include <regex>
using namespace std;


void studentInfo(); //This function for student information

string ValueLetterOnly(std::string CheckLetter);
void ValueNumberOnly();

int main(){

    struct StudentManageSys{

        string StuFirName;
        string StuMidName;
        string StuLasName;

        string StuAdd;

        string StuBirYea;
        string StuBirMon;
        string StuBirDay;

        int StuAge;
    };
    
    StudentManageSys StuInf;
    StuInf.StuFirName;
    StuInf.StuMidName;
    StuInf.StuLasName;

    cout << "Student Management System" << "\n";

    while (true){
        cout << "First name: ";
        getline(cin,StuInf.StuFirName);
        ValueLetterOnly(StuInf.StuFirName);

        if(ValueLetterOnly(StuInf.StuFirName) == "Invalid Name"){

            cout << "Invalid input. Please enter a name containing only letters." << endl;
            
        }else{
            // string AllLetNam = ValueLetterOnly(StuInf.StuFirName);
            // cout << "Student First Name: " << AllLetNam;
            // return 0;
            while (true){
                cout << "\nMiddle name: ";
                getline(cin,StuInf.StuMidName);
                ValueLetterOnly(StuInf.StuMidName);
                if(ValueLetterOnly(StuInf.StuMidName) == "Invalid Name"){

                    cout << "Invalid input. Please enter a name containing only letters." << endl;
                }else{
                    cout << "\nLast name: ";
                    getline(cin,StuInf.StuLasName);
                    ValueLetterOnly(StuInf.StuLasName);

                    if (ValueLetterOnly(StuInf.StuLasName) == "Invalid Name") {
                        cout << "Invalid input. Please enter a name containing only letters." << endl;

                    }else{
                        string CompleteName = StuInf.StuLasName + ", " + StuInf.StuFirName + " " + StuInf.StuMidName;
                        cout << "Student Complete Name: " << CompleteName;
                        return 0;
                    }
                }
            }
        }
    }
}

void studentInfo(){
    struct{
        string StudentCompleteName;
        string StudentCompleteAddress;
        string StudentCompleteBirthday;
        int StudentAge;
        float StudentGeneralAverage;
    }StudentPersonalInfo;
}

/*
    ValueLetterOnly() function checks if a string contains 
    only letters and no invalid characters.
*/
string ValueLetterOnly(std::string CheckLetter) {

    /*
        Define a regular expression pattern that matches 
        any non-letter characters.

            Note: To allow spaces in a regular expression, include a space character " " 
            within the square brackets. In the regex pattern "[ ]", the space character 
            represents a literal space. This will enable the regex to match names that 
            contain letters and spaces.
            example:
                regex invalidName("[^a-zA-Z]");    -> This regex enable only to match letter's        
                reason:
                    it will accept only james not james christopher 

                regex invalidName("[^a-zA-Z ]");   -> Enable the regex to match names that contain letters and spaces.
                                           ^(Has Space)
                reason:
                    it will accept james christopher [Has space]                      
    */
    regex invalidName("[^a-zA-Z ]");

    /*
        Use a try-catch block to handle potential exceptions.
    */
    try {
        /*
            Check if the regular expression pattern 
            matches any part of the input string.
        */
        if (regex_search(CheckLetter, invalidName)) {
            /*
                If a match is found, throw an exception 
                (indicating invalid characters).
            */ 
            throw 1;
        } else {
            /*
                If no match is found, the string contains only letters and/or space.
                Return the input string as it is.
            */
            return CheckLetter;
        }
    } catch (...) {
        /*
            If an exception is caught (invalid characters), 
            return "Invalid Name".
        */ 
        return "Invalid Name";
    }
}

void ValueNumberOnly(){
        cout << "this function use for checking the input that only accept number";
}
