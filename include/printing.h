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

//#include "./Player.hpp"

using namespace std;

void wait(const int& milliseconds) {
    std::chrono::milliseconds timespan(milliseconds);
    this_thread::sleep_for(timespan);
}

//template<typename T>
static void print(const string& textToPrint) {
    cout << "\n";
    for (char i : textToPrint) {
        std::cout << i;
        cout.flush();
        wait(50);
    }
    cout << "\n";
}

static void printSelection(const vector<string>& actions) {
    print("Select one of the following:");
    int i = 1;
    for(const string& action : actions) {
        printf("%-20s[%x]\n", action.c_str(), i);
        i++;
    }
}

static void printActionSelction() {
    printf("%-20s%-10s\n", "Move", "[0]");
    printf("%-20s%-10s\n", "Inventory", "[1]");
    printf("%-20s%-10s\n", "Exit", "[2]");
}

bool validInput(const int& input, const int& min, const int& max) {
    return (input<=max && input>=min);
}

int playerInput(const int& min, const int& max) {
    int input;
    while (std::cout << "\n>"  && !(std::cin >> input) || (input>max || input<min)) {
        std::cin.clear(); //clear bad input flag
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //discard input
        std::cout << "Invalid input; please re-enter.\n";
    }
   return input;
}




#endif //UNTITLED_PRINTING_H
