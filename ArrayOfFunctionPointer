#include<iostream>

using namespace std;

int add(int a, int b){
    return a+b;
}

int sub(int a, int b){
    return a-b;
}

typedef int (*mathFun)(int, int); 

int main()
{
    mathFun arr[2] = {add,sub};
    int result = arr[0](10,5);
    cout<<result<<endl;
    //result = arr[1](10,5);
    result = (*arr[1])(10,5);
    cout<<result<<endl;
    
    return 0;
}
/* OP 
15
5
*/
