/*  name : ahmed said - id : 20200017
 *  name : aya mohamed mounir - id : 20200107
 *  name : shrouk ayman ali - id : 20200251
 *  name : youssef nasser - id : 20200674
 */
#include "matrix.h"
#include <iostream>
#include <iomanip>
//class matrix calculator to display menu of operations

class matrix_calculator {
private:
    int choice;

public:
    matrix_calculator() {
        choice = 0;
    }

    // function welcome accept parameter from matrix class type
    void welcome() {

        cout << "Welcome to our team matrix calculator\n ";
        cout << "------------------------\n\n";

        while (true) {

            //display the options
            cout << "1- Perform Matrix Addition\n";
            cout << "2- Perform Matrix Subtraction\n";
            cout << "3- Perform Matrix Multiplication\n";
            cout << "4- Matrix Transpose\n";
            cout << "Enter any other number to Exit\n";

            cin >> choice;//number of choice

            if (choice == 1) {
                matrix<int> mat1, mat2;
                cout << "Enter the first matrix\n";
                cin >> mat1;

                cout << "Enter the second matrix\n";
                cin >> mat2;

                //To add two matrices rows and columns are equal
                if (mat1.getrows() == mat2.getrows() && mat1.getcol() == mat2.getcol())
                    cout << "Answer of Addition :\n " << mat1 + mat2 << "\n";

                else
                    cout << "Error, You Should Enter Matrices with equal number of rows and columns\n";

            } else if (choice == 2) {
                matrix<int> mat1, mat2;
                cout << "Enter the first matrix\n";
                cin >> mat1;

                cout << "Enter the second matrix\n";
                cin >> mat2;


                //To subtract two matrices rows and columns are equal
                if (mat1.getrows() == mat2.getrows() && mat1.getcol() == mat2.getcol())

                    cout << "Answer of  Subtraction :\n" << mat1 - mat2 << "\n";

                else
                    cout << "Error, You Should Enter Matrices with equal number of rows and columns\n";

            } else if (choice == 3) {
                matrix<int> mat1, mat2;
                cout << "Enter the first matrix\n";
                cin >> mat1;

                cout << "Enter the second matrix\n";
                cin >> mat2;

                //n*m and m*p this rule of Multiplication (any numbers)
                if (mat1.getcol() == mat2.getrows())
                    cout << "Answer of Multiplication\n" << mat1 * mat2 << "\n";

                else
                    cout << "Error , number of columns first matrix not equal second matrix\n";

            }
            else if (choice == 4) {
                matrix<int> mat1;
                cout << "Enter the matrix\n";
                cin >> mat1;
                mat1.transpose();
                cout << "Matrix after transposed :\n" << mat1 << "\n";
            }
            else {
                cout << "Sorry, Invalid option try again...\n";
                break;
            }

        }

    }
};
int main() {
matrix_calculator test;
test.welcome();

}
