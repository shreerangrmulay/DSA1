#include <iostream>
#define max 100
using namespace std;

struct stack{
    char a[max];
    int top = -1;
};

char top(struct stack *s){
    return s->a[s->top];
}

int priority(char OP){
    if(OP == '+' || OP == '-')
        return 1;
    else if(OP == '/' || OP == '*')
        return 2;
    else if(OP == '^' || OP == '%')
        return 3;
    else    
        return 0;
}

char pop(struct stack *s){
    char ch;
    ch = s -> a[s -> top];
    s -> top = s -> top - 1;
    return ch;
}

void push(struct stack *s, char ch){
    s -> top = s -> top + 1;
    s -> a[s -> top] = ch;
}

int empty(struct stack *s){
    if (s -> top == -1)
        return 1;
    else 
        return 0;    
}

void InftoPost(char Inf[], char Post[]){
    struct stack s;
    char ch,token;
    int i = 0, j = 0;
    for (int i = 0; Inf[i] != '\0'; i++)
    {
        token = Inf[i];
        if (isalnum(token))
        {
            Post[j++] = token;
        } else if(token == '('){
            push(&s,token);
        } else if(token == ')'){
            while ((ch = pop(&s)) != '(')
                Post[j++] = ch;
        } else {
            while (priority(top(&s)) >= priority(token) && !empty(&s))
            {
                Post[j++] = pop(&s);
            }
            push(&s,token);
        }
    }
    while(!empty(&s))
        Post[j++] = pop(&s);
        Post[j] = '\0';
    cout << "Postfix : " << Post << endl;;
}

int main(){
    char infix[max], postfix[max];
    cout << "Enter Infix expression : ";
    cin >> infix;
    InftoPost(infix,postfix);
    return 0;
} 