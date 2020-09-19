#include <iostream>
#include <thread>
#include <algorithm>
#include<vector>
#include<mutex>
#include <condition_variable>
#include<future>

using namespace std;

class WorkerThread {
    int data;
    static std::mutex mut;
    static condition_variable cv;
    static int count;
    static int flag;
public:
     WorkerThread(/*int _data = 0*/)/*:data(_data)*/{ data = 0; count = 0;
     }
    void operator()()     
    {
        std::cout<<"Worker Thread "<<std::this_thread::get_id()<<" is Executing"<<std::endl;
    }
    void display(int _i){
        cout<<"Assigning pointer to member function of a class as thread function:"<<_i<<endl;
    }
    
    static void print(string const &str){
        cout<<"Starting thread with static member function "<<str<<endl;
    }
    
    void set(int _data){
        lock_guard<mutex> lg(mut);
        data+= _data;
    }
    void get(){
        lock_guard<mutex> lg(mut);
        cout<<"data "<<data<<endl;
    }
    
    void increment_1(){
        //while(count != 10){
        do{
            unique_lock<mutex> lg(mut);
            ++count;
            cv.notify_one();
            flag = true;
            lg.unlock();
            //cout<<this_thread::get_id()<<" "<<count<<endl;
            cout<<"increment_1 "<<count<<endl;
            //this_thread::sleep_for(chrono::milliseconds(2));
        }while(count != 10);
    }

    void increment_2(){
        //while(count != 10){
        do{
            unique_lock<mutex> lg(mut);
            cv.wait(lg, [](){ return flag; });
            ++count;
            flag = false;
            lg.unlock();
            //cout<<this_thread::get_id()<<" "<<count<<endl;
            cout<<"increment_2 "<<count<<endl;
            //this_thread::sleep_for(chrono::milliseconds(2));
        }while(count != 10);
    }    
    
};

int WorkerThread::count = 0;
mutex WorkerThread::mut;
condition_variable WorkerThread:: cv;
int WorkerThread::flag = false;

void function_pointer ()
{
  cout << "thread function_pointer" << endl;
}

void call_back(int _i, string _str){
    ++_i;
    _str = "Rakesh";
    cout<<"From thread "<<_i<<_str<<endl;
}

class threadRAII{
  thread &th;
  public:
  threadRAII(thread &_th):th(_th){
  }
  ~threadRAII(){
      if(th.joinable()){
          //th.detach();
          th.join();
      }
  }
};

/*void future_promise_callback_fun(promise<int> * _promiseObj){
    cout<<"inside thread setting value"<<endl;
    _promiseObj->set_value(100);
}
*/
void future_promise_callback_fun(promise<int> * _promiseObj1,promise<int> * _promiseObj2){
    cout<<"inside thread setting value"<<endl;
    _promiseObj1->set_value(100);
    _promiseObj2->set_value(200);
}

int main()  {
/*    thread thfp(function_pointer);
      thfp.join();
*/

/*    thread thObjectfun((WorkerThread()));
      thObjectfun.join();
*/

/*    thread thLambda([](){
        cout<<"thread lambda"<<endl;
    });
    thLambda.join();
*/

/*    vector<thread> threadList;
    for(int i = 0; i < 5; i++){
        threadList.push_back( thread( WorkerThread() ) );
    }
    for(auto it = threadList.begin(); it != threadList.end(); ++it){
        it->join();
    }
*/    
/*    int i{10};
    string str{"Rajesh"};
    thread th(call_back, i, str);
    threadRAII raii(ref(th));
    cout<<"From main "<<i<<str<<endl;
*/    
    //this_thread::sleep_for(chrono::milliseconds(10));
    
    //Assigning pointer to member function of a class as thread function:
/*    WorkerThread wth;
    int i = 10;
    thread th(&WorkerThread::display,&wth,i);
    th.join();
*/

/*    thread th(&WorkerThread::print,"Rajesh");
    th.join();
*/

/*    WorkerThread wt;
    thread thget(&WorkerThread::get, &wt);
    thread thset(&WorkerThread::set,&wt, 100);
    thget.join();
    thset.join();
*/
    
/*    WorkerThread wt1;
    WorkerThread wt2;
    thread th1(&WorkerThread::increment_1, &wt1);
    thread th2(&WorkerThread::increment_2, &wt2);
    th1.join();
    th2.join();
*/
    
/*    promise<int> promiseObj;
    future<int> futureObj = promiseObj.get_future();
    thread th(future_promise_callback_fun, &promiseObj);
    cout<<"value set through promise "<<futureObj.get();
    th.join();
*/

/*    promise<int> promiseObj1,promiseObj2;
    future<int> futureObj1 = promiseObj1.get_future();
    future<int> futureObj2 = promiseObj2.get_future();
    thread th(future_promise_callback_fun, &promiseObj1, &promiseObj2);
    cout<<"value set through promise "<<futureObj1.get()<<endl;
    cout<<"value set through promise "<<futureObj2.get()<<endl;
    th.join();
*/

    
    
    return 0;
}

