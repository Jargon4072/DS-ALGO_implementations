#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
class Person{
/*private:
  string name;
  int age;

  //static int cur_id;*/

public:
  string name;
  int age;
  virtual void getdata(){/*cin>>name>>age;*/}
  virtual void  putdata(){/*cout<<name<<age;*/}

  //Person(string,int);
//  ~Person();
//  Person();

//  static int getid(){return cur_id;}

};

//int Person::cur_id=0;
/*Person::Person(string name,int age){
  this->name=name;
  this->age=age;
  //Person::cur_id++;
}
//Person::~Person();
//Person::Person(){ Person::cur_id++;}*/
class Professor:public Person{
  /*int age;
  string name;
  int publications;*/
public:
  static int p;
  int publications;
  int cur_id;
  Professor(){
    cur_id=p++;
  }
  void getdata(){ cin>>name>>age>>publications;}
  void putdata(){cout<<name<<" "<<age<<" "<<publications<<" "<<cur_id<<endl;}
};
class Student:public Person{
  /*int age;
  string name;
  int a,b,c,d,e,f;*/
public:
  static int s;
  int marks[6];
  int cur_id;
  Student(){cur_id=s++;}
  void getdata(){
    cin>>name>>age;
    for(int i=0;i<6;i++)
    cin>>marks[i];
  }
  int sum(int m[]) {
           int t = 0;
           int i;
           for(i = 0; i < 6; i++) t = t+ m[i];
           return t;
       }
  void putdata(){
  cout<<name<<" "<<age<<" "<<sum(marks)<<" ";
  cout<<cur_id<<endl;
  }
};
int Professor::p=1;
int Student::s=1;
int main(){

    int n, val;
    cin>>n; //The number of objects that is going to be created.
    Person *per[n];

    for(int i = 0;i < n;i++){

        cin>>val;
        if(val == 1){
            // If val is 1 current object is of type Professor
            per[i] = new Professor;

        }
        else per[i] = new Student; // Else the current object is of type Student

        per[i]->getdata(); // Get the data from the user.

    }

    for(int i=0;i<n;i++)
        per[i]->putdata(); // Print the required output for each object.

    return 0;

}
