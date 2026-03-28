/**
 * @file ex61.cpp
 * @author Salar Farahmand
 * @brief 
 *          Topic: C++ Library > Sequential containers
 *          Reference: #61 of u04s02
 * @description
 * Write the C++ program that
         Reads the file
         Stores each line in a list
        Output
             On the head, if the string starts with a small letter
             On the tail, if the string starts with a capital letter
             The integers associated with the name must be
                stored in a vector
         If the same name (string) appears more than once
            in the file, the corresponding numbers must be
            inserted in the same vector of the same list
            element in any order
         Display the structure
    @proposed-output
        clara 3 30 27 28
        alfonso 5 19 23 26 12 19
        lara 2 28 27
        Maria 1 15
        Raffaela 2 24 25 

    NOTE: Please, remember to add the required configuration into .vscode/launch.json and args property as following:
        ...    
        "args": [
            "input.txt"
        ]
        ...
        Then press the play button on the ribbon or F5 to run the program.

    NOTE: I considered this input.txt as input file:
            alfonso 5 19 23 26 12 19
            lara 2 28 27
            clara 3 30 27 28
            Maria 1 15
            Raffaela 2 24 25
            clara 2 20 22
    Please, notice that I intentionally put "clara" twice in order to cover the problem specification completely.

 * @version 0.1
 * @date 2026-03-28
 * 
 * @copyright Copyright (c) 2026
 * 
 */


#include<iostream>
#include <fstream>
#include <string>
#include <list>
#include <vector>
#include<cctype>

using namespace std;

class DataEntry {
private:
string name;
vector<int> values;
public:
    DataEntry(string n, vector<int> v) {
        name = n;
        values = v;
    }
    ~DataEntry() {
    }

    // getters
    string getName() const {
        return name;
    }
    const vector<int>& getValues() const {
        return values;
    }
    // Method to add numbers to the existing vector
    void addNumbers(const vector<int>& newNumbers) {
        for (int val : newNumbers) {
            values.push_back(val);
        }
    }
    // Method to display the data as required
    void print() const {
        cout << name << ": <" << values.size() << ">";
        for (int val : values) {
            cout << " " << val;
        }
        cout << endl;
    }
};


int main(int argc, char** argv) {
    if (argc < 2) {
        cerr << "Error: Provide a filename." << endl;
    return 1;
    }
    ifstream inputFile(argv[1]);
    if (!inputFile.is_open()) {
        cerr << "Error: Could not open file." << endl;
        return 1;
    }
    list<DataEntry> sortedList;
    string currentName;
    int count;

    while (inputFile >> currentName >> count) {
        vector<int> tempValues;
        for (int i = 0; i < count; ++i) {
            int val;
            if (inputFile >> val) {
                tempValues.push_back(val);
            }    
        }


        // NOTE: Here, we are checking if the current name already exists in the list. 
        //      If it does, we add the new numbers to the existing vector (merging the data).
        bool found = false;
        for (list<DataEntry>::iterator it = sortedList.begin();
            it != sortedList.end(); ++it) {
            if (it->getName() == currentName) {
                it->addNumbers(tempValues); // if found, add the new numbers to the existing vector
                found = true;
                break;
            }
        }
        
        if (!found) { // if not found, create a new object and insert it into the list
            DataEntry newEntry(currentName, tempValues); // e.g. DataEntry("clara", {30, 27, 28})

            if (islower(currentName[0])) {
                sortedList.push_front(newEntry); // note: adding to the head of the list  | e.g. [{"name": "clara", "values": [30, 27, 28]}, ...]
            } else {
                sortedList.push_back(newEntry); // note: adding to end of the list
            }
        }

    } // end of while loop

    inputFile.close();
    for (list<DataEntry>::iterator it = sortedList.begin();
        it != sortedList.end(); ++it) {
        it->print();
    }

    return 0;
}