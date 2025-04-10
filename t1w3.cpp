#include<iostream>
using namespace std;

class InvalidTimeException {};

class add
{
private:
    int hour;
    int minute;

public:
    add() { hour = minute = 0; }
    add(int a, int b)
    {
        if (a > 24 || b >= 60)
        {
            throw InvalidTimeException();
        }
        hour = a;
        minute = b;
    }

    add operator+(add A)
    {
        add temp;
        temp.minute = minute + A.minute;
        int tt = temp.minute / 60;
        temp.minute = temp.minute % 60;
        temp.hour = tt + hour + A.hour;

        if (temp.hour > 24)
        {
            throw InvalidTimeException();
        }
        return temp;
    }

    void display()
    {
        cout << "hour=" << hour << endl << "minute=" << minute << endl;
    }
};

int main()
{
    try {
    int hour, minute;

    cout << "Enter timestamp:"<<endl<< "Hour:"<<endl;
    cin >> hour;
    cout << "Minute:" << endl;
    cin >> minute;
    add A1(hour, minute);

    cout << "Enter Another timestamp:"<<endl<< "Hour:"<<endl;
    cin >> hour;
    cout << "Minute:" << endl;
    cin >> minute;
    add A2(hour, minute);
    add A3 = A1 + A2;
    A3.display();

    } catch (InvalidTimeException &e) {
        cout << "Invalid input! Hours must be less than or equal to 24 and minutes must be less than 60." << endl;
    }

    return 0;
}
