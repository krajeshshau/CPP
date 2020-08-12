#include<iostream>

using namespace std;

int compare(const void*ptr1, const void*ptr2){
    int a = *(const int*)ptr1;
    int b = *(const int*)ptr2;
    return a>b;
}

int main()
{
    int arr[]={3,1,4,6,2,9,7,8,5};
    int arr_size = sizeof(arr)/sizeof(arr[0]);
    int arr_ele_size = sizeof(arr[0]);
    qsort(arr,arr_size,arr_ele_size,compare);
    
    for(auto it:arr)
        cout<<it<<"\t";
    cout<<endl;
    return 0;
}
/* OP 
1 2 3 4 5 6 7 8 9
*/
