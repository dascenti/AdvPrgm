// Chapter 5 Exercise 14
// Written by Aaron Payne
// This program accepts a number of students and their names, sorts them alphabetically
// and outputs which student should be first and which should be last
// Last modification: 02/01/2024
// CodeBlocks 20.03

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    int numStudents;    //Total number of students

    // ASK user for number of students
    do {
        cout << "Enter the number of students: ";
        cin >> numStudents;
    }while(numStudents < 1 || numStudents > 25);

    string studentNames[numStudents];   // String Array with numStudents
    cin.ignore(100, '\n');              // Skip ahead in the input buffer 100 characters or until the first 'Enter'

    // ASK user for the name of each student
    for(int i = 0; i < numStudents; i++) {
        cout << "Enter the name of Student " << i + 1 << ": ";
        getline(cin, studentNames[i]);
    }

    //Sort the array of student names
    //int numberOfElements = sizeof(studentNames) / sizeof(studentNames[0]);
    sort(studentNames, studentNames + numStudents);


    //OUTPUT RESULT - FIRST and LAST Student
    cout << "First Student: " << studentNames[0] << endl;
    cout << "Last Student : " << studentNames[numStudents-1] << endl;


    /*
    // OUTPUTS ALL STUDENTS IN ALPHABETICAL ORDER
    cout << "Your Students Listed in order are: " << endl;
    for (int i = 0; i < numStudents; i++) {
        cout << studentNames[i] << endl;
    }
    */

    return 0;
}
