#include <iostream>
#include <string>
#include <stack>
#include "expression.h"
using namespace std;



int main() {
    cout<<Infix_TO_Postfix ("8/2+7-4*2")<<endl;                 // TEST_CASE_1
    cout<<Infix_TO_Postfix ("10*(2+1+5)/2-1")<<endl;            // TEST_CASE_1
    cout<<Infix_TO_Postfix ("2+((8+2*3)/2)-1")<<endl;           // TEST_CASE_1






    return 0;
}
