#include<iostream>
#include<vector>
#include <bits/stdc++.h> 

using namespace std;

int main(){

std::vector<int> v = { 1, 2, 3, 4, 5, 6 };
auto it = v.begin();

cout<<"size of vector "<<v.size()<<endl;

while (it != v.end()){
    // remove even numbers
	if ((*it%2) == 0) {
	    //it = v.erase(it);
	    v.erase(it); --it;
	}
	else {
		++it;
	}
}

for (int const &i: v) {
	std::cout << i << ' ';
}

cout<<"\n remove and erase"<<endl;
//remove:  It doesn’t actually delete elements from the container but only shunts non-deleted elements forwards on top of deleted elements.
//erase: Removes from the vector either a single element (position) or a range of elements ([first, last)).

    std::vector<int> vec{ 10, 20, 30, 30, 20, 10, 10, 20 }; 
    cout<<"size = "<<vec.size()<<endl;  //8
    std::vector<int>::iterator pend; 
  
    // std :: remove function call 
    pend = std::remove(vec.begin(), vec.end(), 20); 
    cout<<"size2 = "<<vec.size()<<endl;  //8
    // Print the vector after std :: remove 
    for (std::vector<int>::iterator p = vec.begin(); p != pend; ++p) 
        std::cout << ' ' << *p; std::cout << '\n'; 
  vec.erase(pend,vec.end());
  cout<<"size3 = "<<vec.size()<<endl;





return 0;
}
