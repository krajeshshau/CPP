#include <stdio.h> 
#include<iostream>

using namespace std;

int main(void) {
    
    int x = 19, y = 20;
    cout<<(x << 1)<<endl;   //Left shift i.e multiplication by 2 => 38
    cout<<(x >> 1)<<endl;   //Right shift i.e division by 2       => 9
    
    (x & 1) ? cout<<"Odd"<<endl : cout<<"Even"<<endl; //To check Odd Even.
    
    cout<<(x&y)<<endl;    // Anding  => 16
    cout<<(x|y)<<endl;    //ORing    => 23
    cout<<(x^y)<<endl;    //The result of bitwise XOR operator is 1 if the corresponding bits of two operands are opposite.
    cout<<(~x)<<endl;     //It changes 1 to 0 and 0 to 1, Inverting every bit of a number/1’s complement.
    cout<<(~x + 1)<<endl;     //Two’s complement of the number: 2’s complement of a number is 1’s complement + 1.
    
    //The Quickest way to swap two numbers:
    x ^= y; y ^= x;  x ^= y;
    
    //How to set a bit at n’th position in the number ‘num’ :
{   int num = 10, pos = 2;  //pos start from 0th bit
    num = num | (1 << pos);
    cout<<num<<endl;
}    
    //How to unset/clear a bit at n’th position in the number ‘num’
{   int num = 7, pos = 1;
    num = num & (~(1 << pos));
    cout<<num<<endl;
}        
    //Toggling a bit at nth position :
    //Toggling means to turn bit ‘on'(1) if it was ‘off'(0) and to turn ‘off'(0) if it was ‘on'(1)
{   int num = 4, pos = 1;
    num = num ^ (1 << pos);
    cout<<num<<endl;
}  

    //Checking if bit at nth position is set or unset:
{   int num = 4, pos = 1;
    bool flag = false;
    flag = num & (1 << pos);
    cout<<flag<<endl;
}

{
    char ch = 'A';
    ch = ch | ' ';  //Upper case English alphabet to lower case
    cout<<ch<<endl;
    ch = ch & '_';  // Lower case English alphabet to upper case
    cout<<ch<<endl;
}

{   //To count set bit
    int count = 0;
    int x = 10;
    while (x) 
    { 
        x &= (x-1); 
        count++; 
    }
    cout<<count<<endl;
}
    return 0; 
} 