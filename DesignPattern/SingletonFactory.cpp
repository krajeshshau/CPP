#include<iostream>

using namespace std;

class protocl{
  public:
    virtual void pair() = 0;
    virtual void connect() = 0;
};

class wifi : public protocl{
    private:
      wifi(){
      }  
      wifi(const wifi& obj){
      }
      wifi& operator=(const wifi& obj){
          return *this;
      }
      static wifi* inst;
    public:
        virtual void pair() {
            cout<<"wifi deviced paring"<<endl;
        }
        virtual void connect(){
            cout<<"wifi device connecting"<<endl;
        }
        static wifi* createOneInstance(){
            if(inst == nullptr)
                inst = new wifi();
            return inst;
        }
};
wifi* wifi::inst = nullptr;

class bt : public protocl{
    private:
      bt(){
      }  
      bt(const bt& obj){
      }
      bt& operator=(const bt& obj){
          return *this;
      }
      static bt* inst;
    public:
        virtual void pair() {
            cout<<"BT deviced paring"<<endl;
        }
        virtual void connect(){
            cout<<"BT device connecting"<<endl;
        }
        static bt* createOneInstance(){
            if(inst == nullptr)
                inst = new bt();
            return inst;
        }
};
bt* bt::inst = nullptr;

enum protocalType{
  pt_bt = 1, pt_wifi = 2  
};

class communication{
    public:
        static protocl* getCommuInstance(protocalType pt){
            if(pt == pt_wifi)
                return wifi::createOneInstance();
            else if(pt == pt_bt)
                return bt::createOneInstance();
            else{
                cout<<"invalid input"<<endl;
                return nullptr;
            }
        }
};

int main(){
    
    protocl* obj = communication::getCommuInstance(pt_bt);
    obj->pair();
    obj->connect();
    obj = communication::getCommuInstance(pt_wifi);
    obj->pair();
    obj->connect();
    
    return 0;
}

