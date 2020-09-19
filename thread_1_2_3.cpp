#include <iostream>
#include<thread>
#include<mutex>
#include<condition_variable>

using namespace std;

mutex mut;
condition_variable cv;
int done = 1;

void call_back(int th){
    while(1){
        unique_lock<mutex> lock(mut);
        if(done != th){
            if(th == 1)
                cv.wait(lock, [](){ if(done == 1) return 1;});
            else if(th == 2)
                cv.wait(lock, [](){ if(done == 2) return 1;});
            else
                cv.wait(lock, [](){ if(done == 3) return 1;});
        }
        cout<<done<<endl;
        if(done == 1) done = 2;
        else if(done == 2) done = 3;
        else done = 1;
        lock.unlock();
    }
}

int main(){
    
    int count1 = 1, count2 = 2, count3 = 3;
    thread th1(call_back,count1);
    thread th2(call_back,count2);
    thread th3(call_back,count3);
    th1.join();
    th2.join();
    th3.join();

    return 0;
}