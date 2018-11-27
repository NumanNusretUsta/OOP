#include <iostream>
#include "stdlib.h"
using namespace std;
template<class T = int, class M = int>
class SafeArray {
  private:
    M N;
    T *arr;

    void put(M i, T val) {
      arr[i] = val;
    }

  public:
    SafeArray() {
      N = (M)0;
      arr = NULL;
    }

    SafeArray(M SIZE, int FILL = 0) {
      if (SIZE != 0) {
        N = SIZE;
        arr = new T[SIZE];
        if (FILL == 0) {
          for (M i = 0; i < SIZE; i++) arr[i] = (T)0; 
        } else {
          unsigned int t = static_cast<unsigned int>(time(NULL));
          srand(t);
          for (M i = 0; i < SIZE; i++) arr[i] = rand()%FILL;
        }
      }   
    }

    T at(M i) {
      if (i < N && i >= 0) {
        return arr[i];
      } else {
        cout << "out of bound !!!" << endl;
        return 0;
      }
    }

    SafeArray operator + (SafeArray &other) {
      SafeArray tmp(N);
      for (M i = 0; i < N; i++) {
        //tmp.put(i, arr[i]+other.arr[i]);
        tmp.arr[i] = arr[i]+other.arr[i];
      }
      return tmp;
    }
};

int main(){
  // test default constructor
  SafeArray<> sa0;

  // test overloaded constructor
  SafeArray<double,int> sa1(10, 100);
  SafeArray<double,int> sa2(10, 5);

  // perform arithmetic operation
  SafeArray<double,int> sa3 = sa1+sa2;
  //sa3[5] = 4;

  // print content
  for (int i = 0; i < 10; i++){
    cout << sa1.at(i) << "+" << sa2.at(i) << " = " << sa3.at(i) << endl;
    //cout << sa1[i] << "+" << sa2[i] << " = " << sa3[i] << endl;
  }

 return 0;
}
