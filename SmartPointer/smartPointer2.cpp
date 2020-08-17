#include<iostream>
#include<memory>

using namespace std;

template<class T>
class smartptr{
    private:
    T *ptr;
    public:
    smartptr(T* _ptr = nullptr):ptr(_ptr){
        
    }
    ~smartptr(){
        cout<<"killing smartpointer"<<endl;
        delete ptr;
    }
    T& operator*(){
        return *ptr;
    }
    T* operator->(){
        return ptr;
    }
};

class B{
    public:
    int *arr;
    int size;
    public:
    B(int _size = 0):size(_size),arr(new int[size]){
    }
    ~B(){
        cout<<"killing B"<<endl;
        //delete []arr;
    }
    void setData(){
        for(int i = 0; i < size; i++){
          arr[i] = i*i;
        }
    }
    void getData(){
        for(int i = 0; i < size; i++){
         cout<<arr[i]<<" ";
        }
    cout<<endl;        
    }
};

void display(unique_ptr<B>sptrb2){
    sptrb2->setData();
    sptrb2->getData();    
}
int main(){
    //smartptr sptr(new int());
//    smartptr<B> sptr(new B(20));
//    sptr->setData();
//    sptr->getData();
    //smartptr<B> sptr2 = sptr;
    //sptr2->setData();
    //sptr2->getData();
    
    unique_ptr<B> sptrb(new B(10));
    sptrb->setData();
    sptrb->getData();
    unique_ptr<B> sptrb2 = move(sptrb);
    sptrb2->setData();
    sptrb2->getData();
    display(move(sptrb2));
    return 0;
}