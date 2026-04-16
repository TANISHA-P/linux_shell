#ifndef LEXER_H
    #define LEXER_H

    #include <string>
    #include <vector>

    using namespace std;

    struct Token {
        vector<string> tokens;
        int status;
    };

    Token tokenize(string rawCommand);

#endif
