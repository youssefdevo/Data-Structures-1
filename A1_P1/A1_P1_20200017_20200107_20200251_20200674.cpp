/*  name : ahmed said - id : 20200017
 *  name : aya mohamed mounir - id : 20200107
 *  name : shrouk ayman ali - id : 20200251
 *  name : youssef nasser - id : 20200674
 */
#include <iostream>
#include <string>
using namespace std;
class BigInt {
private:
    string num;
    bool neg = false;
public:

    // constructor with string as a parameter
    BigInt(string decStr) {
        //number of digits in string
        long long n = decStr.size();
        //know if the number is negative or not and store the result
        if (decStr[0] == '-')
            neg = true;
        //removing zero's from the beginning of the number
        bool zero = false;
        for (int i = 0; i < n; ++i) {
            if (decStr[i] == '0' && zero)
                num.push_back(decStr[i]);

            else if (isdigit(decStr[i]) && decStr[i] != '0') {
                num.push_back(decStr[i]);
                zero = true;
            }
        }
        // if all number is zero's.
        if (!zero)
            num.push_back('0');
    }

    // constructor with integer as a parameter
    BigInt(int decInt) {

        //check negative number
        if (decInt < 0) {
            neg = true;
            decInt *= -1;
        }
        // check number equal to zero
        if (decInt == 0) {
            num = '0';
        }
        //store the number in string
        while (decInt) {
            num = to_string(decInt % 10) + num;
            decInt /= 10;
        }
    }
    //bool operator to comparison between two objects
    bool operator>(BigInt &s) {
        int n = this->size(), m = s.size();
        if (n > m)
            return true;
        else if (n < m)
            return false;
        else {
            for (int i = 0; i < n; ++i) {
                if (num[i] < s.num[i])
                    return false;
            }
        }
        return true;
    }

// + operator
    BigInt operator+(BigInt &anotherDec) {
        // declare object to return
        BigInt temp("");
        string a,b,res="";
        //store biggest number in string a, and smallest in string b
        if (*this > anotherDec) {
            a = num;
            b = anotherDec.num;
        } else {
            a = anotherDec.num;
            b = num;
        }
        /*
          a = 123456
          b = 56
          b->>000056
         */
        int  k = a.size()-b.size();
        while (k--)
            b = '0' + b;
        // if any number is negative
        if ((anotherDec.neg || neg) && (!(anotherDec.neg && neg))) {

            for (int i = a.size()-1; i >= 0; --i) {
                if (a[i] < b[i]) {
                    // if (a[i] < b[i]) i will borrow 1 from the previous digit
                    res += to_string(10 - ((b[i] - '0') - (a[i] - '0')));
                    // if the previous == zero it will = 9 and borrow 1 from the previous digit and so on.
                    for (int j = i - 1; j >= 0; --j) {
                        if (a[j] == '0')
                            a[j] = '9';
                        else {
                            a[j] -= 1;
                            break;
                        }
                    }
                } else
                    res += to_string((a[i] - '0') - (b[i] - '0'));
            }
            //removing zero's from the beginning of the number
            bool zer = false;
            temp.num = "";
            for (int i = res.size() - 1; i > 0; --i) {
                if (res[i] == '0' && zer)
                    temp.num.push_back(res[i]);
                else if (res[i] != '0') {
                    temp.num.push_back(res[i]);
                    zer = true;
                }
            }
            // if number = zero
            temp.num.push_back(res[0]);
            // if abs(negative number) > positive number, the result will be negative.
            if ((neg && (*this > anotherDec)) || (anotherDec.neg && (anotherDec > *this)) && temp.num != "0")
                temp.neg = true;
        }

            // if both numbers are positive or negative
        else {
            int ans;
            for (int i = 0; i < a.size(); ++i) {
                ans = (a[i] - '0' + b[i] - '0');
                // if ans>=10 we will add 1 to previous digit
                if (ans >= 10 && i > 0) {
                    bool ok = false;
                    res += to_string(ans % 10);
                    // if the previous == 9 it will = 0, and add 1 to the previous digit and so on.
                    for (int j = res.size() - 2; j >= 0; --j) {
                        if (res[j] == '9')
                            res[j] = '0';
                        else {
                            res[j] += 1;
                            ok = true;
                            break;
                        }
                    }
                    //if all previous digits == 9  we will add 1 to the beginning of the result.
                    if (!ok)
                        res = '1' + res;
                }
                    //if i = 0 and res>=10  we will add ans to the beginning of the result.
                else if (ans >= 10 && i == 0)
                    res += to_string(ans);
                else
                    res += to_string(ans % 10);
            }
            // if both numbers are negative the result will be negative number
            if (anotherDec.neg && neg)
                temp.neg = true;
            temp.num=res;
        }
        return temp;
    }
    // = operator
    void operator=(BigInt anotherDec) {
        num = anotherDec.num;
        neg = anotherDec.neg;
    }
    // get the size of the num string
    int size() {
        return num.size();
    }
    // ostream to print the number
    friend ostream &operator<<(ostream &out, BigInt b) {
        if (b.neg)
            out << '-';
        out << b.num << endl;
        return out;
    }
};
int main() {

    cout << "1#\n";

    BigInt num1("123456789012345678901234567890");
    BigInt num2("113456789011345678901134567890");
    BigInt num3 = num1 + num2;
    cout << "num1 = " << num1 << endl;
    cout << "num2 = " << num2 << endl;
    cout << "num1 + num2 = " << num3 << endl;

    cout << "2#\n";

    BigInt num4("100000000005486521454");
    BigInt num5("-9999999999999");
    BigInt num6 = num4 + num5;
    cout << "num4 = " << num4 << endl;
    cout << "num5 = " << num5 << endl;
    cout << "num4 + num5 = " << num6 << endl;

    cout << "3#\n";

    BigInt num7("78945132458121856645646");
    BigInt num8("-78945132458121856645646");
    BigInt num9 = num7 + num8;
    cout << "num7 = " << num7 << endl;
    cout << "num8 = " << num8 << endl;
    cout << "num7 + num8 = " << num9 << endl;

    cout << "4#\n";

    BigInt num10("-987654321654789753159");
    BigInt num11("-987654321654789753159");
    BigInt num12 = num10 + num11;
    cout << "num10 = " << num10 << endl;
    cout << "num11 = " << num11 << endl;
    cout << "num10 + num11 = " << num12 << endl;

    cout << "5#\n";
    BigInt num13("1597753123456789456123789154687");
    BigInt num14("1597753123456789456123789154687");
    BigInt num15 = num13 + num14;
    cout << "num13 = " << num13 << endl;
    cout << "num14 = " << num14 << endl;
    cout << "num13 + num14 = " << num15 << endl;

    cout << "6#\n";
    BigInt num16("456123789154687");
    BigInt num17(-54687);
    BigInt num18 = num16 + num17;
    cout << "num16 = " << num16 << endl;
    cout << "num17 = " << num17 << endl;
    cout << "num16 + num17 = " << num18 << endl;

}
