#include<iostream>
#include<memory>
#include<string>

using namespace std;

class Song{
    private:
    string str;
    public:
    /*Song(string _str):str(_str){
        cout<<str<<endl;
    }*/
    Song(const string& _str):str(_str){
        cout<<str<<endl;
    }
    Song(const string&& _str):str(move(_str)){
        cout<<"move..."<<endl;
        cout<<str<<endl;
    }
    
    void play(){
        cout<<"O my love!"<<endl;
    }
    ~Song(){
        cout<<"Destructor..."<<endl;
    }
};

void MySong(){
    Song *psong = new Song("Playing a song...");
    psong->play();
    delete psong;
}

void display(unique_ptr<Song>&_psong){
    cout<<"displaying..."<<endl;
    _psong->play();
}
void MySmartSong(){
    unique_ptr<Song>psong(new Song("Playing a my song..."));
    //psong->play();
    display(psong);
}

int main(){
    //MySong();
    MySmartSong();
    
    return 0;
}


