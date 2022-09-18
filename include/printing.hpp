//
// Created by lorenz on 21.04.22.
//

#ifndef UNTITLED_PRINTING_H
#define UNTITLED_PRINTING_H
#include <iostream>
#include <iomanip>
#include <chrono>
#include <thread>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <windows.h>

//#include "./Player.hpp"

using namespace std;

inline void wait(const int& milliseconds) {
    std::chrono::milliseconds timespan(milliseconds);
    this_thread::sleep_for(timespan);
}

inline void changeColour(int colour) {
    HANDLE hConsole;

    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, colour);
}

// Prints out Stuff and can specify colour of printed Text + speed
inline static void print(const string& textToPrint, const int& colour=15, const int& speed=25) {
    cout << "\n";
    changeColour(colour);
    for (char i : textToPrint) {
        std::cout << i;
        cout.flush();
#ifndef DEBUG
        wait(speed);
#endif
    }
    changeColour(15);  // Set Colour back to default white
    cout << "\n";
}

inline static void printSelection(const vector<string>& actions) {
    print("Select one of the following:");
    int i = 1;
    for(const string& action : actions) {
        printf("%-20s[%x]\n", action.c_str(), i);
        i++;
    }
}

inline int playerInput(const int& min, const int& max) {
    int input;
    while (std::cout << "\n>"  && !(std::cin >> input) || (input>max || input<min)) {
        std::cin.clear(); //clear bad input flag
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //discard input
        std::cout << "Invalid input; please re-enter.\n";
    }
   return input;
}
#endif //UNTITLED_PRINTING_H
