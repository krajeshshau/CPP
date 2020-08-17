/*static data and function member*/ 

#include<iostream>

using namespace std;

class Static{
private:
    static int i; //private
    int k;
public:
static int j;  //public
    void display(){
        cout<<i<<" "<<j<<endl;
    }
    ~Static(){
        cout<<"~Static..."<<endl;
    }
    void static get();
};

int Static:: i = 5;
int Static:: j = 10;

void Static:: get(){
    cout<<i<<endl;
    cout<<k<<endl;  //error: invalid use of member ‘Static::k’ in static member function

}

void print(){
    static Static obj;
    obj.display();
}
int main(){
    //Static st;
    //st.display();
    print();
    cout<<"static object tiil not die since it retain till program running"<<endl;
    Static::get();
    return 0;
}