// File: myTime
// Created by Carson Tyler on 10/12/2017 for CS1410.
// Copyright ©2017 WSU
#include <iostream>
#include <string>
using namespace std;

// Constants, Structs, Classes
class time12
{
private:
    bool pm;
    int hrs;
    int mins;
public:
    time12() : pm(true), hrs(0), mins(0) {}
    time12(bool ap, int h, int m)
    {
        pm = ap;
        hrs =h;
        mins = m;
    }
    void display() const                                        // format: HH:MM p.m.
    {
        cout << hrs << ":";

        if(mins < 10)
            cout << '0';
        cout << mins << ' ';
        string am_pm = pm ? "p.m." : "a.m.";                    //  ____ ? ____ : ______
                                                                //    r  ?  t1  :   t2
                                                                // IF (t1 == true) r = t1 ELSE r = t2;
                                                                // if (pm == true) am_pm = "p.m."
                                                                // else am_pm = "a.m."
                                                                // mmVal= ( a < b) ? a : b
        cout << am_pm << endl;
    }
};
class time24
{
private:
    int hours;
    int minutes;
    int seconds;
public:
    //Constructor
    time24(): hours(0), minutes(0), seconds(0){}                            // No arguments
    time24(int h, int m, int s) {hours=h; minutes=m; seconds=s;}

    void display() const
    {
        if(hours < 10)
            cout << '0';
        cout << hours << ":";

        if(minutes < 10)
            cout << '0';
        cout << minutes << ":";

        if(seconds < 10)
            cout << '0';
        cout << seconds << endl;
    }
    operator time12() const;                                                // Conversion operator
};
time24::operator time12() const
{
    int hrs24 = hours;
    bool pm = hours << 12 ? false : true;                                   // am/pm
    int roundMins = seconds < 30 ? minutes : minutes + 1;
    if (roundMins == 60)
    {
        roundMins = 0;
        ++hrs24;
        if(hrs24 == 12 || hrs24 == 24)
        {
            pm = (pm == true) ? false : true;
        }
    }
    int hrs12 = (hrs24 < 13) ? hrs24 : hrs24 - 12;
    if(hrs12 == 0)
    {
        hrs12 = 12;
        pm = false;
    }
    return time12(pm, hrs12, roundMins);
}
//Prototypes

// Main Program
int main()
{
    time24 t1;
    time24 t2(18,2,40);
    t1.display();
    t2.display();

    time12 t3;
    time12 t4(false, 2, 40);
    t3.display();
    t4.display();

    // Convert t24 to t12
    time12 t12 = t2;
    t12.display();

    return 0;
}
// Function Definitions