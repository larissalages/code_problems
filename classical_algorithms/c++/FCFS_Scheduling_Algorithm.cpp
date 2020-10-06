#include<iostream>
using namespace std;

int processes[20], at[20], bt[20], ct[20],wt[20], tat[20],rt[20];

void completionTime( int n)
{
	ct[0] = bt[0];
	cout<< "\nCompletion Time: "<< ct[0] << "\t";
	for(int i = 1; i<n; i++)
	{
	   ct[i] = ct[i-1] + bt[i];
	   cout<< ct[i] << "\t";
	}

}

void turnAroundTime(int n)
{
    tat[n] = {0};
    cout<< "\nTurn Around Time:";
    for (int  i = 0; i < n ; i++)
    {
        tat[i] = ct[i] - at[i];
        cout<< tat[i] << "\t" ;
    }
}

void waitingTime(int n)
{
    wt[n] = {0};
    wt[0] = 0;
    cout<< "\nWaiting Time:    "<< wt[0] << "\t";
    for (int  i = 1; i < n ; i++ )
    {
        wt[i] =  tat[i] - bt[i];
        cout<< wt[i] << "\t";
    }
}
void responseTime(int n)
{
    rt[0]=at[0];
    cout<< "\nResponse Time:   "<< wt[0] << "\t";
    for (int  i = 1; i < n ; i++ )
    {
        rt[i] = ct[i-1];
        cout<< rt[i] << "\t";
    }
}
void findAvgTime( int n)
{
    int  total_wt = 0, total_tat = 0,total_rt = 0;
    completionTime(n);
    turnAroundTime(n);
    waitingTime(n);
    responseTime(n);

    for (int  i=0; i<n; i++)
    {
        total_wt = total_wt + wt[i];
        total_tat = total_tat + tat[i];
        total_rt += rt[i];
    }

    cout << "\n";
    cout << "\nAverage Turn Around Time = " << (float)total_tat / (float)n;
    cout << "\nAverage Waiting Time = " << (float)total_wt / (float)n;
    cout << "\nAverage Response time = " << (float)total_rt / (float)n;
    cout << "\n";
}

int main()
{ 
    int pro, i;
    cout << "Enter the number of processes: ";
    cin >> pro;
    cout << "Enter the process number, arrival time and burst time for the above processes:\n";
    for(i=0; i<pro; i++)
    {
    	cin >> processes[i] >> at[i] >> bt[i];
    }
    cout << "Process ID:      ";
    for(i=0; i<pro; i++)
    {
    	cout << processes[i] << "\t";
    }
    cout << "\nArrival time:    ";
    for(i=0; i<pro; i++)
    {
    	cout << at[i] << "\t";
    }
    cout << "\nBurst time:      ";
    for(i=0; i<pro; i++)
    {
    	cout << bt[i] << "\t";
    }
    
    findAvgTime(pro); 
    return 0; 
} 

