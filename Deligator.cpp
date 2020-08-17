#include<iostream>

using namespace std;

class Deligator{
    int a,b,c;
 public:
    Deligator():Deligator(0){
        //cout<<a<<b<<c<<endl;
    }Deligator(int _a):Deligator(_a,0){
        //cout<<a<<b<<c<<endl;
    }Deligator(int _a, int _b):Deligator(_a,_b,0){
        //cout<<a<<b<<c<<endl;
    }Deligator(int _a, int _b, int _c):a(_a),b(_b),c(_c){
        //cout<<a<<b<<c<<endl;
    }
};

int main(){
    Deligator d;
    Deligator d1(10);
    Deligator d2(20,30);
    Deligator d3(40,50,60);
    return 0;
}