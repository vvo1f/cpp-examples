/**
 * @file ex22.cpp
 * @author Salar Farahmand
 * @brief 
 *          Topic: C++ Library > Associative Containers
 *          Reference: #22 of u04s03
 * @description
 * Write a C++ program that reads a paragraph of
        text (a line of text) from the user
             Tokenize the input paragraph into words
             Ignore punctuation, consider only alphabetic
                characters, and transform characters in lowercase
             Create a map in which
                 Words (in the text) are keys
                 Values are frequencies (of that word in the text)
             Display the list of unique words and their
                frequencies alphabetically
             Find and display the total number of unique words
                in the paragraph
             Prompt the user to enter a word and then search
                the map to display the frequency of that word
             Create a set containing the unique words from the
                paragraph
             Display the unique words in the set sorted
                alphabetically

    @proposed-output
        Unique words and their frequencies:
        a: 2
        example: 1
        has: 1
        is: 2
        ...

        Total number of unique words: 10
        Enter a word: is

        is appears 2 times
        Unique words sorted alphabetically:
        a
        example
        has
        ...

    @proposed-input
        This is a simple example. This is a paragraph. It has some words.



 * @version 0.1
 * @date 2026-03-29
 * 
 * @copyright Copyright (c) 2026
 * 
 */


#include<iostream>
//#include <fstream> // option#2: Reading a file
#include <sstream>
#include <string>
#include <list>
#include <vector>

#include <set>
#include <map>

using namespace std;



int main(int argc, char** argv) {
    // option#2: Reading a file
    // if (argc < 2) {
    //     cerr << "Error: Provide a filename." << endl;
    // return 1;
    // }
    // ifstream inputFile(argv[1]);
    // if (!inputFile.is_open()) {
    //     cerr << "Error: Could not open file." << endl;
    //     return 1;
    // }

    string paragraph;
    string word;
    set<string> words; // note: Sets store the unique values in *sorted* order by default.
    map<string, int> freq_map; // note: Maps store key-value pairs, where `keys` are unique and `values` can be duplicated. 
                                    //  The `keys` are stored in *sorted* order by default.

    // Read a paragraph
    cout << "Enter a paragraph of text: ";
    getline(cin, paragraph);

    std::stringstream ss(paragraph);

    while (ss >> word) {
        // Remove punctuation and convert to lowercase
        std::string clean_word;
        for (char c : word) {
            if (std::isalpha(c)) {
                clean_word += std::tolower(c);
            }
        }
        words.insert(clean_word);
        freq_map[clean_word]++;
    }

    // Display unique words and their frequencies
    std::cout << "\nUnique words and their frequencies:\n";
    for (const auto &pair: freq_map) {
        std::cout << pair.first << ": " << pair.second << std::endl;        
    }

    std::cout << "\nTotal number of unique words: " << words.size() << std::endl;

    cout << "~\nEnter a word: ";
    cin >> word;
    cout << word << "appears " << freq_map[word] << " times.\n";

    std::cout << "\nUnique words sorted alphabetically:\n";
    for (const std::string &word : words) {
        std::cout << word << std::endl;
    }

    return 0;
}