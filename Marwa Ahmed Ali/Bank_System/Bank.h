#pragma once
#include <iostream>
#include <deque>
#include <algorithm> // For std::sort
#include "Customer.h"
#include <iomanip> // for std::setw
#include <windows.h>
using namespace std;

struct Teller {
    int IsAvailable = 1;
    int NumberOfTellers; //1 2 3
    int AvailableTime;
    int TotalServedNumber; //number of customers 
    int TotalTimeServed;
};

class Bank {
    deque<Customer> customersQueue;
    int teller_num = 3;
    int totalServeTime;
    int totalWaitingTime;
    Teller* tellers;

public:
    //void AddCustomer(Customer customer) {
    //    customersQueue.push_back(customer);
    //    // Sort customers based on arrival time
    //    sort(customersQueue.begin(), customersQueue.end(), [](const Customer& a, const Customer& b) {
    //        return a.GetTime() < b.GetTime();
    //        });

    //}
    void AddCustomer(Customer c)
    {
        customersQueue.push_back(c);
        sort(customersQueue.begin(), customersQueue.end(), [](const Customer& a, const Customer& b) {
            if (a.GetTime() == b.GetTime()) {
                // If arrival times are equal, prioritize special customers
                return a.GetSpecial() > b.GetSpecial();
            }
            // Otherwise, sort based on arrival time
            return a.GetTime() < b.GetTime();
            });
    }

    Bank() {
        tellers = new Teller[teller_num];
        for (int i = 0; i < teller_num; ++i) {
            tellers[i].IsAvailable = 1;
            tellers[i].NumberOfTellers = i + 1;
            tellers[i].TotalServedNumber = 0;
            tellers[i].AvailableTime = 0;
            tellers[i].TotalTimeServed = 0;
        }
    }

    ~Bank() {
        delete[] tellers;
    }

    void Simulate() {
        
        SetColor(11);
        cout <<setw(70)<< "Customers Details " << endl;
        SetColor(15);
        cout << endl;
        printHeader();
        while (!customersQueue.empty()) {
            Customer currentCustomer = customersQueue.front();

            int NormalServed = 0;

            for (int i = 0; i < teller_num; ++i) {
                if (tellers[i].IsAvailable) {
                    currentCustomer.SetWaitingTime(0);
                    currentCustomer.SetLeaveTime(currentCustomer.GetService() + currentCustomer.GetTime());
                    DisplayCustomerDetails(currentCustomer, tellers[i]);
                    tellers[i].IsAvailable = 0;
                    tellers[i].AvailableTime = currentCustomer.GetLeaveTime();
                    tellers[i].TotalServedNumber++;
                    tellers[i].TotalTimeServed += currentCustomer.GetService();
                    totalServeTime += currentCustomer.GetService();
                    totalWaitingTime += currentCustomer.GetWaitingTime();
                    customersQueue.pop_front();
                    NormalServed = 1;
                    break;
                }
            }

            if (!NormalServed)
            {
                Teller* nearTeller = findNearTeller();
                int VipServed = 0;
                int index = customersQueue.size(); 

                for (int i = 0; i < customersQueue.size() && customersQueue[i].GetTime() <= nearTeller->AvailableTime; i++)
                {
                    if (customersQueue[i].GetSpecial())
                    {
                        currentCustomer = customersQueue[i];
                        nearTeller->IsAvailable = 1;
                        nearTeller->TotalServedNumber++;
                        if (nearTeller->AvailableTime < currentCustomer.GetTime())
                        {
                            currentCustomer.SetWaitingTime(0);
                        }
                        else {
                            currentCustomer.SetWaitingTime(nearTeller->AvailableTime - currentCustomer.GetTime());

                        }

                        currentCustomer.SetLeaveTime(currentCustomer.GetTime() + currentCustomer.GetWaitingTime() + currentCustomer.GetService());
                        DisplayCustomerDetails(currentCustomer, *nearTeller);
                        totalServeTime += currentCustomer.GetService();
                        totalWaitingTime += currentCustomer.GetWaitingTime();
                        nearTeller->TotalTimeServed += currentCustomer.GetService();
                        nearTeller->AvailableTime = currentCustomer.GetLeaveTime();
                        nearTeller->IsAvailable = 0;
                        // customersQueue.pop_front();
                        index = i;
                        VipServed = 1;
                        break;
                    }
                }
                if (VipServed && index != customersQueue.size())
                {
                    customersQueue.erase(customersQueue.begin() + index);
                }
                if (!VipServed)
                {
                    nearTeller->IsAvailable = 1;
                    nearTeller->TotalServedNumber++;
                    if (nearTeller->AvailableTime < currentCustomer.GetTime())
                    {
                        currentCustomer.SetWaitingTime(0);
                    }
                    else {
                        currentCustomer.SetWaitingTime(nearTeller->AvailableTime - currentCustomer.GetTime());

                    }
                    currentCustomer.SetLeaveTime(currentCustomer.GetTime() + currentCustomer.GetWaitingTime() + currentCustomer.GetService());
                    DisplayCustomerDetails(currentCustomer, *nearTeller);
                    totalServeTime += currentCustomer.GetService();
                    totalWaitingTime += currentCustomer.GetWaitingTime();
                    nearTeller->TotalTimeServed += currentCustomer.GetService();
                    nearTeller->AvailableTime = currentCustomer.GetLeaveTime();
                    nearTeller->IsAvailable = 0;
                    customersQueue.pop_front();
                }


                
            }


        }
        
        DisplayTellerDetails();
        DisplayBankDetails();
    }

