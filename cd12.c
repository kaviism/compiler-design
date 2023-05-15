#include <stdio.h>
#include <ctype.h>

char input[100];
int pos = 0;
int error = 0;

void E();
void Eprime();
void T();
void Tprime();
void F();

int main() {
    printf("Enter the input string: ");
    fgets(input, 100, stdin);
    
    E();
    
    if (error == 0 && pos == strlen(input) - 1) {
        printf("The input string is valid!\n");
    } else {
        printf("The input string is not valid!\n");
    }
    
    return 0;
}

void E() {
    T();
    Eprime();
}

void Eprime() {
    if (input[pos] == '+') {
        pos++;
        T();
        Eprime();
    }
}

void T() {
    F();
    Tprime();
}

void Tprime() {
    if (input[pos] == '*') {
        pos++;
        F();
        Tprime();
    }
}

void F() {
    if (input[pos] == '(') {
        pos++;
        E();
        
        if (input[pos] == ')') {
            pos++;
        } else {
            error = 1;
        }
    } else if (isalnum(input[pos])) {
        pos++;
    } else {
        error = 1;
    }
}



