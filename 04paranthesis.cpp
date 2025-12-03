#include <iostream>
#include <string.h>
using namespace std;
int top = -1;

void push(char stack[],char c,int size) {
        if (top < size-1) {
            stack[++top] = c;
        } else {
            cout << "Stack Overflow in Stack 1\n";
        }
}
bool pop(char stack[], char c) {
    if (top < 0) {
        cout << "Stack Underflow\n";
        return false;
    }
    char last = stack[top--];   // take top element

    if ((last == '(' && c != ')') ||
        (last == '{' && c != '}') ||
        (last == '[' && c != ']')) {
        cout << "Mismatch found!" << endl;
        return false;
    }
    return true; // matched properly
}


int read(char stack[100],int size){
    for (int i = 0; i < size; i++)
    {   
        char brack = stack[i];
        if (brack == '(' || brack == '{' || brack == '[')
        {
            push(stack,brack,size);
        } else if (brack == ')' || brack == '}' || brack == ']')
        {
            if (!pop(stack,brack))
            {
                return 0;
            }
            
        }
    }
    if (top == -1)
    {
        return 1;
    } else {
        return 0;
    }
}

int main(){
    char stack[100];
    cout << "Enter the string : \n";
    cin >> stack;
    cout << read(stack,strlen(stack));
    return 0;
}