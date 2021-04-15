#ifndef CLIENTSROUNDROBIN_H
#define CLIENTSROUNDROBIN_H
#include "ClientsProcesses.h"
#include "Stack.h"
#include "Queue.h"
#include "LinkedList.h"

class ClientsRoundRobin
{
public:
    LinkedList<ClientsProcesses> Clients;
    Queue<ClientsProcesses> WaitingQ;
    Queue<ClientsProcesses> TempQ;
    LinkedList<Stack<ClientsProcesses>> Agents;
    int time = 0,   flag =0;
    int Count=0;
    void addCustToQueue()
    {
        if(Clients.getListCounter()!=0)
        {
            for(int i = 0 ; i<Clients.getListCounter(); i++ )
            {
                if(Clients.getElementByIndex(0)->GetArrivalTime() == time )
                {
                    WaitingQ.Enqueue(Clients.getElementByIndex(0));
                    cout<<"Mr "<<Clients.getElementByIndex(0)->GetName()<<" has arrived!"<<endl;
                    Clients.DeleteByIndex(0);
                }
            }
        }
    }
    void pushCustForCashier(int index)
    {
        WaitingQ.GetDequeue()->SetEndTime(time+WaitingQ.GetDequeue()->GetProcessBurstTime());
        if(WaitingQ.GetDequeue()->GetStartedAtTime() == -1)
        {
            WaitingQ.GetDequeue()->SetStartedAtTime(time);
        }
        Agents.getElementByIndex(index)->Push(WaitingQ.GetDequeue());
        WaitingQ.Dequeue();
        cout<<"Window No. "<<index+1<<" is now Empty, Its Client "<<Agents.getElementByIndex(index)->GetTop()->GetName()<<" turn now"<<endl;

    }


    void popAndEnqueueIfInterrupt(int index)
    {
        Agents.getElementByIndex(index)->GetTop()->RemoveInterrupt();
        WaitingQ.Enqueue(Agents.getElementByIndex(index)->GetTop());
        cout<<Agents.getElementByIndex(index)->GetTop()->GetName()<<" has temporarily left Window No. "<<index+1<<endl;
        Agents.getElementByIndex(index)->Pop();
    }
    void popCustomerFinishitsProcess(int j)
    {
        Agents.getElementByIndex(j)->GetTop()->SetTotalTime(time-(Agents.getElementByIndex(j)->GetTop()->GetStartedAtTime()));
        cout<<"Mr "<<Agents.getElementByIndex(j)->GetTop()->GetName()<<" has left the Bank!"<<endl;
        cout<<"Total Wait of "<<Agents.getElementByIndex(j)->GetTop()->GetName()<<" duo to the interruption is "<<Agents.getElementByIndex(j)->GetTop()->GetWaitTime()<<endl;
        cout<<"End Time for Client "<<Agents.getElementByIndex(j)->GetTop()->GetName()<<" is "<<Agents.getElementByIndex(j)->GetTop()->GetEndTime()<<endl;
        cout<<"Total Time for Client "<<Agents.getElementByIndex(j)->GetTop()->GetName()<<" in The Bank is "<<
            Agents.getElementByIndex(j)->GetTop()->GetEndTime()-Agents.getElementByIndex(j)->GetTop()->GetArrivalTime()<<endl;
        TempQ.Enqueue(Agents.getElementByIndex(j)->GetTop());
        Agents.getElementByIndex(j)->Pop();
        cout<<"Finished"<<endl;
    }
    void Loop()
    {
        time++;

        for(int k=0; k<Agents.getListCounter(); k++)
        {
            if(! Agents.getElementByIndex(k)->isEmpty())
            {
                Agents.getElementByIndex(k)->GetTop()->SetProcessBurstTime(Agents.getElementByIndex(k)->GetTop()->GetProcessBurstTime()-1);
                Agents.getElementByIndex(k)->GetTop()->SetCounter(Agents.getElementByIndex(k)->GetTop()->GetCounter()+1);
            }
            else
            {
                if(Clients.getListCounter()==0&&WaitingQ.GetSize()==0)
                    Count++;
            }
        }

    }
    void roundRobin()
    {

        do
        {
            cout<<"At Time: "<< time<<endl ;
            cout<<"-------"<<endl;
            addCustToQueue();
            for(int j=0; j<Agents.getListCounter(); j++)
            {
                if(!Agents.getElementByIndex(j)->isEmpty())
                {
                    if(Agents.getElementByIndex(j)->GetTop()->GetEndTime()==time)
                    {
                        popCustomerFinishitsProcess(j);
                    }
                    else if(Agents.getElementByIndex(j)->GetTop()->GetInterruptTime()==Agents.getElementByIndex(j)->GetTop()->GetCounter())
                    {
                        popAndEnqueueIfInterrupt(j);
                    }
                }
                if(WaitingQ.isHasData())
                {
                    if(Agents.getElementByIndex(j)->isEmpty())
                    {
                        if(WaitingQ.isHasData()&& WaitingQ.GetDequeue()->GetArrivalTime()<=time)
                        {
                            pushCustForCashier(j);
                        }
                    }
                }
            }
            Loop();

            if(Count==Agents.getListCounter())
            {
                flag=1;
                time--;
            }
            else
            {
                Count=0;
            }
            cout<<endl;
            cout<<"--------------------------------------------------------"<<endl;

        }
        while(flag==0);
        cout<<endl<<endl;
        cout<<endl<<endl;
        cout<<endl<<endl;

    }
    void Report()
    {

        cout<<"Final Report!"<<endl;

        int temp = TempQ.GetSize();


        for(int i=0; i<temp; i++)
        {
            cout<<"Chient "<< TempQ.GetDequeue()->GetName()<<" Report"<<endl;
            cout<<"---------------------"<<endl;

            cout<< " Arrived At            waiting Time        Total Time After finishing proccess  "<<endl;
            cout<<"------------------------------------------------------------------------------"<<endl;

            cout<<"       "<<TempQ.GetDequeue()->GetArrivalTime()<<"                  "<< TempQ.GetDequeue()->GetWaitTime()<<"                                "<<TempQ.GetDequeue()->GetEndTime()-TempQ.GetDequeue()->GetArrivalTime()<<endl;
            cout<<endl<<endl;

            TempQ.Dequeue();
        }
        cout<<"------------------------------------------------------"<<endl;

        cout<<"Total time of all the Clients in the system is : "<<time<<endl;


    }
};

#endif // ClientsRoundRobin
