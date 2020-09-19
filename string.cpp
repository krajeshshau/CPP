#include<iostream>
#include<string>
#include<map>
#include<list>
#include<algorithm>
#include <sstream>

using namespace std;

int main(){

{
    string str {"abcgsbarrttb"};
    map<char,int>mp;
    map<char,int>::iterator it;
    for(auto it:str) 
        mp[it]++;
    for(it = mp.begin(); it != mp.end(); ++it)
        cout<<it->first<<it->second;
    cout<<endl;
//OP a2b3c1g1r2s1t2
}

{
//2. To find out substring
string str {"http://www.cisco.com"};
string ch("c");

size_t found = str.find(ch);
int count  = 0;

for(; found != string::npos; ){
    cout<<"sub string "<<ch<<" found at "<<found<<endl;
	++count;
    found = str.find(ch, found+1);
}
cout<<"Total occurance of substr "<<ch<<" is "<<count<<endl;
}

{
//3. Delete all occurance of char from the string
string str = "rajesah";
cout << "Initial string: " << str << endl;
str.erase(remove(str.begin(), str.end(), 'a'), str.end()); //remove 'a' from string
cout << "final string: " << str << endl;
}

{
//4. Find & Replace all sub strings

    string str = "Boost Library is simple C++ Library";
    string toSearch = "Lib";
    string replaceStr = "XXX";
    size_t pos = str.find(toSearch);
    while( pos != std::string::npos) {
		str.replace(pos, toSearch.size(), replaceStr);
        pos = str.find(toSearch, pos + replaceStr.size());
    }
    cout<<str<<endl;
}

//5. To find substr
{
    string str = "hello world, this is a test";
    string fragment = str.substr(6,5);
    cout<<fragment <<endl;  //OP world
}

//6. To convert Strings to Numbers
{
    string str{"12345"};
    stringstream ss(str);
    int num;
    ss>>num;
    //Second methoh
    int data = 0;
    for(auto it: str){
        data = data * 10 + it - '0';
    }
}
    return 0;
}