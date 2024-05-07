#include <iostream>
#include"Customer.h"
#include"Bank.h"
using namespace std;
int main()
{
    cout <<setw(80)<< "Welcome To Bank Queue Management System"<<endl;
    cout << setw(80) << "***************************************" << endl;
    Bank b1;
    //Testing
    
    //Customer c1;
    //c1.Setname("A");
    //c1.SetTime(35);
    //c1.SetService(62);
    //c1.SetSpecial(0);
    //b1.AddCustomer(c1);

    //Customer c2;
    //c2.Setname("B");
    //c2.SetTime(39);
    //c2.SetService(57);
    //c2.SetSpecial(0);
    //b1.AddCustomer(c2);

    //Customer c3;
    //c3.Setname("C");
    //c3.SetTime(78);
    //c3.SetService(12);
    //c3.SetSpecial(0);
    //b1.AddCustomer(c3);

    //Customer c4;
    //c4.Setname("D");
    //c4.SetTime(80);
    //c4.SetService(50);
    //c4.SetSpecial(0);
    //b1.AddCustomer(c4);

    //Customer c5;
    //c5.Setname("E");
    //c5.SetTime(83);
    //c5.SetService(55);
    //c5.SetSpecial(1);
    //b1.AddCustomer(c5);

    //Customer c6;
    //c6.Setname("F");
    //c6.SetTime(89);
    //c6.SetService(60);
    //c6.SetSpecial(0);
    //b1.AddCustomer(c6);

    //Customer c7;
    //c7.Setname("G");
    //c7.SetTime(99);
    //c7.SetService(50);
    //c7.SetSpecial(1);
    //b1.AddCustomer(c7);

    //Customer c8;
    //c8.Setname("H");
    //c8.SetTime(102);
    //c8.SetService(59);
    //c8.SetSpecial(1);
    //b1.AddCustomer(c8);

    //Customer c9;
    //c9.Setname("I");
    //c9.SetTime(105);
    //c9.SetService(63);
    //c9.SetSpecial(0);
    //b1.AddCustomer(c9);
    int numofcusromers;
    cout << "Enter number of customers : ";
    cin >> numofcusromers;
    for (int i = 0; i < numofcusromers; i++)
    {
        string name;
        int arrivaltime, servicetime;
        int special;
        cout << "Enter details of customer " << i + 1 << ":" << endl;
        cout << "Name : ";
        cin >> name;
        cout << "Arrival time : ";
        cin >> arrivaltime;
        cout << "Service time : ";
        cin >> servicetime;
        cout << "If you vip enter 1 ,else enter 0: ";
        cin >> special;
        Customer customer;
        customer.Setname(name);
        customer.SetTime(arrivaltime);
        customer.SetService(servicetime);
        customer.SetSpecial(special);
        b1.AddCustomer(customer);
        cout << endl;
    }
    b1.Simulate();
   
    return 0;
}

