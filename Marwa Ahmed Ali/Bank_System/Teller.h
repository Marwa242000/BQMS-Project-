#pragma once
#include <iostream>
using namespace std;
class Teller
{
	int IsAvailable = 1;
	int NumberOfTellers;//1 2 3
	int AvailableTime;
	int TotalServedNumber;//number of customers 
	int TotalTimeServed;
public:
	void SetAvailabilty(int available) {
		IsAvailable = available;
	}
	void SetNumberOfTellers(int numbers) {
		NumberOfTellers = numbers;
	}
	void SetAvailableTime(int time) {
		AvailableTime = time;
	}
	
	void SetTotalTimeServed(int totalTime) {
		 TotalTimeServed += totalTime;
	}
    int GetAvailabilty() {
		return IsAvailable;
	}
	int GetNumberOfTellers() {
		return NumberOfTellers;
	}
	int GetAvailableTime() {
		return AvailableTime;
	}
	int GetTotalServedNumber() {
		return TotalServedNumber;
	}
	int GetTotalTimeServed() {
		return TotalTimeServed;
	}
	void IncrementTotalServedNumber() {
		TotalServedNumber++;
	}
	
};

