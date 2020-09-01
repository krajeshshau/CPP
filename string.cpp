#include<iostream>
#include<string>
#include<map>
#include<list>
#include<algorithm>

using namespace std;

int main(){

//1.
/*    string str {"abcgsbarrttb"};
    map<char,int>mp;
    map<char,int>::iterator it;
    for(auto it:str) 
        mp[it]++;
    for(it = mp.begin(); it != mp.end(); ++it)
        cout<<it->first<<it->second;
//OP a2b3c1g1r2s1t2
*/

//2. To find out substring
/*string str {"http://www.cisco.com"};
string ch("c");

size_t found = str.find(ch);
int count  = 1;

for(; found != string::npos; ){
    cout<<count<<" sub string found"<<endl;
    found = str.find(ch, found+1);
    ++count;
}
*/

//3. Delete all occurance of char from the string
/*string str = "rajesah";
cout << "Initial string: " << str << endl;
str.erase(remove(str.begin(), str.end(), 'a'), str.end()); //remove 'a' from string
cout << "final string: " << str << endl;
*/




   
    return 0;
}