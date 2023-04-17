/*  name : ahmed said - id : 20200017
 *  name : aya mohamed mounir - id : 20200107
 *  name : shrouk ayman ali - id : 20200251
 *  name : youssef nasser - id : 20200674
 */
#include <iostream>

using namespace std;
template<class t>
struct node{   //define doubly linked list elements
    t    data;
    node *next;
    node *prev;
};
template<class t>
class List{
private:
    int s;
    node<t> *head;
    node<t> *tail;
public:
    List(){   //copy constructor with dummy node
        head=tail= nullptr;
        s=0;
    };
    List(t value, int initial_size){   //parametrize constructor
        s=initial_size;
        head=tail=nullptr;
        for (int i = 0; i < s; ++i) {   //push the value back and fill the initial size
            node<t> *newNode=new node<t>;
            if (head==nullptr){   //checking if head not point to any node
                head=tail=new node<t>;
                head=newNode;   //set new node into head
            }
            newNode->data=value;
            newNode->next= nullptr;
            newNode->prev=tail;
            tail->next=newNode;
            tail=newNode;
        }
    }
    void push_back(t value)   //store a new element into list from the end
    {
        node<t> *newNode=new node<t>;
        newNode->data=value;
        if(head== nullptr){
            head=tail=newNode;
            newNode->next=newNode->prev= nullptr;
        }
        else{
            newNode->next= nullptr;
            newNode->prev=tail;
            tail->next=newNode;
            tail=newNode;
        }
        s++;
    }
    void push_front(t value)   //store a new element into list from the start
    {
        node<t>* newNode=new node<t>;
        newNode->data=value;
        if(head== nullptr){
            head=tail=newNode;
            newNode->next=newNode->prev= nullptr;
        }
        else{
            newNode->next=head;
            newNode->prev= nullptr;
            head->prev=newNode;
            head=newNode;
        }
        s++;
    }
    void push_position(int p, t value){   //insert new element in specific position
        p--;
        node<t> *newNode=new node<t>;
        newNode->data=value;
        if(p>s){   //doesn't exist position
            cout<<"the position doesn't exist.\n";
        }
        else if(p==1)   //insert into start
            push_front(value);
        else if(p==s)   //insert into end
            push_back(value);
        else{           //insert into position
            node<t> *cur=head;
            for (int i = 1; i < p; ++i) {
                cur=cur->next;
            }
            newNode->next=cur->next;
            newNode->prev=cur;
            cur->next=newNode;
            cur->next->prev=newNode;
            s++;
        }
    }
    int size(){
        return s;
    }
    void pop_front(){
        if(s==0)          // list is empty
            return;
        else if(s==1) {  //  deleting lonely element in the list
            delete head;
            head = tail = nullptr;
        }
        else{            //delete first element
            node<t>* cur=head;
            head= head->next;
            head->prev=nullptr;
            delete cur;
        }
        s--;
    }
    void pop_back(){   //delete the last element in the list
        if(s==0)          //list is empty
            return;
        else if(s==1) {   //delete lonely element in the list
            delete head;
            tail = head = nullptr;
        }
        else{             //delete last element
            node<t>* cur=tail;
            tail= tail->prev;
            tail->next=nullptr;
            delete cur;
        }
        s--;
    }
    void pop_position(int p){   //delete specific element
        if(p>s){      //a wrong position
            cout<<p<<" th position is not found\n";
            return;
        }
        else if(p==1){   //delete first element
            pop_front();
        }
        else if(p==s){   //delete last element
            pop_back();
        }
        else {           //delete specific element
            node<t> *cur = new node<t>;
            node<t> *prev = new node<t>;
            cur = head;
            for (int i = 1; i < p; i++) {
                prev = cur;
                cur = cur->next;
            }
            prev->next = cur->next;
            s--;
        }
    }
    void print(){   //display all elements in the list
        node<t> *newNode=new node<t>;
        if(head== nullptr && tail== nullptr){
            cout<<"it is empty"<<endl;
        }
        else {
            newNode = head;
            for (int i = 0; newNode != nullptr; ++i) {
                cout << newNode->data << "  ";
                newNode = newNode->next;
            }
            cout << "\n";
        }
    }
    List<t>& operator = (List<t> &copyList){
        if( this == &copyList )
            return *this;
        List<t>:: iterator it =copyList.begin();
        this->push_back(*it);
        while(it != copyList.end()){
            ++it;
            this->push_back(*it);
        }
        return *this;
    }
    class iterator{  //class iterator
    private:
        friend class List;
        node<t>*newNodeIt;
        node<t>*headIt;

