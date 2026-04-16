#include "lexer.h"
#include <iostream>
#include <sstream>
#include <vector>
#include <string>

using namespace std;


Token tokenize(string rawCommand) {
    
    stringstream ss(rawCommand);
    
    vector<string> tokens;
    string word;
    while (!ss.eof()) {
        getline(ss, word, ' ');
        tokens.push_back(word);
    }
    return Token{tokens, 200};
}