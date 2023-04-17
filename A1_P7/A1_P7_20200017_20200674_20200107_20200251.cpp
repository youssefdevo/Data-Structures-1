/*  name : ahmed said - id : 20200017
 *  name : aya mohamed monir - id : 20200107
 *  name : shrouk ayman ali - id : 20200251
 *  name : youssef nasser - id : 20200674
 */

#include <iostream>
#include <vector>
#include <string>
using namespace std;
//function accepts a vector and size
void BiasedSort(vector <string>& v, int n) {
// implementation based on selection sort
    int k = 0;
    for (int i = 0; i < n; ++i) {

        int ndx = i;
        string check = v[ndx];
        while (ndx > k && (v[ndx - 1] > v[ndx] || v[ndx] == "Untitled")) {

            swap(v[ndx], v[ndx - 1]);

            ndx--;
        }
        if (check == "Untitled")
            k++;
    }
}
int main() {
    vector<string>test1={"Sad","Verysad","Untitled","Unhappy"};
    vector<string>test2={"Molotof","Belsalam","Untitled","Siuuu","BobMarly"};
    vector<string>test3={"Vector","Alahly" , "Untitled" ,"Corona","Untitled"};

    cout<<"First vector without sort :  ";
    for (string s: test1)
        cout << s << ' ';
    cout<<"\n";
    BiasedSort(test1,test1.size());
    cout<<"First vector After sort :  ";
    for (string s : test1)
        cout << s << ' ';
    cout<<"\n\n";

    cout<<"Second vector without sort :  ";
    for (string s : test2)
        cout << s << ' ';
    cout<<"\n";
    BiasedSort(test2,test2.size());
    cout<<"Second vector After sort :  ";
    for (string s : test2)
        cout << s << ' ';
    cout<<"\n\n";


    cout<<"Third vector without sort :  ";
    for (string s : test3)
        cout << s << ' ';
    cout<<"\n";
    BiasedSort(test3,test3.size());
    cout<<"Third vector After sort :  ";
    for (string s : test3)
        cout << s << ' ';
    cout<<"\n\n";

    cout<<"If you need test another example enter 1 \nTo Exit enter 0:";
    int x;cin>>x;
    if(x==1){
        cout << "Enter Number of The Songs: ";
        int k;
        cin >> k;

        vector<string> songs;
        cout << "\nEnter The Names of The Songs, and make the first digit in upper case:\n";
        for (int i = 0; i < k; ++i) {
            string s;
            cin >> s;
            songs.push_back(s);
        }

        BiasedSort(songs, k);

        cout << "Songs after sort : ";
        for (string s : songs)
            cout << s << ' ';
        cout<<"\n\n";
    }
    else{
        cout<<"\nThank You";
        return 0;
    }


    return 0;
}
