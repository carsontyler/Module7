// File: assignment.cpp
// Created by Carson Tyler on 10/10/2017 for CS1410.
// Copyright ©2017 WSU
#include <iostream>
#include <string>
using namespace std;

// Constants, Structs, Classes
class Counter
{
private:
    unsigned int count;                     // count
public:
    Counter():count(0){};                   // Constructor

    unsigned int get_count()                // Return scount
    {
        return count;
    }
    Counter operator ++()                      // Increment prefix, 'operator' overloads the operator. We have to add the features
    {
        ++count;
        Counter temp;
        temp.count = count;
        return temp;
    }
};

//Prototypes

// Main Program
int main()
{
    Counter c1, c2, c3;
    cout << "c1 = " << c1.get_count() << endl;
    cout << "c2 = " << c2.get_count() << endl;
    ++c1;
    ++c2;
    cout << "c1 = " << c1.get_count() << endl;
    cout << "c2 = " << c2.get_count() << endl;
    c3 = ++c1;
    cout << "c3 = " << c3.get_count() << endl;

    return 0;
}
// Function Definitions