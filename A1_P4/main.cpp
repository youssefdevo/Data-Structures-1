/*  name : ahmed said - id : 20200017
 *  name : aya mohamed mounir - id : 20200107
 *  name : shrouk ayman ali - id : 20200251
 *  name : youssef nasser - id : 20200674
 */

#include <iostream>
#include <set>
using namespace std;
void RecPermute(string soFar, string rest)
{
    set<string> newArr;
    int cnt=0;
    if (rest == "") // No more characters
        cout << soFar << endl; // Print the word
    else // Still more chars
// For each remaining char
        for (int i = 0; i < rest.length(); i++) {
            string next = soFar + rest[i]; // Glue next char
            string remaining = rest.substr(0, i)+ rest.substr(i+1);
            cnt=newArr.size();
            newArr.insert(next);
            if(cnt==newArr.size())
                break;
            else
                RecPermute(next, remaining);

        }
}
// "wrapper" function
void ListPermutations(string s) {
    RecPermute("", s);
}
int main() {
    string word;
    cin>>word;
    ListPermutations(word);
}
