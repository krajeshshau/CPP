#include<iostream>
#include<array>
#include<list>
#include<vector>
#include<deque>
#include<set>
#include<map>

using namespace std;

void comp(auto lmbd){
    if(lmbd(5,6)) cout<<"Greater"<<endl;
    else cout<<"Smaller"<<endl;
}

int main(){
[](){
    cout<<"Lambda expression_2"<<endl;
}();  //Anonymous function object(functor) is created here and calling throgh function call operator operator().

auto fun = [](){
    cout<<"Lambda expression"<<endl;
};    //fun is anonymous object of anonymous class.
fun();

auto sum = [](auto i, auto j){
    return i+j;
};
cout<<sum(5,6.5)<<endl;

comp([](int x, int y){
    return x > y;
});


    return 0;
}