    Teller* findNearTeller() {
        Teller* nearTeller = nullptr;
        int nearAvailableOne = INT_MAX;
        for (int i = 0; i < teller_num; ++i) {
            if (tellers[i].AvailableTime < nearAvailableOne) {
                nearAvailableOne = tellers[i].AvailableTime;
                nearTeller = &tellers[i];
            }
        }
        return nearTeller;
    }

    
    void printHeader() {
            cout << setw(10) << "Customer Name"
            << setw(15) << "Waiting Time"
            << setw(15) << "Service Time"
            << setw(15) << "Leave Time"
            << setw(33) << "Served with Teller Number"
            << setw(14) << "Type"
            << endl;

        
        cout << setw(20)<<string(120, '-') << endl;
    }
    void DisplayCustomerDetails(Customer c, Teller t) {
        int Is_Special = (c.GetSpecial()) ? 1 : 0;

        cout << setw(10) << c.GetName()
            << setw(15) << c.GetWaitingTime()
            << setw(15) << c.GetService()
            << setw(15) << c.GetLeaveTime()
            << setw(25) << t.NumberOfTellers
            << setw(25) << Is_Special
            << endl;
        cout << setw(20) << string(120, '-') << endl;
    }

    void printTellerHeader() {
       
        cout <<setw(40) << "Teller Number"
            << setw(25) << "Total Time Served"
            << setw(35) << "Number of Customers Served"
            << endl;

        cout << setw(20) << string(120, '-') << endl;
    }

    void DisplayTellerDetails() {
        SetColor(11);
        cout << endl;
        cout << endl;
        cout << setw(70)<< "Tellers Details : " << endl;
        SetColor(15);
        cout << endl;
        cout << endl;
        
        printTellerHeader();

        for (int i = 0; i < teller_num; i++) {
            cout << setw(35) << tellers[i].NumberOfTellers
                << setw(25) << tellers[i].TotalTimeServed
                << setw(30) << tellers[i].TotalServedNumber
                << endl;
        }
        cout << setw(20) << string(120, '-') << endl;

    }

    void printBankDataHeader() {
        cout <<setw(50) << "Total Service Time"
            << setw(30) << "Total Waiting Time"
            << endl;

        cout << string(120, '-') << std::endl;
    }

    void DisplayBankDetails() {
        cout << endl;
        SetColor(11);
        cout <<setw(70)<<"Bank Details : " << endl;
        SetColor(15);
        cout << endl;
        cout << endl;

        printBankDataHeader();

       cout <<setw(40) << totalServeTime
            << setw(30) << totalWaitingTime
            << endl;
       cout << setw(20) << string(120, '-') << endl;

    }
    void SetColor(int ForgC)
    {
        WORD wColor;
        HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
        CONSOLE_SCREEN_BUFFER_INFO csbi;

        if (GetConsoleScreenBufferInfo(hStdOut, &csbi))
        {
            wColor = (csbi.wAttributes & 0xF0) + (ForgC & 0x0F);
            SetConsoleTextAttribute(hStdOut, wColor);
        }
    }
};
