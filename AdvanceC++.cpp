Advance C++ feature:

1. Range based loop
list<int> lst;
for(auto it: lst){
++it; cout<<it<<endl;
}

function objects ("functors").
Functors are objects that can be treated as though they are a function or function pointer.
ClassA functor;
functor( 1, 2, 3 );
This code works because C++ allows you to overload operator(), the "function call" operator. The function call operator can take any number of arguments of any types and return anything it wishes to. (It's probably the most flexible operator that can be overloaded; all the other operators have a fixed number of arguments.)

2. Lambda Expression:
Anonymous function object, shortcut for a function object. It can create function object without create class and struct and having overload the function call operator().

   [](){	   
   } 
 [] => Lambda introduce. capture class.
 () => argumentand its optional.
 {} => body of lambda expression.

void comp(auto lmbd){
    if(lmbd(5,6)) cout<<"Greater"<<endl;
    else cout<<"Smaller"<<endl;
}

A. 
[](){
    cout<<"Lambda expression_2"<<endl;
}();  //Anonymous function object(functor) is created here and calling throgh function call operator operator().
B. 
auto fun = [](){
    cout<<"Lambda expression"<<endl;
};    //fun is anonymous object of anonymous class.
fun();
C. 
auto sum = [](auto i, auto j){
    return i+j;
};
cout<<sum(5,6.5)<<endl;
D.
comp([](int x, int y){
    return x > y;
}); 
 
3. all_of();
This function operates on whole range of array elements and can save time to run a loop to check each elements one by one. It checks for a given property on every element and returns true when each element in range satisfies specified property, else returns false.

    array<int,5>arr = {1,2,3,4,5};
    auto ret = all_of(arr.begin(),arr.end(), [](int x){ return x > 0;} );
    if(ret) cout<<"All are positive elements\n";
    else cout<<"All are not positive elements\n";

4.  any_of();
This function checks for a given range if there’s even one element satisfying a given property mentioned in function. Returns true if at least one element satisfies the property else returns false.

    array<int,5>arr = {1,2,-3,4,5};
    auto ret = any_of(arr.begin(),arr.end(), [](int x){ return x < 0;} );
    if(ret) cout<<"-ve number present in array\n";
    else cout<<"all are +ve numbere present in array\n";

5. none_of()
This function returns true if none of elements satisfies the given condition else returns false.

	auto ret = none_of(arr.begin(),arr.end(), [](int x){ return x < 0;} );
	
6. copy_n()
copy_n() copies one array elements to new array. This type of copy creates a deep copy of array. This function takes 3 arguments, source array name, size of array and the target array name.

	copy_n(source, size, dest);

7. iota()
This function is used to assign continuous values to array.
	int arr[6] = {0};
	iota(arr, arr+6, 20);  //It fill 20 to all six element

8.  Initialization in Binary form: In C++ 11 assignments can also be made in binary form.
	auto number = 0b011; 
    cout << number;  OP 3

9. Use of “and” and "or" instead of && and ||
	int a = 10; 
    if (a < 20 and a > 5)

10. move semantics and rvalue references
When any function return an object then that time temporary objects create. Sometimes these temporary objects can be optimized away by the compiler (the return value optimization, for example). But this is not always the case, and it can result in expensive object copies. rvalue references are perfect for detecting if a value is temporary object or not. Rvalue references use the && syntax instead of just &.
A copy constructor, takes an instance of an object as its argument and creates a new instance based on the original object. However, the move constructor can avoid memory reallocation because we know it has been provided a temporary object, so rather than copy the fields of the object, we will move them.

11. threading

std::mutex mut;
void CallBackFun(string message){
	mut.lock();  //lock_guard<mutex> lock(mut);
	mut.unlock();

//In case of deadlock 
1. std::scoped_lock lock{muA, muB};
2. we can use a "timed mutex"	

//to put sleep 
std::this_thread::sleep_for(std::chrono::seconds(1));
}

thread t1(CallBackFun, "Hello from Jupiter"); //Create thread by default joinable

t1.join();
t1.detach();
if(t1.joinable())

/*
A thread object is said to be joinable if it identifies/represent an active thread of execution.

A thread is not joinable if:

It was default-constructed
If either of its member join or detach has been called
It has been moved elsewhere
*/



12. smart pointers
unique_ptr<A> ptr, shared_ptr<A> ptr, weak_ptr<A> ptr

13. initilizer list {}

14. std::string_view
Conceptually, string_view is only a view of the string and cannot​ be used to modify the actual string.

15. std::variant
This creates a variant that can store either an int or a string at a time.  
std::variant< int, std::string > var;
var = "hello"s;
auto str = std::get<std::string>(var);
var = 10;

16. std::any
any provides a type-safe container to store single value of any type.
any_cast<type>( i ) to convert i value into its original type.
 
any i = 42; 
cout <<any_cast<int>(i); 

17. 


