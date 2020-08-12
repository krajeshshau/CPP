#include<iostream>
#include<vector>

using namespace std;

int main()
{
    vector<int>vect;
    cout<<vect.size()<<" "<<vect.capacity()<<endl;
    vect.push_back(10);
    cout<<vect.size()<<" "<<vect.capacity()<<endl;
    vect.push_back(20);
    cout<<vect.size()<<" "<<vect.capacity()<<endl;
    vect.push_back(30);
    cout<<vect.size()<<" "<<vect.capacity()<<endl;
    vect.push_back(40);
    cout<<vect.size()<<" "<<vect.capacity()<<endl;
}
/* OP 
0 0
1 1
2 2
3 4
4 4
*/
