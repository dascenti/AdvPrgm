// Chapter 7 Exercise 19
// Written by Aaron Payne
// This program simulates a magic 8 ball
// Last modification: 02/04/2024
// CodeBlocks 20.03
#include <iostream>
#include <fstream>
#include <random>

using namespace std;

// Global Variables
const int NUM_PREDICTIONS = 12;                                 // Number of prediction lines in the file
random_device randomEngine;                                     // Random Device Engine
uniform_int_distribution<int> randomInt(0,NUM_PREDICTIONS-1);   // Generate Integer 0-11

// Function Headers
void processFile(string[]);

int main()
{
    string prediction[NUM_PREDICTIONS]; // Array to store each line as a predicition
    string question;                    // Store user's last question
    char exit;                          // Char to read to exit game

    // Reads the file and stores each line as a separate value in the provided array
    processFile(prediction);

    do {
        // Prompt user to input a question
        cout << "Ask a Yes or No Question: " << endl;
        getline(cin, question);

        // Randomly selects an element of the prediction array and displays the value
        cout << prediction[randomInt(randomEngine)] << endl;

        // Repeat program until user is ready to quit
        cout << "Would you like to ask another question? (y/n)? ";
        cin.get(exit);
        cin.ignore(100, '\n');
    }
    while(exit != 'n' && exit != 'N');

    return 0;
}


// Given an array, reads the 8 ball text file and assigns each line
// To an element in the array
void processFile(string text[]) {
    ifstream inputFile;
    inputFile.open("8_ball_responses.txt");
    for(int i = 0; i < NUM_PREDICTIONS; i++) {
        getline(inputFile, text[i]);
    }
    inputFile.close();
}
