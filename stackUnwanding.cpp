#include<iostream>

using namespace std;

void fun3() /*throw int()*/{
    cout<<"inside fun3"<<endl;
    throw 100;
    cout<<"coming out fun3"<<endl;
}

void fun2(){
    cout<<"inside fun2"<<endl;
    fun3();
    cout<<"coming out fun2"<<endl;
}

void fun1(){
    cout<<"inside fun1"<<endl;
    try{
        fun2();
    }catch(int i){
        cout<<"exception catch "<<i<<endl;
    }
    cout<<"coming out fun1"<<endl;
}

int main(){
    cout<<"inside main..."<<endl;
    fun1();
    cout<<"coming out from main..."<<endl;
    return 0;
}