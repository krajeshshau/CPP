#include<iostream>

using namespace std;

class Base{
    private:
        int priB;
        void priBB(){
            cout<<"priBB..."<<endl;
        }
    protected:
        int proB;
        void proBB(){
            cout<<"proBB..."<<endl;
        }
    public:
        int pubB;
        void pubBB(){
            cout<<"pubBB..."<<endl;
        }
};
class Derived: private Base{
    private:
        int priD;
        void priDD(){
            cout<<"priDD..."<<endl;
            //priB++;  //error: ‘int Base::priB’ is private within this context
            proB++;
            pubB++;
        }
    protected:
        int proD;
        void proDD(){
            cout<<"proDD..."<<endl;
            //priB++;  //error: ‘int Base::priB’ is private within this context
            proB++;
            pubB++;
        }
    public:
        int pubD;
        void pubDD(){
            cout<<"pubDD..."<<endl;
            //priB++;  //error: ‘int Base::priB’ is private within this context
            proB++;
            pubB++;
        }
};
int main()
{
    //printf("Hello World");
    
    Derived D;
    //D.pubBB();
    //D.proBB();
    //D.priBB();
    
    return 0;
}



