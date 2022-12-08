//Bushra Ghanem Alzeghabi 2110066
//Bushra Abdulkhaleg Dajam 2110054
// Lab 8
#include <iostream>
#include<stack> 
#include<cstring>
using namespace std;
// getWeight Mothed
int getWeight(char ch) {
    switch (ch) {
    case '/':
    case '*': return 2;
    case '+':
    case '-': return 1;
    default: return 0;
    }
}

// infix2postfix Mothed
void infix2postfix(char *infix, char *postfix, int size)
{
 stack<char> s;
 int weight;
 int i = 0;
 int k = 0;
 char chars;
 
 while (i < size) {
    chars = infix[i];
    if (chars == '(') {
        s.push(chars);
        i++;
        continue;
    }
    if (chars == ')') {
        while (!s.empty() && s.top() != '(') {
            postfix[k++] = s.top();
            s.pop();
        }
        if (!s.empty()) {
            s.pop();
        }
        i++;
        continue;
    }
    weight = getWeight(chars);
    if (weight == 0) {
        postfix[k++] = chars;
    }
    else {
        if (s.empty()) {
            s.push(chars);
        }  
        else {
            while (!s.empty() && s.top() != '(' && weight <= getWeight(s.top())) {
                postfix[k++] = s.top();
                s.pop();
            }
            s.push(chars);
        }
    }
    i++;
 }
 while (!s.empty()) {
     postfix[k++] = s.top();
     s.pop();
    }
    postfix[k] = 0; // terminate the postfix expression.
}

// EvaluatePostfix Mothed
bool IsNumericDigit(char C)
{
    if (C >= '0' && C <= '9') return true;
    return false;
}

// IsOperator Mothed
bool IsOperator(char C)
{
    if (C == '+' || C == '-' || C == '*' || C == '/'){
        return true; 
    }
 
    return false;
}

// PerformOperation Mothed
int PerformOperation(char operation, int operand1, int operand2)
{
    if(operation == '+') return operand1 +operand2;
    else if(operation == '-') return operand1 - operand2;
    else if(operation == '*') return operand1 * operand2;
    else if(operation == '/') return operand1 / operand2;

    else cout<<"Unexpected Error \n";
    return -1;
}

// EvaluatePostfix Mothed
int EvaluatePostfix(string expression)
{
    stack<int> S;

    for(int i = 0;i< expression.length();i++) {

        if(expression[i] == ' ' || expression[i] == ',') continue;
        
        else if(IsOperator(expression[i])) {
            int operand2 = S.top(); S.pop();
            int operand1 = S.top(); S.pop();
            int result = PerformOperation(expression[i], operand1, operand2);
            S.push(result);
        }
        else if(IsNumericDigit(expression[i])){
            int operand = 0;
            while(i<expression.length() && IsNumericDigit(expression[i])) {
                operand = (operand*10) + (expression[i] - '0');
                i++;
            }
            
            i--;
            S.push(operand);
        }
    }
    return S.top();
}
int main()
{
    char *infix = new char[100];
    cout << ">>>>>>> convert infix to postfix <<<<<<<" << endl;
    cout << ">> enter the infix expression you wish to convert "<<endl;
    cout<<"type on one line "<<endl;
    cout<<"Example : 7 * 10 + 5 + 4 * 3 + 25 * 2"<<endl;
    cout<<"Please enter the infix expression : ";
    cin.getline(infix,100);
 
    int size = strlen(infix);
    char *postfix = new char[100];
    infix2postfix(infix, postfix, size);
    string expression = postfix;
    cout << "\nInfix Expression :: " << infix;
    cout << "\nPostfix Expression :: " << postfix;
    cout << "\nPostfix Is Evaluetd to : " << EvaluatePostfix(expression);
    cout << endl;
    return 0;
}