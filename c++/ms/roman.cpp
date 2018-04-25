#include<bits/stdc++.h>
using namespace std;
int digit(char ch,int n,int i,char* c){
    for(int j=0;j<n;j++)
        c[i++]=ch;
    return i;
}
int sub_digit(char ch1,char ch2,int i, char* c){
    c[i++]=ch1;
    c[i++]=ch2;
    return i;
}
void roman(int n){
    char c[1000005];
    int i=0;
    if(n<=0){
        cout<<"invalid"<<endl;
    }
    while(n!=0){
        if(n>=1000){
            i=digit('M',n/1000,i,c);
            n=n%1000;
        }

        else if(n>=500){
            if(n<900){
                i=digit('D',n/500,i,c);
                n=n%500;
            }
            else{
                i=sub_digit('C','M',i,c);
                n=n%100;
            }
        }
        else if(n>=100){
            if(n<400){
                i=digit('c',n/100,i,c);
                n=n%100;
            }
            else{
                i=sub_digit('C','D',i,c);
                n=n%100;
            }
        }
        else if(n>=50){
            if(n<90){
                i=digit('L',n/50,i,c);
                n=n%50;
            }
            else{
                i=sub_digit('X','C',i,c);
                n=n%10;
            }
        }
        else if(n>=10){
            if(n<40){
                i=digit('X',n/10,i,c);
                n=n%10;
            }
            else{
                i=sub_digit('X','L',i,c);
                n=n%10;
            }
        }
        else if(n>=5){
            if(n<9){
                i=digit('V',n/5,i,c);
                n=n%5;
            }
            else{
                i=sub_digit('I','X',i,c);
                n=0;
            }
        }
        else if(n>=1){
            if(n<4){
                i=digit('I',n,i,c);
                n=0;
            }
            else{
                i=sub_digit('I','V',i,c);
                n=0;
            }
        }
    }
    for(int j=0;j<i;j++){
        cout<<c[j];
    }
    cout<<endl;
}
int main(){
    int n;
    cin>>n;
    roman(n);
    return 0;
}
