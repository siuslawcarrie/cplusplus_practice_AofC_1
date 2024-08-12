/*C++ practice
summer 2024
Advent of Code 2023 #1
import strings of numbers and letters, take the first digit and the last digit (even if same) for each line,
then sum all lines 2 digit numbers together. */
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <ctype.h>
#include <stdio.h>
#include <cctype>
#include <vector>
#include <map>
#include <set>

//**FUNCTION DECLARATIONS
void parseData(std::ifstream &in, std::vector<int> &mixed_chars);

int main() {
//vector
    std::vector<int> mixed_chars;
//input file variables & open input file
    std::ifstream in;//open txt file //creates a cursor that points to the very beginnning of the txt file
    in.open("C:\\Users\\siusl\\CLionProjects\\Cplusplus_practice_AofC_1\\input.txt");
    //if file opens
    if (in.good()) {
        std::cout << "works";
        parseData(in, mixed_chars);
        //if text file won't open
    } else {
        std::cout << "Could not read file";
        return -1;
    }

    return 0;
}//closing brace, main

//**FUNCTION DEFINITIONS
void parseData(std::ifstream &in, std::vector<int> &mixed_chars) {//must be reference
    std::string line;//each line is placed into this variable
    while (!in.eof())//while not end of file
    {
        getline(in,
                line);//passing in the stream, and an empty string called line, puts the first line of the txt file into line
        bool running = true;
        int i = 0; //sets index
        while (running) {
            char character = line[i]; //puts content of index into variable character
            if (isdigit(character) ==
                true) {//looks at CONTENT of index (ex. 0 on first loop), is what's in index a digit?
                running = false;
                int int_num = std::stoi(&character);
                std::cout << "here is the number: " << character << std::endl;
                mixed_chars.push_back(int_num);
            }//closing brace if statement
            else if (i < line.size() - 1) {
                i++;
            } else {
                running = false;
            }

        }//closing brace for loop
    }//closing brace while not end of file
}//closing brace parseData



