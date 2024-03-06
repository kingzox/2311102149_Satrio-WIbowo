#include <iostream>
#include <iomanip>

using namespace std;

int main(){

    char op;
    float num1, num2;

    //it allows user to enter operator i.e.+,-,*,/
    cout<<"enter operator (+,-,*,/): ";
    cin>> op;

    //it allows user to enter the operatpr
    cout<<"enter two operands: ";
    cin>>num1>>num2;

    //switch statenent begins
    switch(op){
        //if user enter +
        case '+' :
        cout<<"Result: "<<num1+num2;
        break;

        //if user enter -
        case '-': 
        cout<<"Result: "<<num1-num2;
        break;

        //if user enter *
        case '*':
        cout<<"Result: "<<num1*num2;
        break;

        //if user enter /
        case '/':
        if(num2 !=0){
            cout<<"Result: "<<fixed<<setprecision(2)<<num1/num2;
        } else{
            cout<<"error! division by zero isn't allowed.";
        }
        break;
        
        //if operator is other than + - * /,
        //error massage will display
        default:
        cout<<"error! operator isn't corrcet";
        

    } //switch statement ends

    return 0;

}