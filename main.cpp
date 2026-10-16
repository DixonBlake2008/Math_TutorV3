/********************************************************************************************************************************************
 Program....: MathTutorV3
 Programmers: Blake Dixon and Connor Stolpe
 Date.......: 2026.10.12
 Section....: 2 or 10am
 GitHub Repo: https://github.com/DixonBlake2008/Math_TutorV3
 Description: An easy math tutor for young children. In version 2, it displays the program's intro, gets the user's full name,
              asks a random question, and then displays if they are correct and then ends the program.
********************************************************************************************************************************************/
#include <iostream> // for cout & cin
#include <windows.h> // for math symbols
#include <cstdlib> // for srand and rand
#include <ctime> // for time seeding
#include <string> // for string data types
#include <limits> // limits library
using namespace std;

int main() { // Initiate variables for user name and answer
    string name = "unknown"; // the user's name

    int tempNum = 0; // uses to swap two values

    int leftNum = 0; // the 1st random number between 1 and 10
    int rightNum = 0; // the 2nd random number between 1 and 10

    enum MathType {MT_ADD, MT_MINUS, MT_MULT, MT_DIV}; // random number [1=add, 2=sub, 3=multi, 4=div]
    MathType mathType = MT_ADD;
    char mathSym = '?'; // [+, -, *, /]

    const int MAX_ATTEMPTS = 3; // defines the amount of max amount of attempts before leveling down
    const int LEVEL_CHANGE = 10; // how much the level changes by at each level

    int totalCorrect = 0; // counts how many answers the users has gotten correct for level up
    int totalIncorrect = 0; // counts how many answers the users has gotten incorrect for level down
    int mathLevel = 1; // what level the Math Tutor is at
    int currentRange = LEVEL_CHANGE; // sets the base number range of level 1

    int userAnswer = 0; // the user's answer to the math question
    int correctAnswer = 0; // the correct answer

    string userInput; // user input variable for yes or no question

    srand(time(NULL));  // allows the program to generate random numbers
    SetConsoleOutputCP(CP_UTF8);  // allows the program to show math characters in quotes

    // ASCII art and math fun facts
    cout << "+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-" << endl;
    cout << R"(|   _       __     __                             __           __  ___      __  __       ______      __              |
|  | |     / /__  / /________  ____ ___  ___     / /_____     /  |/  /___ _/ /_/ /_     /_  __/_  __/ /_____  _____  |
|  | | /| / / _ \/ / ___/ __ \/ __ `__ \/ _ \   / __/ __ \   / /|_/ / __ `/ __/ __ \     / / / / / / __/ __ \/ ___/  |
|  | |/ |/ /  __/ / /__/ /_/ / / / / / /  __/  / /_/ /_/ /  / /  / / /_/ / /_/ / / /    / / / /_/ / /_/ /_/ / /      |
|  |__/|__/\___/_/\___/\____/_/ /_/ /_/\___/   \__/\____/  /_/  /_/\__,_/\__/_/ /_/    /_/  \__,_/\__/\____/_/       |)" << endl;
    cout << "+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-" << endl;
    cout << "|                                  Welcome to the Silly Simple Math Tutor version 2!                                 |" << endl;
    cout << "+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-" << endl;
    cout << endl;
    cout << "Here are some cool math jokes:" << endl;
    cout << "    * There's no limit to what math can do." << endl;
    cout << "    * Some people have some polar opinions about math." << endl;
    cout << "    * √(-1) 2³ ∑ π and it was yummy!" << endl;
    cout << "    * Are monsters good at math? Not unless you Count Dracula." << endl;
    cout << "    * Why should you never argue with a 90-degree angle? Because it's always right." << endl;
    cout << "+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-" << endl;


    // Get user's full name and welcomes them
    cout << endl;
    cout << "What is your name: ";
    getline (cin, name);
    cout << "Welcome " << name << " to the Silly Simple Math Tutor! Hope you are smart enough to completely get these very simple questions down." << endl;
    cout << endl;

    do {
        leftNum = rand() % currentRange + 1; // Generates random numbers between 1 and 10 for the left number
        rightNum = rand() % currentRange + 1; // Generates random numbers between 1 and 10 for the right number
        mathType = static_cast<MathType>(rand() % 4);

        // mathType = 5; // only for testing default block
        //  Converts mathType numbers into symbols
        switch (mathType) {
        case MT_ADD: // addition
            mathSym = '+';
            correctAnswer = leftNum + rightNum;
            break;

        case MT_MINUS: // subtraction
            mathSym = '-';
            if (leftNum < rightNum){ // avoiding negative numbers
                tempNum = leftNum;
                rightNum = leftNum;
                rightNum = tempNum;
            }
            correctAnswer = leftNum - rightNum;
            break;

        case MT_MULT: // multiply
            mathSym = '*';
            correctAnswer = leftNum * rightNum;
            break;

        case MT_DIV: //division
            mathSym = '/';
            leftNum *= rightNum; // avoids fractions
            correctAnswer = leftNum / rightNum;
            break;

        default: // for errors, should not happen
            cout << "Invalid Question Type: " << mathType << endl;
            cout << "Program ended with an Error -1." << endl;
            cout << "please report this to Brody or Blake, appreciate you reading this." << endl;

            return -1;
            break;
        }
        for (int i = 1; i <= MAX_ATTEMPTS; i++){ // sets 3 attempts for the questions
            // Puts the numbers together to make a question and tells the user what level they are on
            cout << "[Level [" << mathLevel << "] " << name << ", what does " << leftNum << " " << mathSym << " " << rightNum << " = ";

            //Loop until the user enters numeric data
            while (!(cin >> userAnswer)) {
                cin.clear(); // clear the cin error flag
                // need to include the limits library to use numeric_limits
                cin.ignore (numeric_limits<streamsize>::max(),'\n'); // ignore the max input, up to '\n'
                cout << "\tInvalid input!" << endl;
                cout << "\tPlease enter a number: ";
            }//end of get userAnswer while loop

            // tells user if they were correct and adds to the total correct value
            if (userAnswer == correctAnswer) {
                totalCorrect++;
                cout << correctAnswer << " was correct, great job!" << endl;
                break;
            }
            else { // tells users that they are incorrect
                if (i == MAX_ATTEMPTS) { // adds to the incorrect counter
                    totalIncorrect++;
                    cout << "That is incorrect, the correct answer was " << correctAnswer << endl;
                }
                else { // tells the user to try again
                    cout << "That is incorrect, you have " << (3 - i) << " trys left!" << endl;
                }
            }
        }

        if (totalCorrect = 3) {
            cout << "Congrats you've leveld up!" << endl;
            cout << endl;
            currentRange + levelRange;


        }
            getline(cin, userInput); // clearing the newline from the input buffer
            while (true){
                cout << "Do you want to continue? (Yes or No): "; // asks the user if they want another question
                getline(cin, userInput); // Grab's user input

                for (int i = 0; i < userInput.size(); i++){
                    userInput.at(i) = tolower(userInput.at(i)); // makes characters in input lowercase
                }
                if (userInput == "y" || userInput == "yes" || userInput == "n" || userInput == "no"){
                    break; // checks for yes or no inputs then leaves loop
                }
                else { // for invalid input
                    cout << "Please enter a valid input!" << endl;
                }
            }
    } while (userInput == "yes" || userInput == "y");
    // End of program
    cout << endl;
    cout << "This is the end of the current program" << endl;
    cout << "Math Tutor version 4 will release soon!" << endl;
    cout << "End of Program" << endl;
    return 0;
}