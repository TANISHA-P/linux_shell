#ifndef PARSER_H
    #define PARSER_H

    #include <string>
    #include <vector>

    using namespace std;

    struct ParseResponse {
        bool isValid;
        string errorMessage;
    };

    ParseResponse parse(vector<string> tokens);
#endif