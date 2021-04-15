#include <iostream>
#include "ClientsRoundRobin.h"
using namespace std;

int main()
{
    ClientsRoundRobin BankSys;
    int int1 = 1,int3 = 3,int5 = 5,int4 =4, int2=2,int6=6;
    LinkedList<int> Client1Interruption;
    LinkedList<int> Client2Interruption;
    LinkedList<int> Client3Interruption;
    LinkedList<int> Client4Interruption;
    LinkedList<int> Client5Interruption;
    LinkedList<int> Client6Interruption;
    LinkedList<int> Client7Interruption;
    LinkedList<int> Client8Interruption;

    Client1Interruption.Add(&int1);

    Client2Interruption.Add(&int2);

    Client3Interruption.Add(&int1);
    Client3Interruption.Add(&int3);

    Client4Interruption.Add(&int1);
    Client4Interruption.Add(&int2);

    Client5Interruption.Add(&int1);
    Client5Interruption.Add(&int2);

    Client6Interruption.Add(&int1);
    Client6Interruption.Add(&int2);
    Client6Interruption.Add(&int3);

    Client7Interruption.Add(&int1);
    Client7Interruption.Add(&int4);
    Client7Interruption.Add(&int6);

    ClientsProcesses Client1("Ahmed",0,5,Client1Interruption),
                     Client2("Mohamed",0,3,Client2Interruption),
                     Client3("Ali",6,6,Client3Interruption),
                     Client4("Zeyad",3,11,Client4Interruption),
                     Client5("Shaker",2,8,Client5Interruption),
                     Client6("Alaa",0,11,Client6Interruption),
                     Client7("Sherif",7,9,Client7Interruption),
                     Client8("Shehab",10,7,Client8Interruption);

    BankSys.Clients.Add(&Client1);
    BankSys.Clients.Add(&Client2);
    BankSys.Clients.Add(&Client3);
    BankSys.Clients.Add(&Client4);
    BankSys.Clients.Add(&Client5);
    BankSys.Clients.Add(&Client6);
    BankSys.Clients.Add(&Client7);
    BankSys.Clients.Add(&Client8);
    BankSys.Clients.BubbleSort();
    Stack<ClientsProcesses> Agent1,Agent2;
    BankSys.Agents.Add(&Agent1);
    BankSys.Agents.Add(&Agent2);


    BankSys.roundRobin();
    BankSys.Report();

    return 0;
}
