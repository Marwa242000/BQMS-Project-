#pragma once
#include <iostream>
#include<string>
using namespace std;
class Customer
{
    string Name;
    int ArrivalTime;
    int ServiceTime;
    int LeaveTime;
    int WaitingTime;
    int IsSpecial;
 

public:
    
     Customer(){
         Name = "";
         ArrivalTime = 0;
         ServiceTime = 0;
         IsSpecial = 0;
     }
     
     void Setname(string name) {
         Name = name;
     }
     void SetTime(int time) {
         ArrivalTime = time;
     }
     void SetService(int service) {
         ServiceTime = service;
     }
     void SetWaitingTime(int wTime) {
         WaitingTime = wTime;
     }
     void SetLeaveTime(int lTime) {
         LeaveTime = lTime;
     }
     void SetSpecial(int special) {
         IsSpecial = special;
     }
     string GetName() {
         return Name;
     }
     int GetTime()const {
         return ArrivalTime;
     }
     int GetService() {
         return ServiceTime;
     }
     int GetWaitingTime() {
         return WaitingTime;
     }
     int GetLeaveTime() {
         return LeaveTime;
     }
     int GetSpecial() const {
         return IsSpecial;
     }
   
};

