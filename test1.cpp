#include<iostream>
#include<string>
#include<vector>

using namespace std;
class Animal{
private:
  int height;
  int weight;
  string name;

  static int numOfAnimals;

public:
  int getHeight(){return height;}
  int getWeight(){return weight;}
  string getName(){return name;}

  void setHeight(int cm){ height=cm;}
  void setWeight(int kg){ weight=kg;}
  void setName(string Aname){ name=Aname;}

  void setAll(int ,int ,string);

  Animal(int,int,string);
  ~Animal();
  Animal();

  static int getNumOfAnimals(){return numOfAnimals;}

  void toString();

};
int Animal::numOfAnimals=0;
/*Animal::setAll(int height,int weight,string name){
  this->height=height;
  this->weight=weight;
  this->name=name;
  Animal::numOfAnimals++;
}*/
Animal::Animal(int h,int w,string n){
  this->height=h;
  this->weight=w;
  this->name=n;
  Animal::numOfAnimals++;
}
Animal::~Animal(){cout <<"Animal "<< this->name <<" destroyed"<<endl;}
Animal::Animal(){ Animal::numOfAnimals++;}
void Animal::toString(){cout<<this->name<<" is"<< this->height<<" cms in height and "<< this->weight<<" kg in weight"<<endl;}

int main() {

  Animal fred;
  fred.setHeight(70);
  fred.setWeight(120);
  fred.setName("fred");

  cout<<fred.getName()<< " is "<<fred.getHeight()<<"cms in height and "<<fred.getWeight()<<"kg in weight "<<endl;

  Animal tom(30,50,"tom");
  cout<<tom.getName()<<" is "<< tom.getHeight()<<"cms in height and "<< tom.getWeight()<<"kg in weight "<< endl;

  return 0;
}
