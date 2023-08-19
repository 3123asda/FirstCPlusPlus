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


void studentInfo();

string ValueLetterOnly(std::string CheckLetter);
string RemExtSpa(string removeExtraSpace);
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
        StuInf.StuFirName = RemExtSpa(StuInf.StuFirName);
        ValueLetterOnly(StuInf.StuFirName);

        if(ValueLetterOnly(StuInf.StuFirName) == "Invalid Name"){

            cout << "Invalid input. Please enter a name containing only letters." << endl;
            
        }else{        

            while (true){
                cout << "\nMiddle name: ";

                getline(cin,StuInf.StuMidName);
                StuInf.StuMidName = RemExtSpa(StuInf.StuMidName);
                ValueLetterOnly(StuInf.StuMidName);

                if(ValueLetterOnly(StuInf.StuMidName) == "Invalid Name"){

                    cout << "Invalid input. Please enter a name containing only letters." << endl;
                    
                }else{
                    
                    while (true){
                        cout << "\nLast name: ";
                        getline(cin,StuInf.StuLasName);
                        StuInf.StuLasName = RemExtSpa(StuInf.StuLasName);
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


string RemExtSpa(string removeExtraSpace){

    auto end = unique(removeExtraSpace.begin(), removeExtraSpace.end(), 
                [](char l, char r){  
                    return isspace(l) && isspace(r) ;  
                }
    );
    
    string DoneRemovingExtraSpace = string (removeExtraSpace.begin(),end);

    //Trimming the font and end 
    if(isspace(DoneRemovingExtraSpace.front())){
        DoneRemovingExtraSpace.erase(DoneRemovingExtraSpace.begin());
    }
    if(isspace(DoneRemovingExtraSpace.back())){
        DoneRemovingExtraSpace.pop_back();
    }

    return DoneRemovingExtraSpace; 
}

string ValueLetterOnly(std::string CheckLetter) {

   if(CheckLetter.empty()){
        return "Invalid Name";
   }else{

        regex invalidName("[^a-zA-Z ]");

        try {

            if (regex_search(CheckLetter, invalidName)) {
                throw 1;
            } else {
                return CheckLetter;
            }

        } catch (...) {
            return "Invalid Name";
        }

    }

}

void ValueNumberOnly(){
        cout << "this function use for checking the input that only accept number";
}