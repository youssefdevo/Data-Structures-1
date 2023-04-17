/*  name : ahmed said - id : 20200017
 *  name : aya mohamed monir - id : 20200107
 *  name : shrouk ayman ali - id : 20200251
 *  name : youssef nasser - id : 20200674
 */
#include<iostream>
#include <string>
#include<vector>
using namespace std;
class StudentName {
private:
    // string attribute to store the name
    string name;
public:
    // default constructor to ask user to input the name.
    StudentName() {

        //ask user to input the name.
        cout << "Please enter your name: ";
        getline(cin, name);

        //counter to check how many spaces in the name
        int cnt = 0;

        // string to store last name
        string lastName;

        //check how many spaces in the name.
        for (int i = 0; i < name.size(); ++i) {
            if (name[i] == ' ') {
                cnt++;
                lastName = "";
                continue;
            }
            //store last name to add it if (the number of spaces < 2)
            lastName += name[i];
        }

        //add space before the last name.
        lastName = ' ' + lastName;

        // while loop to add last name
        while (cnt < 2) {
            name += lastName;
            cnt++;
        }
    }



    // parameterized constructor that takes the string as a parameter.

    StudentName(string nm) {

        // store parameter into the attribute
        name = nm;

        //counter to check how many spaces in the name
        int cnt = 0;

        // string to store last name
        string lastName;

        //check how many spaces in the name.
        for (int i = 0; i < name.size(); ++i) {
            if (name[i] == ' ') {
                cnt++;
                lastName = "";
                continue;
            }
            //store last name to add it if (the number of spaces < 2)
            lastName += name[i];
        }

        //add space before the last name.
        lastName = ' ' + lastName;

        // while loop to add last name
        while (cnt < 2) {
            name += lastName;
            cnt++;
        }

    }
    //The function to print the full name.
    void print() {

        // declare ord to print number before each name.
        cout << "\n1)";
        int ord = 2;
        for (char i : name) {
            if (i == ' ') {
                cout << '\n' << ord << ')';
                ord++;
                continue;
            }
            cout << i;
        }
        cout << '\n';
    }

    // The function to replace names that return boolean
    bool replace(int i, int j) {

        //declare vector that the name will be store in it
        vector<string> v;
        // declare string to store each name in it to push it into vector
        string s;
        for (char k : name) {
            if (k == ' ') {
                v.push_back(s);
                s = "";
                continue;
            }
            s += k;
        }
        v.push_back(s);
        //check if one of the two indices is out of range and return false.
        if (max(i, j) > v.size() || min(i, j) < 1)
            return false;

        // swapping names
        swap(v[i - 1], v[j - 1]);

        // store the name again into attribute name and return true.
        name = "";

        for (int k = 0; k < v.size(); ++k) {
            name += v[k];
            if (k < v.size() - 1)
                name += ' ';
        }
        return true;
    }
};

int main() {

    // 5 test cases to check on functions

    StudentName n1("hassan ali");
    n1.print();
    if (n1.replace(2, 1)) {
        n1.print();
        cout << " the replacement is valid\n";
    }
    else {
        n1.print();
        cout << " the replacement is not valid\n";
    }

    StudentName n2("Ahmed Said Maghawry");
    n2.print();
    if (n2.replace(1, 3)) {
        n2.print();
        cout << " the replacement is valid\n";
    }
    else {
        n2.print();
        cout << " the replacement is not valid\n";
    }

    StudentName n3("Said Ali");
    n3.print();
    if (n3.replace(1, 3)) {
        n3.print();
        cout << " the replacement is valid\n";
    }
    else {
        n3.print();
        cout << " the replacement is not valid\n";
    }

    StudentName n4("Mohammed Salah");
    n4.print();
    if (n4.replace(1, 4)) {
        n4.print();
        cout << " the replacement is valid\n";
    }
    else {
        n4.print();
        cout << " the replacement is not valid\n";
    }

    StudentName n5("Mahmoud");
    n5.print();
    if (n5.replace(4, 3)) {
        n5.print();
        cout << " the replacement is valid\n";
    }
    else {
        n5.print();
        cout << " the replacement is not valid\n";
    }
}