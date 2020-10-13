#ifndef PERSON_H
#define PERSON_H

#include <iostream>
using namespace std;

template <class T>
class Person {
  public: 
    Person(string name, T age) {
      this->name = name;
      this->age = age;
    }
    string name;
    T age;
  
  public:
    void greet() {
      cout<<"Hello"<<" I'm "<<this->name<<" I'm "<<age<<" years old"<<endl;
    }
};

#endif
