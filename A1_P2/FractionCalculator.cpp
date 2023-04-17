#include "Fraction.h"
#include "FractionCalculator.h"
using namespace std;
FractionCalculator::FractionCalculator() {}

void FractionCalculator::perform(){
    string ch;
    Fraction fraction, fraction1;
    cout<<"enter your first number \n";
    cin >> fraction ;
    cout<<"enter your second number \n";
    cin>> fraction1;
    cout << "choose operation(+, -, *, /, > ,< ,= ,>= ,<= ) \n";
    cin >> ch;
    if (ch == "*")
        cout << fraction*fraction1;

    if (ch == "+")
        cout << fraction+fraction1;

    if (ch == "-")
        cout << fraction-fraction1;

    if (ch == "=") {
        if (fraction==fraction1)
            cout<<fraction<<" is equal "<<fraction1<<endl;
    }
    if (ch == "/")
        cout << fraction/fraction1;

    if (ch == ">"){
        if (fraction>fraction1)
            cout<<fraction<<"is greater than "<<fraction1;
        else
            cout<<fraction1<<"is greater than"<<fraction;
    }
    if (ch == ">="){
        if (fraction>=fraction1)
            cout<<fraction<<"is greater than or equal "<<fraction1;
        else
            cout<<fraction1<<"is greater than or equal "<<fraction;

    }
    if(ch=="<") {
        if (fraction<fraction1)
            cout<<fraction<<" is less than "<<fraction1;
        else
            cout<<fraction1<<"is less than "<<fraction;
    }
    if(ch=="<=") {
        if (fraction<=fraction1)
            cout<<fraction<<"is less than or equal "<<fraction1;
        else
            cout<<fraction1<<"is less than or equal "<<fraction;
    }


}
