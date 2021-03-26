#include <iostream>
#include <string>
#include <ctime>
#include <vector>
#include <fstream>
#include <iomanip>
#include <algorithm>
#include <cmath>
 
using namespace std;

class node {
public:
    int data;
    node* link;
};

class node2 {
public:
    string data2;
    node2* link2;
};

int main ()
{
    vector<int> v1;
    vector<string> v2;
    
    srand(time(NULL));
    
    for (int i=0;i<4;i++){ //This fills the vector with random numbers
        v1.push_back(rand() % 100); //Adds a position to the end
    }
    v1.pop_back(); //Takes off the last position
     
    cout << "This is the vector when filled with random numbers: " ;

    vector<int>::iterator it;
    for (it=v1.begin();it != v1.end();it++){ //We will keep going until it is not the same as v1.end
        cout << *it << " ";
    }

    cout << endl;


    int rnum; //Random number
    char rchar; // Random character
    string str = "";
    
    for (int i=0;i<4;i++){
        str=str + "";
        for(int i=0;i<3;i++){
            rnum=rand() % 26;
            rchar=(char)(rnum % 68 + 58); //randomly generate random chars using ascii 
            str = str + rchar;
        }
        v2.push_back(str);
        
    }
    v2.pop_back();

    cout << "This is the vector filled with random strings: ";

    vector<string>::iterator itz;
    for (itz=v2.begin();itz != v2.end();itz++){
        cout << *itz << " ";
    }
    cout << endl;
    


    cout << "This is the linked list with random integers: ";

    node* first = new node;
    node* second = new node;
    node* third = new node;

    first->data = rand() % 100;
    second->data = rand() % 100;
    third->data = rand() % 100;

    first->link = second;
    second->link = third;
    third->link = nullptr;

    node* current = new node;
    current =first;
    while(current != nullptr){
        cout << current->data << " ";
        current = current->link;
    }

    cout << endl << "This is the linked list with random strings: ";

    node2* f = new node2;
    node2* s = new node2;
    node2* t = new node2;

    f->link2=s;
    s->link2=t;
    t->link2=nullptr;

    string str2;
    node2* current2 =f;
    while(current2!=nullptr){
        str2="";
        for (int i=0;i<3;i++){
            rchar=(char)(rnum % 68 + 58);
            str2=str2+rchar;    
        }
        current2->data2=str2;
        current2=current2->link2;
    }
    
    current2 =f;
    while(current2 != nullptr){
        cout << current2->data2 << " ";
        current = current->link;
    }
    cout << endl;

    return 0;
   
}
