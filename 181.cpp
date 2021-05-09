#include "std_lib_facilities.h"

//1. Define a global int array ga of ten ints initialized to 1, 2, 4, 8, 16, etc.
int ga[10] = { 1, 2, 4, 8, 16, 32, 64, 128, 256, 512 };
//2. Define a function f() taking an int array argument and an int argument indicating the number of elements in the array.
void f(int ai[], int n)
{
    //3.a. Define a local int array la of ten ints.
    int la[10] = { };
    
    //3.b. Copy the values from ga into la.
    for (int i = 0; i < n; ++i) la[i] = ga[i];
    
    //3.c. Print out the elements of la.
    std::cout << "Local copy\n";
    for (const auto& a : la)
        std::cout << a << ' ';
    std::cout << '\n';
    
    //3.d. Define a pointer p to int and initialize it with an array allocated on the free store with the same number of elements as the argument array.
    int* p = new int[n];
    
    //3.e. Copy the values from the argument array into the free-store array.
    for (int i = 0; i < n; ++i) p[i] = ai[i];
    std::cout << "Pointer to free store\n";
    
    //3.f. Print out the elements of the free-store array.
    for (int i = 0; i < n; ++i)
        std::cout << p[i] << ' ';
    std::cout << '\n';
    
    //3.g. Deallocate the free-store array.
    delete[] p;
}

int fac(int n) { return n > 1 ? n*fac(n-1) : 1; }

int main()
{
    //4.a. Call f() with ga as its argument.
    std::cout << "Binary array\n";
    f(ga, 10);
    //4.b. Define an array aa with ten elements, and initialize it with the first ten factorial values (1, 2 * 1, 3 * 2 * 1, 4 * 3 * 2 * 1, etc.).
    int aa[10] = {};
    for (int i = 0; i < 10; ++i)
        aa[i] = fac(i + 1);

    std::cout << "Factorial array\n";
    //4.c. Call f() with aa as its argument.
    f(aa, 10);
}

