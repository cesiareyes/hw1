/*
array
    Array class (class template )

vector
    Vector (class template )

deque
    Double ended queue (class template )

forward_list
    Forward list (class template )

list
    List (class template )
*/
#include <iostream>
#include <time.h>
#include <array>
#include <vector>
#include <list>
#include <chrono>
#include <ctime>
using namespace std;

array<int, 20000> testArray;
vector<int> testVector;
list<int> testList;


int main(){
  time_t start,
         finish;
  cout << "Tessting Array Container"<<endl;
  time(&start);
  //construct
  testArray = array<int, 20000>();
  //add 20000 entries
  for(int i= 0; i< 20000; i++){
    testArray[i]=i;
  }
  //remove 20000 entries
   for(int i= 0; i< 20000; i++){
    testArray[i]=-1;
  }
  time(&finish);
  //report time
  cout <<"Started " <<start <<" ended " << finish << " Elapsed " <<(finish -start)<<endl;
  
cout << "Tessting Vector Container"<<endl;
  time(&start);
  //construct
  testVector = vector<int>();
  //add 20000 entries
  for(int i= 0; i< 20000; i++){
    testVector.push_back(i);
  }
  //remove 20000 entries
   for(int i= 0; i< 20000; i++){
    testVector.pop_back();
  }
  time(&finish);
  //report time
  cout <<"Started " <<start <<" ended " << finish << " Elapsed " <<(finish -start)<<endl;
  
cout << "Testing Array Container"<<endl;
  time(&start);
  //construct
  testList = list<int>();
  //add 20000 entries
  for(int i= 0; i< 20000; i++){
    testList.push_front(i);
  }
  //remove 20000 entries
   for(int i= 0; i< 20000; i++){
     testList.pop_front();
  }
  time(&finish);
  //report time
  cout <<"Started " <<start <<" ended " << finish << " Elapsed " <<(finish -start)<<endl;
  
return 0;
}