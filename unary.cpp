#include <iostream>
using namespace std;

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
    void operator ++()                      // Increment prefix, 'operator' overloads the operator. We have to add the features
    {
        ++count;
    }
};

int main()
{
    Counter c1, c2;
    cout << "c1 = " << c1.get_count() << endl;
    cout << "c2 = " << c2.get_count() << endl;
    ++c1;
    ++c2;
    ++c2;
    ++c2;
    ++c2;
    cout << "c1 = " << c1.get_count() << endl;
    cout << "c2 = " << c2.get_count() << endl;
    // c1 = ++c2;

    return 0;
}