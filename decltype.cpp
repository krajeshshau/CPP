/*
decltype check expression type
*/
#include<iostream>

using namespace std;

template<class T1, class T2>
auto sum(T1 x, T2 y) ->decltype(x+y){
    return (x + y);
}

int main(){
    cout<<sum(2,3.5)<<endl;
    cout<<sum(3.5,2)<<endl;
    return 0;
}