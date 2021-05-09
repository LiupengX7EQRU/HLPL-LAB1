#include "std_lib_facilities.h"

//1. Define a global vector<int> gv; initialize it with ten ints, 1, 2, 4, 8, 16, etc.
vector<int> gv {1, 2, 4, 8, 16, 32, 64, 128, 256, 512};

//2. Define a function f() taking a vector<int> argument.
void f(vector<int> v)
{
    //3.a. Define a local vector<int> lv with the same number of elements as the argument vector.
    vector<int> lv(v.size());
     
    //3.b. Copy the values from gv into lv.
    lv = gv;
    
    //3.c. Print out the elements of lv.
    for (auto& a : lv)
    cout << a <<"\t";
    cout << '\n';
    
    //3.d. Define a local vector<int> lv2; initialize it to be a copy of the argument vector.
    vector<int> lv2 = v;
    
    //3.e. Print out the elements of lv2.
    for (auto& a : lv2)
    cout << a << "\t";
    cout << '\n';  
}

int main()
{
    //4.a. Call f() with gv as its argument.
    f(gv);

    //4.b. Define a vector<int> vv, and initialize it with the first ten factorial values (1, 2*1, 3*2*1, 4*3*2*1, etc.).
    vector<int> vv(10);
    int temp = 1;
    for (int i = 0; i < vv.size(); ++i)
    {
        temp *= (i+1);
        vv[i] = temp;
    }
    
    //4.c. Call f() with vv as its argument.
    f(vv);
    
    return 0;
}



