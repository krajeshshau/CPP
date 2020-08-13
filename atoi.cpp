#include <iostream>

using namespace std;

int aToi(string str){
    int ret = 0;
    int i = 0;
    int sign = 1;
    if(str[i] == '-'){
        sign = -1;
        i++;
    }
    while(str[i] != '\0'){
        ret = ret * 10 + str[i] - '0';
        i++;
    }
    return ret;
}

int main()
{
    string str("132546");
    int ret = aToi(str);
    cout<<ret<<endl;
    return 0;
}
/* OP
132546
*/
