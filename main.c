#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

typedef enum
{
    TOKEN_NUMBER,
    TOKEN_PLUS,
    TOKEN_MINUS,
    TOKEN_END
} TokenType;

typedef struct
{
    TokenType type;
    int value;
} Token;

Token *tokenize(const char *input)
{
    Token *tokens = malloc(256 * sizeof(Token));
    int pos = 0;

    while (*input)
    {
        if (isdigit((*input)))
        {
            tokens[pos].type = TOKEN_NUMBER;

            tokens[pos].value = strtol(input, (char **)&input, 10);
            pos++;
        }
        else if (*input == '+')
        {
            tokens[pos].type = TOKEN_PLUS;
            input++;
            pos++;
        }
        else
        {

            input++;
        }
    }

    tokens[pos].type = TOKEN_END;
    return tokens;
}

int parse(Token *tokens, int *result)
{
    int pos = 0;
    if (tokens[pos].type != TOKEN_NUMBER)
    {
        return 0;
    }

    *result = tokens[pos].value;
    pos++;

    while (tokens[pos].type != TOKEN_END)
    {
        if (tokens[pos].type == TOKEN_PLUS)
        {
            pos++;
            if (tokens[pos].type != TOKEN_NUMBER)
            {
                return 0;
            }
            *result += tokens[pos].value;
        }
        else if (tokens[pos].type == TOKEN_MINUS)
        {
            pos++;
            if (tokens[pos].type != TOKEN_NUMBER)
            {
                return 0;
            }
            *result -= tokens[pos].value;
        }
        else
        {
            return 0;
        }
        pos++;
    }
    return 1;
}


void generate_assembly(Token *tokens){
    int pos = 0;

    printf("LOAD %d\n", tokens[pos].value);
    pos++;
    while (tokens[pos].type != TOKEN_END){
        if (tokens[pos].type == TOKEN_END)
        {
            pos++;
            printf("ADD %d\n", tokens[pos].value);
        } else if (tokens[pos].type == TOKEN_MINUS){
            pos++;
            printf("SUB %d\n", tokens[pos].value);
        }
        pos++;
        
    }
}

int main(){

    char input[256];
    printf("Enter an arithmetic expression (e.g. 5 + 4 - 3 ): ");
    
    fgets(input, sizeof(input), stdin);

    size_t len = strlen(input);

    if (len > 0 && input[len - 1] == '\n'){
        input[len - 1] ='\0';
    }

    Token *tokens = tokenize(input);

    int result;

    if (parse(tokens, &result)){
        printf("Parsed result: %d\n", result);

        generate_assembly(tokens);
    }else {

        printf("Invalid Expression\n");
    }
    free(tokens);
    return 0;
}
