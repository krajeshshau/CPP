#include <iostream>

using namespace std;

//plain enum
//enum color{red,green,yellow,black};
//enum people{good,bad};

enum class color{red,green,yellow,black};
enum class people{good,bad};

int main()
{
    if(red == good) cout<<"Magic in enum"<<endl;//main.cpp:14:8: error: ‘red’ was not declared in this scope
    else cout<<"All is well in enum"<<endl;
    return 0;
}
/* OP
//Magic in enum                                                                   
main.cpp:14:8: error: ‘red’ was not declared in this scope

*/
