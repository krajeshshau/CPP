#include<iostream>
#include<tuple>

using namespace std;

struct values{
    int i;
    float f;
    string str;
    values(){
    }
    values(int _i, float _f, string _str){
        i = _i;
        f = _f;
        str = _str;
    }
};

values display(){
/*    values val;
    val.i = 10;
    val.f = 20.5;
    val.str = "rajesh";
    return val; */
    return values(10,20.5,"rajesh");
}

tuple<int,float,string>display1(){
    return make_tuple(10,20.5,"rajesh");
}

int main(){
    //values val;
    //val = display();
    //cout<<val.i<<" "<<val.f<<" "<<val.str<<endl;
/*  auto val = display();
    cout<<val.i<<" "<<val.f<<" "<<val.str<<endl;
*/    
    int i;
    float f;
    string str;
//    tie(i,f,str) = display1();
//    cout<<i<<" "<<f<<" "<<str<<endl;

    return 0;
}