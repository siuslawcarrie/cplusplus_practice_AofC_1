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
#include <algorithm>

//**FUNCTION DECLARATIONS
void parseData(std::ifstream &in, std::vector<int> &mixed_chars);

int pull_digit(std::string s);//iterate through string and pull out 1st digit
void integer_sum(std::vector<int> &some_ints);//sum integers in vector
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

        int int_num = pull_digit(line);
        int_num*=10;
        std::reverse(line.begin(), line.end());
        int int_num_rev = pull_digit(line);
        int digits = int_num + int_num_rev;
        std::cout << "here is the number: " << digits << std::endl;
        mixed_chars.push_back(digits);
        integer_sum(mixed_chars);
    }//closing brace while loop
}//closing brace parseData

int pull_digit(std::string s) {
    int i = 0; //sets index
    while (i<s.size()){
        char character = s[i]; //puts content of index into variable character
        if (isdigit(character) ==
            true) {//looks at CONTENT of index (ex. 0 on first loop), is what's in index a digit?
            int num = std::stoi(&character);
            return num;
        } else {
            i++;
        }
    }//closing brace while loop
}//clsing brace pull digit

void integer_sum(std::vector<int> &some_ints) {//sum of integers
    int sum = 0;
    int i = 0;
    while(i<some_ints.size()){
        sum += some_ints[i];
        i++;
    }
    std::cout << "The sum of your numbers is: " << sum << std::endl;
}//closing brace integer sum



