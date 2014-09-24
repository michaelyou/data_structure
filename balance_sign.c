#include "stack.h"

char correspond(char c);

int main()
{
    stack s;
    s = create_stack();

    char c;
    
    while((c = getchar()) != '#') {
        switch(c) {
            case '(': case '{': case '[':
                push(s,c);
                break;
            case ')': case ']': case '}':
                if(is_empty(s) == TRUE) {
                    printf("error!\n");
                    return -1;
                }
                else {
                    if(top(s) == correspond(c))
                        pop(s);
                    else {
                        printf("not match, error!\n");
                        return -1;
                    }
                }
                break;
        }
    }
    if(is_empty(s) == FALSE) 
        printf("the stack is not empty, error!\n");
    else 
        printf("success!\n");
    return 0;
}

char correspond(char c)
{
    switch(c) {
        case ')':
            return '(';
            break;
        case ']':
            return '[';
            break;
        case '}':
            return '{';
            break;
    }
}