#ifndef EVALUATOR_H
    #define EVALUATOR_H

    #include <string>
    #include <vector>
    using namespace std;

    struct EvaluatorResponse {
        int status;
        string printOutput;
    };

    EvaluatorResponse evaluate(vector<string> tokens);
#endif