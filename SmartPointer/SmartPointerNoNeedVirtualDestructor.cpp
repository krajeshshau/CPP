#include<iostream>
#include<memory>

using namespace std;

class Base{
  public:
  Base(){
    cout<<"Base..\n";
  }
  /*virtual*/ ~Base(){
      cout<<"~Base..\n";
  }
};
class Derived:public Base{
  public:
  Derived(){
    cout<<"Derived..\n";
  }
  ~Derived(){
      cout<<"~Derived..\n";
  }
};

int main(){
    //Base *pBase = new Derived();
    //delete pBase;
    //shared_ptr<Base> sp(new Derived()); //Good
    shared_ptr<Base> sp(make_shared<Derived>()); //it also good
    return 0;
}

/*
OP:
case: witout virtual destructor in base
Base..                                                                                                                        
Derived..                                                                                                                     
~Base...
case: with virtual destructor in base
Base..                                                                                                                        
Derived..                                                                                                                     
~Derived..
~Base...
case:case: witout virtual destructor in base with smart pointer
Base..                                                                                                                        
Derived..                                                                                                                     
~Derived..
~Base...

Note:
This behavior is achieved by shared_ptr only.
This behavior is not achieved by using unique_ptr.
All the classes in STL do not have virtual destructor, so be careful if you inherit from them. If you want to inherit, you can use shared_ptr in that case to have the smart destruction applied.
*/