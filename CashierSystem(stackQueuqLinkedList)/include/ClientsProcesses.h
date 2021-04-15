#ifndef ClientsProcesses_H
#define ClientsProcesses_H
#include "LinkedList.h"
#include <string>


class ClientsProcesses
{
    int ProcessBurstTime,ArrivalTime,EndTime,Counter=0,StartedAtTime = -1,TotalTime,BurstTemp;

    string Name;

public:
    LinkedList<int> Interrupts;
    ClientsProcesses(string pname,int stime,int ptime,LinkedList<int> interrs)
    {
        Name = pname;
        ProcessBurstTime = ptime;
        ArrivalTime = stime;
        Interrupts = interrs;
        BurstTemp = ptime;
    };
    string GetName()
    {
        return Name;
    }
    int getBurstTemp()
    {
        return BurstTemp;
    }
    void SetProcessBurstTime(int ptime)
    {
        ProcessBurstTime = ptime;
    }
    int GetProcessBurstTime()
    {
        return ProcessBurstTime;
    }

    int GetArrivalTime()
    {
        return ArrivalTime;
    }
    bool HasInterrupts()
    {
        if(Interrupts.getListCounter()==0)
            return false;
        else
            return true;
    }
    void RemoveInterrupt()
    {
        Interrupts.DeleteByIndex(0);
    }
    int GetInterruptTime()
    {
        return  Interrupts.FirstElement();
    }
    void SetEndTime(int etime)
    {
        EndTime = etime;
    }
    int GetEndTime()
    {
        return EndTime;
    }
    void SetCounter(int iatime)
    {
        Counter = iatime;
    }
    int GetCounter()
    {
        return Counter;
    }
    void SetStartedAtTime(int satime)
    {
        StartedAtTime = satime;
    }
    int GetStartedAtTime()
    {
        return StartedAtTime;
    }
    void SetTotalTime(int time)
    {
        TotalTime = time;
    }
    int GetTotalTime()
    {
        return TotalTime;
    }
    int GetWaitTime()
    {
        return GetTotalTime()-BurstTemp;
    }
    bool operator> (const ClientsProcesses &c2)
    {
        return this->ArrivalTime > c2.ArrivalTime;
    }

};

#endif
