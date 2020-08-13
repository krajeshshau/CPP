#include <iostream>

using namespace std;

//plain enum
enum color1{red,green,yellow,black};
//int red; //error: ‘int red’ redeclared as different kind of symbol
//enum color2{red,green,yellow,black,white}; //error: redeclaration of ‘red’

//class enum
enum class color3{red,green,yellow,black,white};
int white;

int main()
{
    color1 c1 = red;
    switch(c1){
        case red: cout<<"red "<<c1<<endl; break;
        case green: cout<<"green "<<c1<<endl; break;
        case yellow: cout<<"yellow "<<c1<<endl; break;
        case black: cout<<"black "<<c1<<endl; break;
    }
    
    color3 c3 = color3::yellow;
    switch(c3){
        case color3::red: cout<<"red "/*<<c3<<*/<<endl; break;
        case color3::green: cout<<"green "/*<<c3*/<<endl; break;
        case color3::yellow: cout<<"yellow "/*<<c3*/<<endl; break;
        case color3::black: cout<<"black "/*<<c3*/<<endl; break;
    }

    return 0;
}
/* OP
red 0
yellow
*/
