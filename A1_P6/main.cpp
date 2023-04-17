/*  name : ahmed said - id : 20200017
 *  name : aya mohamed mounir - id : 20200107
 *  name : shrouk ayman ali - id : 20200251
 *  name : youssef nasser - id : 20200674
 */

#include <iomanip>
#include <iostream>
#include <vector>

using namespace std;
class PhoneDirectory {

private:
    string firstName, lastName;
    string phoneNumberEntry;
public:
    vector<string> firstN;
    vector<string> lastN;
    vector<string> phoneN;

    PhoneDirectory() = default;

    void addEntry() {
        cout << "Enter First Name:";
        cin >> firstName;
        firstN.push_back(firstName);
        cout << "Enter Last Name:";
        cin >> lastName;
        lastN.push_back(lastName);
        cout << "Enter Phone Number:";
        cin >> phoneNumberEntry;
        phoneN.push_back(phoneNumberEntry);
    }

    void deleteEntry() {
        string fn;
        int index = 0;
        cout << "Enter First Name:";
        cin >> fn;
        for (int i = 0; i < firstN.size(); i++) {
            if (firstN[i] == fn) {
                index = i;
            }
        }
        firstN.erase(firstN.begin() + index);
        lastN.erase(lastN.begin() + index);
        phoneN.erase(phoneN.begin() + index);
        int n;
        cout<<"Choose an sort algorithm:\n"
              "1-Insertion Sort.\n"
              "2-Selection Sort.\n"
              "3-Shell Sort.\n";
        cin>>n;
        switch (n) {
            case 1:
                listDirectory_insertion();
                break;
            case 2:
                listDirectory_selection();
                break;
            case 3:
                listDirectory_shell();
                break;
        }
    }
    void listDirectory_selection() {
        for (int i = 0; i < firstN.size(); ++i) {
            int least = i;
            for (int j = i+1; j < firstN.size(); ++j) {
                if (firstN[j] < firstN[least]){
                    least=j;
                }
            }
            swap(firstN[i],firstN[least]);
        }
        cout<<endl<<"--------Sorting With Selection Sort--------"<<endl<<endl;
        cout<<left<<setw(15)<<"First Name"<<setw(15)<<"Last Name"<<setw(15)<<"Phone Number"<<endl;
        for (int i = 0; i < firstN.size(); ++i) {
            cout<<left<<setw(15)<<firstN[i]<<setw(15)<<lastN[i]<<setw(15)<<phoneN[i]<<endl<<endl;
        }
    }
    void listDirectory_shell() {
        for (int gap=firstN.size()/2; gap>0 ; gap/=2) {
            for (int i = gap; i < firstN.size() ; ++i) {
                string tmpFN=firstN[i];
                string tmpLN=lastN[i];
                string tmpPN=phoneN[i];
                for (int j = i; j >= gap && firstN[j-1]>tmpFN ; ++j) {
                    swap(firstN[j],firstN[j-gap]);
                    swap(lastN[j],lastN[j-gap]);
                    swap(phoneN[j],phoneN[j-gap]);
                }
            }
        }
        cout<<endl<<"--------Sorting With Shell Sort--------"<<endl<<endl;
        cout<<left<<setw(15)<<"First Name"<<setw(15)<<"Last Name"<<setw(15)<<"Phone Number"<<endl;
        for (int i = 0; i < firstN.size(); ++i) {
            cout<<left<<setw(15)<<firstN[i]<<setw(15)<<lastN[i]<<setw(15)<<phoneN[i]<<endl<<endl;
        }
    }
    void listDirectory_insertion(){
        for (int i = 1 ,j; i <firstN.size() ; ++i) {
            string tmpFN=firstN[i];
            string tmpLN=lastN[i];
            string tmpPN=phoneN[i];
            for ( j = i; j >0 && tmpFN<firstN[j-1] ; --j) {
                firstN[j]=firstN[j-1];
                lastN[j]=lastN[j-1];
                phoneN[j]=phoneN[j-1];
            }
            firstN[j]=tmpFN;
            lastN[j]=tmpLN;
            phoneN[j]=tmpPN;
        }
        cout<<endl<<"--------Sorting With Insertion Sort--------"<<endl<<endl;
        cout<<left<<setw(15)<<"First Name"<<setw(15)<<"Last Name"<<setw(15)<<"Phone Number"<<endl;
        for (int i = 0; i < firstN.size(); ++i) {
            cout<<left<<setw(15)<<firstN[i]<<setw(15)<<lastN[i]<<setw(15)<<phoneN[i]<<endl<<endl;
        }
    }
    void sort(){
        int n;
        cout<<"Choose an sort algorithm:\n"
              "1-Insertion Sort.\n"
              "2-Selection Sort.\n"
              "3-Shell Sort.\n";
        cin>>n;
        switch (n) {
            case 1:
                listDirectory_insertion();
                break;
            case 2:
                listDirectory_selection();
                break;
            case 3:
                listDirectory_shell();
                break;
        }
    }
    void lookByFN(){
        string fn;
        cout<<"enter the first name:";
        cin>>fn;
        for (int i = 0; i < firstN.size(); ++i) {
            if(firstN[i] == fn){
                cout<<left<<setw(15)<<"First Name"<<setw(15)<<"Last Name"<<setw(15)<<"Phone Number"<<endl;
                cout<<left<<setw(15)<<firstN[i]<<setw(15)<<lastN[i]<<setw(15)<<phoneN[i]<<endl<<endl;
                return;
            }
        }
        cout<<"Entry not found! \n";
    }
    void lookByPN(){
        string pn;
        cout<<"enter the phone number:";
        cin>>pn;
        for (int i = 0; i < phoneN.size(); ++i) {
            if(phoneN[i] == pn){
                cout<<left<<setw(15)<<"First Name"<<setw(15)<<"Last Name"<<setw(15)<<"Phone Number"<<endl;
                cout<<left<<setw(15)<<firstN[i]<<setw(15)<<lastN[i]<<setw(15)<<phoneN[i]<<endl<<endl;
                return;
            }
        }
        cout<<"Entry not found! \n";
    }
    void Menu(){
        string fn,ln,pn;
        int num;
        while(true){
            cout <<endl<< "-------menu------\n";
            cout << " 1. Add an entry to the directory\n";
            cout << " 2. Look up a phone number\n";
            cout << " 3. Look up by first name\n";
            cout << " 4. Delete an entry from the directory\n";
            cout << " 5. List All entries in phone directory\n";
            cout << " 6. Exit form this program\n";
            cout<<"Please Enter The number [ 1 -> 6 ]:";
            cin>>num;
            switch (num) {
                case 1:
                    addEntry();
                    break;
                case 2:
                    lookByPN();
                    break;
                case 3:
                    lookByFN();
                    break;
                case 4:
                    deleteEntry();
                    break;
                case 5:
                    sort();
                    break;
                case 6:
                    cout<<"Thank you for using this Program ^_^";
                    return;
            }
        }
    }
};

int main(){
    PhoneDirectory phone;
    phone.Menu();
}
