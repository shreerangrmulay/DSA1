#include <iostream>
#define MAX 100
using namespace std;

struct stack {
    int a[MAX];
    int top = -1;
};

int empty(struct stack *s) {
    return (s->top == -1);
}

void push(struct stack *s, int val) {
    s->top++;
    s->a[s->top] = val;
}

int pop(struct stack *s) {
    if(empty(s)) {
        cout << "Error: Stack Underflow!" << endl;
        return 0; // safe default
    }
    return s->a[s->top--];
}

int evaluatePostfix(char expr[]) {
    struct stack s;
    char token;
    int i = 0;

    while(expr[i] != '\0') {
        token = expr[i];

        // If digit, push to stack
        if(token >= '0' && token <= '9') {
            push(&s, token - '0');
        } else {
            // Pop two operands safely
            int operand2 = pop(&s);
            int operand1 = pop(&s);
            int result = 0;

            switch(token) {
                case '+': result = operand1 + operand2; break;
                case '-': result = operand1 - operand2; break;
                case '*': result = operand1 * operand2; break;
                case '/': 
                    if(operand2 == 0) {
                        cout << "Division by zero!" << endl;
                        return 0;
                    }
                    result = operand1 / operand2; 
                    break;
                case '%': result = operand1 % operand2; break;
                case '^': { 
                    result = 1;
                    for(int j = 0; j < operand2; j++)
                        result *= operand1;
                    break;
                }
                default:
                    cout << "Unknown operator: " << token << endl;
                    return 0;
            }
            push(&s, result);
        }
        i++;
    }

    if(s.top != 0) {
        cout << "Invalid postfix expression!" << endl;
        return 0;
    }

    return pop(&s);
}

int main() {
    char postfix[MAX];
    cout << "Enter postfix expression (single-digit operands, no spaces): ";
    cin >> postfix;

    int result = evaluatePostfix(postfix);
    cout << "Result: " << result << endl;

    return 0;
}
