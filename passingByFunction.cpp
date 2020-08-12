#include<iostream>

using namespace std;

int add(int a, int b){
    return a+b;
}

int mathFun(int(*add)(int,int)){
    return add(10,5);
}

int main()
{
    cout<<mathFun(add)<<endl; 
    
    return 0;
}
/* OP 
15
*/
