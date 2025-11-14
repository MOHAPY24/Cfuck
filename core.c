#include <stdio.h>
#include <string.h>
#include "tokens.c"


int tape[256] = {0};
int ip = 0;


int tokenize(char text[], Token tokens[]){
    unsigned int i = 0;
    int count = 0;

    while(text[i] != '\0'){
        if (text[i] == '+'){
            strcpy(tokens[count].Value, "+");
            strcpy(tokens[count].Type, "ADD_OPERAND");
            count++;
        }
        else if (text[i] == '-')
        {
            strcpy(tokens[count].Value, "-");
            strcpy(tokens[count].Type, "MINUS_OPERAND");
            count++;
        }
        else if (text[i] == '>')
        {
            strcpy(tokens[count].Value, ">");
            strcpy(tokens[count].Type, "NEXT");
            count++;
        }
        else if (text[i] == '<')
        {
            strcpy(tokens[count].Value, "<");
            strcpy(tokens[count].Type, "BACK");
            count++;
        }
        else if (text[i] == '.')
        {
            strcpy(tokens[count].Value, ".");
            strcpy(tokens[count].Type, "PRINT");
            count++;
        }
        else{
            printf("Invalid token: '%c'\n", text[i]);
            break;
        }
        i++;
    }
    return count;
}


const char* interpet(Token token){
    if (strcmp(token.Type, "ADD_OPERAND") == 0){
        tape[ip]++;
    }
    else if (strcmp(token.Type, "MINUS_OPERAND") == 0)
    {
        tape[ip]--;
    }
    else if (strcmp(token.Type, "NEXT") == 0)
    {
        ip++;
    }
    else if (strcmp(token.Type, "BACK") == 0)
    {
        ip--;
    }
    else if (strcmp(token.Type, "PRINT") == 0)
    {
        printf("%d\n", tape[ip]);
    }
    return "";
}

void run(char code[]){
    Token tokens[60];
    unsigned int count = tokenize(code, tokens);
    for (int i = 0; i < count; i++) {
        if (count < 0){
            break;
        }
        interpet(tokens[i]);
    }
}