    public:
        iterator() {   //default
            newNodeIt=NULL;
            headIt=NULL;
        }
        iterator(node<t>*ptr,node<t>*head){   //parametrize constructor
            newNodeIt=ptr;
            headIt=head;
        }
        void operator++() {   //prefix increment
            if(newNodeIt->next== nullptr) {
                cout<<"Out of Scope\n";
            }
            else
                newNodeIt = newNodeIt->next;
        }
        void operator++(int) {   //postfix increment
            if(newNodeIt->next== nullptr) {   //out of scope increment
                cout<<"Out of Scope\n";
            }
            else
                newNodeIt = newNodeIt->next;
        }
        void operator--(){   //prefix decrement
            if(newNodeIt->prev== nullptr) {   //out of scope decrement
                cout<<"Out of Scope\n";
            }
            else
                newNodeIt=newNodeIt->prev;
        }
        void operator--(int){   //post decrement
            if(newNodeIt->prev== nullptr) {   //out of scope decrement
                cout<<"Out of Scope\n";
            }
            else
                newNodeIt=newNodeIt->prev;
        }
        t & operator*(){   //pointer into value
            return newNodeIt->data;
        }
        bool operator==(const iterator& it)const{   //compare two pointers
            return newNodeIt ==it.newNodeit;
        }
        bool operator!=(const iterator& it)const{   //compare two pointers
            return newNodeIt !=it.newNodeIt;
        }

    };

    iterator begin(){   //going to first element
        return iterator(head,head);
    }
    iterator end(){   //going to last element
        return iterator(tail,head);
    }
    iterator erase(iterator pos) {   //delete specific element using pointer iterator
        node<t> *deleteNode = pos.newNodeIt->next;
        pos.newNodeIt->next = pos.newNodeIt->next->next;//
        if (deleteNode == tail) {
            tail = pos.newNodeIt;
        }
        delete deleteNode;
        return pos;
    }
    //destructor
    ~List(){
        while (head!=tail){
            node<t>* temp = head;
            head = head->next;
            delete temp;
        }
        delete head;
        delete tail;
    }
};
int main() {

    //    myList<int> o;
    //    o.print();
    List<int> list(1,3);
    list.push_back(2);
    list.push_back(4);
    list.push_back(5);
    cout<<"size of the list:\n";
    cout<<list.size()<<endl;
    cout<<"you list now is :\n";
    list.print();
    cout<<"push position 4 value 3: \n";
    list.push_position(4,3);
    list.print();
    cout<<"push front 4 :\n ";
    list.push_front(0);
    list.print();
    cout<<"push back 10 :\n ";
    list.push_back(6);
    list.print();
    cout<<"size now is :\n";
    cout<<list.size()<<endl;
    cout<<"delete first element :\n ";
    list.pop_front();
    list.print();
    cout<<"delete last element :\n ";
    list.pop_back();
    list.print();
    cout<<"delete position :\n ";
    list.pop_position(2);
    list.print();
    cout<<"delete position :\n ";
    list.pop_position(10);
    list.print();
    cout<<"size now is:\n ";
    cout<<list.size()<<endl;
    cout<<"your list now is : \n";
    list.print();     // 1 1 2 3 4 5

    cout<<endl;

    List<int>:: iterator itr1 = list.begin();
    List<int>:: iterator itr2 = list.begin();
    List<int>:: iterator itr3 = list.end();


    cout<<"print using iterator : \n";
    for (int i = 0; i < list.size(); ++i) {
        cout<<*itr1<<"  ";   // 1 1 2 3 4
        if(i<list.size()-1){
            ++itr1;
        }
    }
    cout<<endl;
    itr1++; //  error
    cout<<*itr1<<endl;  //5
    --itr1;
    cout<<*itr1<<endl;   //4
    cout<<"pointing at the end of list : \n";
    cout<<*itr3<<endl;  //  5
    itr3--;
    cout<<*itr3<<endl;   // 4
    cout<<"erase first element : \n";
    list.erase(itr2); // erase first element
    list.print();
    cout<<endl;
    itr2++;
    cout<<"your list now is :\n";
    list.print();
    List<int> list2;
    cout<<"copy the list : \n";
    list2 = list;
    list2.print();  // 1 3 2 4 5
    return 0;
}
