#include <stdio.h>
#include <ctype.h>

#define MAX_TOKEN_LENGTH 100

enum TokenType {
    KEYWORD,
    IDENTIFIER,
    LITERAL,
    OPERATOR,
    PUNCTUATION,
};

struct Token {
    enum TokenType type;
    char lexeme[MAX_TOKEN_LENGTH];
};

int is_keyword(char* lexeme) {
    // Define the list of keywords
    char* keywords[] = {"auto", "break", "case", "char", "const", "continue",
                        "default", "do", "double", "else", "enum", "extern",
                        "float", "for", "goto", "if", "int", "long",
                        "register", "return", "short", "signed", "sizeof", "static",
                        "struct", "switch", "typedef", "union", "unsigned", "void",
                        "volatile", "while"};

    int num_keywords = sizeof(keywords) / sizeof(char*);

    // Check if the lexeme is a keyword
    for(int i = 0; i < num_keywords; i++) {
        if (strcmp(lexeme, keywords[i]) == 0) {
            return 1;
        }
    }

    return 0;
}

int is_operator(char c) {
    // Define the list of operators
    char* operators = "+-*/%=<>&|^!~?:";
    return strchr(operators, c) != NULL;
}

int is_punctuation(char c) {
    // Define the list of punctuation marks
    char* punctuation = "(){}[];,";
    return strchr(punctuation, c) != NULL;
}

int is_literal(char* lexeme) {
    // Check if the lexeme is an integer or floating-point literal
    int num_digits = 0;
    int num_points = 0;
    int i = 0;

    if (lexeme[i] == '-' || lexeme[i] == '+') {
        i++;
    }

    while (isdigit(lexeme[i])) {
        num_digits++;
        i++;
    }

    if (lexeme[i] == '.') {
        i++;

        while (isdigit(lexeme[i])) {
            num_digits++;
            num_points++;
            i++;
        }
    }

    if (num_digits > 0 && num_points <= 1) {
        return 1;
    } else {
        return 0;
    }
}

struct Token* tokenize(char* program, int* num_tokens) {
    struct Token* tokens = malloc(sizeof(struct Token) * MAX_TOKEN_LENGTH);
    int index = 0;

    char lexeme[MAX_TOKEN_LENGTH];
    int lexeme_index = 0;

    int is_in_comment = 0;

    for (int i = 0; program[i] != '\0'; i++) {
        if (program[i] == '/' && program[i+1] == '/') {
            // Ignore single-line comments
            is_in_comment = 1;
            i++;
        } else if (program[i] == '/' && program[i+1] == '*') {
            // Ignore multi-line comments
            is_in_comment = 1;
            i++;
        } else if (program[i] == '*' && program[i+1] == '/') {
            is_in_comment = 0;
            i++;
        } else if (is_in_comment) {
            continue;
        } else if (isspace(program[i])) {
            // Ignore whitespace
            continue;
        } else if (is_operator(program[i])) {
            // Recognize operators
            if (lexeme_index

}
