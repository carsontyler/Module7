// File: casting
// Created by Carson Tyler on 10/12/2017 for CS1410.
// Copyright ©2017 WSU
#include <iostream>
#include <string>
using namespace std;

// Constants, Structs, Classes
class Distance
{
private:
    float MTF;                                            // Meters to feet
    int feet;
    float inches;
public:
    //Constructor
    Distance() : feet(0), inches(0.0), MTF(3.280833F){}         // 1. Constructor with no arguments
    Distance(int meters): MTF(3.280833F)                        // 2. Constructor with one argument
    {
        float fltfeet = MTF * meters;                           // Convert to float feet
        //feet = static_cast<int>(fltfeet);
        feet = int(fltfeet);                                    // Feet is the integer part
        inches = 12*(fltfeet - feet);                           // Inches is what is left
    }

    Distance(int f, float i): MTF(3.290833F)                    // 3. Constructor with two arguments
    {
        feet = f;
        inches = i;
    }
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
    operator float() const                                      // Convert to inches
    {
        float ffeet = inches/12;
        ffeet =+ static_cast<float>(feet);
        return ffeet/MTF;
    }
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
    float mtrs;
    Distance d1;
    Distance d3(5);
    Distance d2(11, 6.25);
    d1.getdist();
    cout << "Distance d1 = "; d1.showdist(); cout << endl;
    cout << "Distance d2 = "; d2.showdist(); cout << endl;
    // Add binary operator support
    d3 = d1 + d2;
    cout << "Distance d3 = "; d3.showdist(); cout << endl;
    mtrs = static_cast<float>(d2);
    d2 += d3;
    cout << "Distance d2 = "; d2.showdist(); cout << endl;
    // Conversion between c-strings and string objects PAGE 348


    return 0;
}
// Function Definitions