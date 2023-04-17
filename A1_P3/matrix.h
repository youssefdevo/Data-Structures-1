
/*  name : ahmed said - id : 20200017
 *  name : aya mohamed monir - id : 20200107
 *  name : shrouk ayman ali - id : 20200251
 *  name : youssef nasser - id : 20200674
 */
#ifndef Q_3_MATRIX_H
#define Q_3_MATRIX_H
#include <iostream>
#include <iomanip>
using namespace std;

template<class T>
class matrix {
private:
    T **mat;
    int rows;
    int colms;
public:
    //constuctor
    matrix() {}

    matrix(int Rows, int columns) {

        rows = Rows;
        colms = columns;

        mat = new T *[rows];
        for (int i = 0; i < rows; i++)
            mat[i] = new T[columns];

        //set initial values to zeros
        for (int i = 0; i < rows; ++i)
            for (int j = 0; j < colms; ++j)
                mat[i][j] = 0;
    }

//getters
    int getrows() {
        return rows;
    }

    int getcol() {
        return colms;
    }

//operator +
    matrix<T> operator+(matrix<T> &m) {
        //create object from class type
        //add the result of addition to the new object
        matrix<T> res(rows, colms);

        for (int i = 0; i < rows; ++i)
            for (int j = 0; j < colms; ++j)
                res.mat[i][j] = mat[i][j] + m.mat[i][j];

        return res;
    }

    matrix<T> operator-(matrix<T> &m) {
        //create object from class type
        //add the result of subtraction to the new object
        matrix<T> res(rows, colms);

        for (int i = 0; i < rows; ++i)
            for (int j = 0; j < colms; ++j)
                res.mat[i][j] = mat[i][j] - m.mat[i][j];

        return res;
    }

    matrix<T> operator*(matrix<T> &m) {
        //create object from class type
        //set initial values to zeros
        //loop must be verification the condition
        matrix<T> res(rows, m.colms);

        //n*m and m*p

        for (int i = 0; i < rows; ++i)
            for (int j = 0; j < m.colms; ++j)
                for (int k = 0; k < colms; ++k)
                    res.mat[i][j] += mat[i][k] * m.mat[k][j];

        return res;
    }

    matrix<T> &transpose() {

        matrix<T> NewMat(rows, colms);

        for (int i = 0; i < rows; ++i)
            for (int j = 0; j < colms; ++j)
                NewMat.mat[i][j] = mat[i][j];

        //delete current matrix
        for (int i = 0; i < rows; ++i)
            delete[]mat[i];
        delete[]mat;

        // create new matrix with new size
        mat = new T *[colms];
        for (int i = 0; i < colms; i++)
            mat[i] = new T[rows];

        //store data in the new matrix
        for (int i = 0; i < colms; ++i)
            for (int j = 0; j < rows; ++j)
                mat[i][j] = NewMat.mat[j][i];

        swap(rows, colms);

        return *this;
    }

    //operator to print the matrix
    friend ostream &operator<<(ostream &os, const matrix<T> &x) {
        for (int i = 0; i < x.rows; ++i) {
            for (int j = 0; j < x.colms; ++j) {
                os << x.mat[i][j] << ' ';
            }
            os << "\n";
        }
        os << "\n";
        return os;
    }

    //operator to enter number of rows and columns and matrix elements
    friend istream &operator>>(istream &is, matrix<T> &x) {
        cout << "Enter number of rows: ";
        is >> x.rows;

        cout << "Enter number of columns: ";
        is >> x.colms;

        //initialize new matrix
        x.mat = new T *[x.rows];
        for (int i = 0; i < x.rows; i++) {
            x.mat[i] = new T[x.colms];
        }
        cout << "Enter Your Matrix : \n";
        for (int i = 0; i < x.rows; ++i) {
            for (int j = 0; j < x.colms; ++j) {
                is >> x.mat[i][j];
            }
        }
        return is;
    }



//destructor
    ~matrix() {
        for (int i = 0; i < rows; ++i) {
            delete[]mat[i];
        }
        delete[]mat;
    }

};


#endif //Q_3_MATRIX_H
