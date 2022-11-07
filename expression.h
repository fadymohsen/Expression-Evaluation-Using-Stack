#ifndef EXPRESSION_EVALUATION_USING_STACK_EXPRESSION_H
#define EXPRESSION_EVALUATION_USING_STACK_EXPRESSION_H
#include <iostream>
#include <string>
#include <stack>
using namespace std;




string Infix_TO_Postfix (string expression);

int weightOperator (char op);

bool is_right_associative (char op);

bool is_correct_operator(char op);

bool is_correct_operand(char c);

bool periority(char op1, char op2);



#endif //EXPRESSION_EVALUATION_USING_STACK_EXPRESSION_H
