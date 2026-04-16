#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>
#include "lexer.h"
#include "parser.h"
#include "evaluator.h"
using namespace std;


int main() {
    
    do {
        cout<<"shell> ";
        string command;
        getline(cin, command);
        if(command == "exit") {
            break;
        }

        try {
            // lexer
            Token tokens = tokenize(command);
            if (tokens.status != 200) {
                throw runtime_error("tokenization failed");
            }

            for(int i=0;i<tokens.tokens.size(); i++) {
                cout << tokens.tokens[i] << endl;
            }
            
            ParseResponse parseResult = parse(tokens.tokens);
            if (!parseResult.isValid) {
                throw runtime_error("parsing failed: " + parseResult.errorMessage);
            }

            EvaluatorResponse evalResult = evaluate(tokens.tokens);
            if (evalResult.status != 200) {
                throw runtime_error("evaluation failed");
            }

            cout<<"Yay we reached end";

        } catch (const exception& ex) {
            cerr << "Error: " << ex.what() << endl;
            continue;
        }

        cout<<"You entered: "<<command<<endl;

    } while(true);

    return 0;
}