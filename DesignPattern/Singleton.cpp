/*static data and function member*/ 

#include<iostream>

using namespace std;

class Singleton{
private:
    static Singleton *ptr; //private
    static pthread_mutex_t mut;
    Singleton(){
    }
public:
    static Singleton* GetInstance(){
        if(ptr == nullptr){
            pthread_mutex_lock(&mut);
            if(ptr == nullptr){
                try{
                ptr = new Singleton();
                }
                catch(bad_alloc xa){
                    cout<<"Singletion allocation failed"<<endl;
                }
            }
            pthread_mutex_lock(&mut);
        }
        return ptr;
    }
private:
    ~Singleton(){  // Its private because, no one will use delete operator.
        delete ptr;
    }
};

Singleton* Singleton:: ptr = nullptr;
pthread_mutex_t Singleton::mut;

int main(){
    Singleton* ptr = Singleton::GetInstance();
    cout<<ptr<<endl;
    Singleton* ptr2 = Singleton::GetInstance();
    cout<<ptr2<<endl;
    //delete ptr;   //run time error
    Singleton* ptr3 = Singleton::GetInstance();
    cout<<ptr3<<endl;
    return 0;
}