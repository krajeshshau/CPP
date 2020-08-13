#include <iostream>

using namespace std;

//plain enum
enum color1{red,green,yellow,black};

void print(int en){
    switch(en){
        case red: cout<<"red "<<en<<endl;break;
        case green: cout<<"green "<<en<<endl;break;
        case yellow: cout<<"yellow "<<en<<endl;break;
        default: cout<<"Sorry no color matching!"<<endl;
    }
}

//class enum
enum class color2{red,green,yellow,black,white};
void display(color2 en){
    switch(en){
        case color2::red: cout<<"class red "<<endl;break;
        case color2::green: cout<<"class green "<<endl;break;
        case color2::yellow: cout<<"class yellow "<<endl;break;
        default: cout<<"Sorry no color matching in class!"<<endl;
    }
}

int main()
{
    print(10);
    print(red);
    display(color2::red);
    display(color2::white);
    
    return 0;
}
/* OP
Sorry no color matching!                                                        
red 0                                                                           
class red                                                                       
Sorry no color matching in class!                                               
*/
