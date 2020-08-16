#include<iostream>
#include<memory>
#include<string>

using namespace std;

class Song{
    string movie;
    string song;
    public:
       Song(string &&mymovie):movie(move(mymovie)){
           //cout<<"Movie is => ";
       }
       ~Song(){
           cout<<"Ending my song!"<<endl;
       }
       void run(){
           
       }
       void selectsong(string mysong){
           //cout<<movie<<endl;
           song = mysong;
           //cout<<song<<endl;
           
       }
       void display(){
           cout<<"Movie => "<<movie<<endl;
           cout<<"Song => "<<song<<endl;
       }
};
/*void run(Song* _mysong){
    _mysong->display();
}
*/
/*void run(const unique_ptr<Song>&_mysong){
    _mysong->display();
}
*/
void run(const unique_ptr<Song>_mysong){
    _mysong->display();
}

void MySong(){
    unique_ptr<Song>mysong(new Song("Rustam"));
    mysong->selectsong("Jo tum chhor ke jaowage ");
    //run(mysong.get());
    //run(mysong);
    run(move(mysong));
}
int main(){
    MySong();
    
    return 0;
}