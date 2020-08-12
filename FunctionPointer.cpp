#include<iostream>

using namespace std;

int add(int a, int b){
    return a+b;
}

int sub(int a, int b){
    return a-b;
}

int (*cal(int type))(int,int){
    if(type == 1)
       return add;
    else if(type == 2)
        return sub;
    else
        return 0;
}

int main()
{
    int (*pfun)(int,int);
    pfun = cal(1);
    cout<<pfun(5,10)<<endl;
    pfun = cal(2);
    cout<<pfun(10,5)<<endl;
    
    return 0;
}

/* OP: 
15
5
*/
