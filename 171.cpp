#include "std_lib_facilities.h"

//4. Write a function print_array10(ostream& os, int* a) that prints out the values of a to os.
ostream& print_array10(ostream& os, int* a)
{
    for (int i = 0; i < 10; ++i)
        os << a[i] << "  ";
    os << endl;
    return os;
}

//7. Write a function print_array(ostream& os, int* a, int n) that prints out the values of a to os.
ostream& print_array(ostream& os, int* a, int n)
{
    for (int i = 0; i < n; ++i)
        os << a[i] << "  ";
    os << endl;
    return os;
}

ostream& print_vector(ostream& os, vector<int>& v)
{
    for (auto e : v)
        os << e << "  ";
    os << endl;
    return os;
}

int main()
 {
    //1. Allocate an array of ten ints on the free store using new.
    int* array = new int[10];
    for (int i = 0; i < 10; ++i)
        array[i] = i;

    //2. Print the values of the ten ints to cout.
    for (int i = 0; i < 10; ++i)
        cout << array[i] << "  ";
    cout << endl;

    //3. Deallocate the array (using delete[]).
    delete[] array;

    //5. Allocate an array of ten ints on the free store; initialize it with the values 100, 101, 102, etc. And print out its values.
    int* array5 = new int[10];
    int x = 100;
    for (int i = 0; i < 10; ++i)
    {
        array5[i] = x;
        ++x;
    }
    print_array10(cout, array5);
    delete[] array5;

    //6. Allocate an array of 11 ints on the free store; initialize it with the values 100, 101, 102, etc. And print out its values.
    int* array6 = new int[11];
    x = 100;
    for (int i = 0; i < 11; ++i)
    {
        array6[i] = x;
        ++x;
        cout << array6[i] << "  ";
    }
    cout << endl;
    delete[] array6;

    //8. Allocate an array of 20 ints on the free store; initialize it with the values 100, 101, 102, etc. And print out its values.
    //9. Did you remember to delete the arrays? (If not, do it.)
    int* array8 = new int[20];
    x = 100;
    for (int i = 0; i < 20; ++i)
    {
        array8[i] = x;
        ++x;
    }
    print_array(cout, array8, 20);
    delete[] array8;

    //10. Do 5, 6, and 8 using a vector instead of an array and a print_vector() instead of print_array().
    vector <int> b1;
        b1.resize(10);
        for (int i = 0; i < 10; i++) 
            b1[i] = i;
      
        print_vector(cout, b1);

        //6. Allocate an array of 11 ints on the free store; initialize it with the values 100, 101, 102, etc. and print out its values.
        vector <int> c1;
        c1.resize(11);
        for (int i = 0; i < 11; i++) 
            c1[i] = i;
        
        print_vector(cout, c1);

    //8. Allocate an array of 20 ints on the free store; initialize it with the values 100, 101, 102, etc. and print out its values.
        vector <int> d1;
        d1.resize(20);
        for (int i = 0; i < 20; i++) 
            d1[i] = i;
       
        print_vector(cout, d1);
        
    return 0;

}

