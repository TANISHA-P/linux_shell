#include "evaluator.h"
#include <iostream>
#include <vector>
#include <string>
#include <unistd.h>


string getPresentWorkingDirectory() {
    char* location = getcwd(NULL, 20);

    if (location == NULL) {
        return "Error getting current directory";
    }
    return string(location);
}

EvaluatorResponse evaluate(vector<string> tokens) {
    string printOutput = "";
    int status;

    if (tokens[0] == "PWD") {
        string currentPath = getPresentWorkingDirectory();
        cout<<currentPath<<endl;

        printOutput = currentPath;
        status = 200;
    }

    return EvaluatorResponse{status, printOutput};
}