#include<bits/stdc++.h>

using namespace std;


//Implement the class Box
class Box{
//l,b,h are integers representing the dimensions of the box
    private:
    static int Boxescreated;
    static int Boxesdestroyed;
    int l=0;
    int b=0;
    int h=0;
// The class should have the following functions :

// Constructors:
// Box();
// Box(int,int,int);
// Box(Box);


// int getLength(); // Return box's length
// int getBreadth (); // Return box's breadth
// int getHeight ();  //Return box's height
// long long CalculateVolume(); // Return the volume of the box
    public:
    int getLength(){return l;}
    int getBreadth(){return b;}
    int getHeight(){return h;}
    long long CalculateVolume(){return (long long)l*b*h; }

    Box();
    Box(int,int,int);

    Box(Box& obj);
    ~Box();
    bool operator<(Box &p){
        if(this->l != p.l) return this->l < p.l;
        if(this->b != p.b) return this->b < p.b;
        return this->h < p.h;
    }


//Overload operator << as specified
//ostream& operator<<(ostream& out, Box& B)

};
 ostream& operator<<(ostream& out,Box& box) {
   out << box.getLength() << " " << box.getBreadth() << " " << box.getHeight();
    return out;
 }
int Box::Boxescreated=0;
int Box::Boxesdestroyed=0;
Box::Box(int m,int n,int o){
    this->l=m;
    this->b=n;
    this->h=o;

}
Box::Box(Box& obj){
         l = obj.l;
        b =obj.b;
        h = obj.h;
        Boxescreated++;
    }
Box::Box(){Boxescreated++;}
Box::~Box(){Boxesdestroyed++;}


void check2()
{
	int n;
	cin>>n;
	Box temp;
	for(int i=0;i<n;i++)
	{
		int type;
		cin>>type;
		if(type ==1)
		{
			cout<<temp<<endl;
		}
		if(type == 2)
		{
			int l,b,h;
			cin>>l>>b>>h;
			Box NewBox(l,b,h);
			temp=NewBox;
			cout<<temp<<endl;
		}
		if(type==3)
		{
			int l,b,h;
			cin>>l>>b>>h;
			Box NewBox(l,b,h);
			if(NewBox<temp)
			{
				cout<<"Lesser\n";
			}
			else
			{
				cout<<"Greater\n";
			}
		}
		if(type==4)
		{
			cout<<temp.CalculateVolume()<<endl;
		}
		if(type==5)
		{
			Box NewBox(temp);
			cout<<NewBox<<endl;
		}

	}
}

int main()
{
	check2();
}
