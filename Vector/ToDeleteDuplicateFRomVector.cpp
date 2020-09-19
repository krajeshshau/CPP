#include <iostream>
#include<vector>

using namespace std;

int main(){
    
    vector<char>vect{'r','a','j','r','s','h'};
    //vector<char>vect{1,5,2,3,5,4,4,5,6};
    for(auto it = vect.begin(); it != vect.end(); ++it){
        if(*it == 'r'){  
        //if(*it == 5){
            vect.erase(it);
            --it;
        }
    }
    for(auto it:vect)
        cout<<it;

    return 0;
}