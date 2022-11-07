#include <iostream>
#include <string>
#include <stack>
#include "expression.h"
using namespace std;





// MAIN FUNCTION --> Infix_TO_Postfix
string Infix_TO_Postfix (string expression){

    // Declaring a Stack For Holding the Operators
    stack <char> s;

    // Initialize an Empty String to put the Postfix Expression in it
    string postfix = "";


    // Scanning Each Character in the Expression
    for (unsigned int i=0; i<expression.length(); i++){
        if (expression[i]==' ' || expression[i]==',')   continue;        //Normal Text

            // If the Expression is not empty && the last element Not '(' && the Last Element (top) is higher periority
            // We will remove the top from the stack and add it into postfix and then add expression[i] in Stack
        else if (is_correct_operator(expression[i])){
            while (!s.empty()  &&  s.top()!='('   &&  periority(s.top(), expression[i])){   // It may be more than one
                postfix += s.top();
                s.pop();
            }
            s.push(expression[i]);

            // The Character is an Operand
        }else if (is_correct_operand(expression[i])){       // is Correct Operand
            postfix += expression[i];

        }else if (expression[i] == '('){                    // if '(' Entered we will pretend an virtual sub stack
            s.push(expression[i]);

        }else if (expression[i] == ')'){                    // if ')' Enetered we will remove all operators till '('
            while (!s.empty()   &&   s.top()!='('){
                postfix += s.top();
                s.pop();
            }
            s.pop();                                        // Will remove the closed bracket ')'
        }
    }


    // Removing the Remaining Operators
    while (!s.empty()){
        postfix += s.top();
        s.pop();
    }
    return postfix;
}


















// Weight Function: To Know The Periority of Operators
int weightOperator (char op){
    int weight=-1;
    if (op=='+' || op=='-'){
        weight = 1;
    }else if (op=='*' || op=='/'){
        weight = 2;
    }else if (op=='$'){
        weight = 3;
    }
    return weight;
}
// END WEIGHT KNOWN FUNCTION



// Start Is Right Associative Function
bool is_right_associative (char op){
    if (op=='$'){
        return true;
    }else{
        return false;
    }
}
// END Is Right Associative Function



// Start Is Correct Operator Function
bool is_correct_operator(char op){
    if (op=='+' || op=='-' || op=='*' || op=='/'){
        return true;
    }
    else {
        return false;
    }
}
// END Is Correct Operator Function



// Start Function to check the Alphanumeric characters
bool is_correct_operand(char c){
    if (c>='0' && c<='9')   return true;
    if (c>='a' && c<='z')   return true;
    if (c>='A' && c<='Z')   return true;
    return false;
}
// END check Alphanumeric Function



// Start Periority Function
bool periority(char op1, char op2){
    int op1Weight = weightOperator(op1);
    int op2Weight = weightOperator(op2);
    if (op1Weight == op2Weight)
        return true;
    return op1Weight > op2Weight ? true : false;
}

// END Periority Function