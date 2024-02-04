// Chapter 6 Exercise 24
// Written by Aaron Payne
// This program plays a game of rock, paper, scissors with the computer
// Last modification: 02/04/2024
// CodeBlocks 20.03
#include <iostream>
#include <string>
#include <random>

using namespace std;

random_device randomEngine;                     // Random Device Engine
uniform_int_distribution<int> randomInt(1,3);   // Generate Integer 1-3

/* Store the choices in an enum */
enum class Choice {
    Rock = 1, Paper, Scissors   // Start at 1
};

/* FUNCTIONS */

// Randomly generates an int for the CPU value and returns a Choice enum
Choice getCpuChoice() {
    return static_cast<Choice>(randomInt(randomEngine)); // Casts the integer into the Choice enum
}

// Gets an input character from the player and returns a Choice enum.
Choice getPlayerChoice() {
    char playerInputChar;
    Choice playerChoice;
    do{
        cout << "Choose (r)ock, (p)aper or (s)cissors." << endl;
        cin.get(playerInputChar);
        cin.ignore(100, '\n');
    }while (playerInputChar != 'r' && playerInputChar != 'p' && playerInputChar != 's' && playerInputChar != 'x');

    switch (playerInputChar) {
        case 'r' :
            playerChoice = Choice::Rock;
            break;
        case 'p' :
            playerChoice = Choice::Paper;
            break;
        case 's' :
            playerChoice = Choice::Scissors;
            break;
        }

    return playerChoice;
}

// Evaluates who wins the game based on player and cpu choices, builds and returns a string ready to display.
string gameLogic(Choice player, Choice cpu) {

    /* Text Strings to simplify changes to text Displayed to User */
    string playerText = "You chose: ",
           computerText = "CPU chose: ",
           rock = "rock\n",
           paper = "paper\n",
           scissors = "scissors\n",
           tie = "Tie Game!\n",
           lose = "CPU wins!\n",
           win = "You win!\n",
           result;

    /* Checks player's Choice and Computer's choice then builds an output string with result */
    switch(player) {

       case Choice::Rock :
        if (cpu == Choice::Rock)            // TIE
            result = playerText + rock +
                     computerText + rock +
                     tie;
        else if (cpu == Choice::Paper)      // LOSE
            result = playerText + rock +
                     computerText + paper +
                     lose;
        else //(cpu == Choice::Scissors)    // WIN
            result = playerText + rock +
                     computerText + scissors +
                     win;
        break;

       case Choice::Paper :
        if (cpu == Choice::Rock)            // WIN
            result = playerText + paper +
                     computerText + rock +
                     win;
        else if (cpu == Choice::Paper)      // TIE
            result = playerText + paper +
                     computerText + paper +
                     tie;
        else // (cpu == Choice::Scissors)   // LOSE
            result = playerText + paper +
                     computerText + scissors +
                     lose;
        break;

       case Choice::Scissors :
        if (cpu == Choice::Rock)            // TIE
            result = playerText + scissors +
                     computerText + rock +
                     tie;

        else if (cpu == Choice::Paper)      // WIN
            result = playerText + scissors +
                     computerText + paper +
                     win;

        else // (cpu == Choice::Scissors)   // LOSE
            result = playerText + scissors +
                     computerText + scissors +
                     lose;
        break; // Break for Scissors
           } // End Switch

        return result; // Returns the string built by the logic
}

int main()
{
    // Use Choice enum to declare and initialize values for cpu and player
    Choice  cpuChoice    =  getCpuChoice(),     // Randomly Generates a CPU value
            playerChoice =  getPlayerChoice();  // Asks for user input to create player value

    // Displays the choices and results of the game.
    cout << gameLogic(playerChoice, cpuChoice);

    return 0;
}
