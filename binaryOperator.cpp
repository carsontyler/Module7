// File: binaryOperator
// Created by Carson Tyler on 10/10/2017 for CS1410.
// Copyright ©2017 WSU
#include <iostream>
#include <string>
using namespace std;

// Constants, Structs, Classes
class Distance
{
private:
    int feet;
    float inches;
public:
    //Constructor
    Distance() : feet(0), inches(0.0){}                         // No arguments
    Distance(int f, float i) {feet = f; inches = i;}            // Two arguments

    void getdist()                                              // Get the length for the user
    {
        cout << "\nEnter feet: ";
        cin >> feet;
        cout << "Enter inches: ";
        cin >> inches;
    }
    void showdist()                                             // Display distance
    {
        cout << feet << "\'-" << inches << "\"" << endl;
    }
    Distance operator + (Distance) const;                       // Add 2 distances
    void operator += (Distance);
};
//Prototypes, Return sum
Distance Distance::operator+(Distance d2) const
{
    int f = feet + d2.feet;
    float i = inches + d2.inches;
    while (i >= 12.0)
    {
        i -= 12.0;
        f++;
    }
    return Distance(f,i);
}
void Distance::operator+=(Distance d2)
{
    feet += d2.feet;
    inches += d2.inches;
    while (inches >= 12.0)
    {
        inches -= 12.0;
        feet++;
    }
}
// Main Program
int main()
{
    Distance d1, d3;
    Distance d2(11, 6.25);
    d1.getdist();
    cout << "Distance d1 = "; d1.showdist(); cout << endl;
    cout << "Distance d2 = "; d2.showdist(); cout << endl;
    // Add binary operator support
    d3 = d1 + d2;
    cout << "Distance d3 = "; d3.showdist(); cout << endl;
    d2 += d3;
    cout << "Distance d2 = "; d2.showdist(); cout << endl;


    return 0;
}
// Function Definitions