/*Design a scheduling program to implements a Queue with two levels:
Level 1 : Fixed priority preemptive Scheduling
Level 2 : Round Robin Scheduling
For a Fixed priority preemptive Scheduling (Queue 1), the Priority 0 is highest priority. If one
process P1 is scheduled and running , another process P2 with higher priority comes. The New
process (high priority) process P2 preempts currently running process P1 and process P1 will go
to second level queue. Time for which process will strictly execute must be considered in the
multiples of 2..
All the processes in second level queue will complete their execution according to round robin
scheduling.
Consider: 1. Queue 2 will be processed after Queue 1 becomes empty.
2. Priority of Queue 2 has lower priority than in Queue 1*/
#include<stdio.h>
#include<conio.h>
#include<string.h>
int main()
{
	char t[10][5],temp[5];
	int a,b,pt[10],wt[10],totwt=0,pr[10],temp1,n;
	float avgwt;
	printf("enter the number of processes:");
	scanf("%d",&n);
	for(a=0;a<n;a++)
	{
		printf("enter the process %d name:",a+1);
  		scanf("%s",&t[a]);
		printf("enter the process time:");
		scanf("%d",&pt[a]);
		printf("enter the priority:");
		scanf("%d",&pr[a]);
	}
  	for(a=0;a<n-1;a++)
	{
		for(b=a+1;b<n;b++)
		{
			if(pr[a]>pr[b])
			{
				temp1=pr[a];
				pr[a]=pr[b];
				pr[b]=temp1;
				temp1=pt[a];
				pt[a]=pt[b];
				pt[b]=temp1;
				strcpy(temp,t[a]);
				strcpy(t[a],t[b]);
				strcpy(t[b],temp);
			}
		}
	}
	wt[0]=0;
	for(a=1;a<n;a++)
	{
		wt[a]=wt[a-1]+wt[a-1];
		totwt=totwt+wt[a];
	}
	avgwt=(float)totwt/n;
	printf("p_name\t p_time\t priority\t w_time\n");
	for(a=0;a<n;a++)
	{
	   printf(" %s\t %d\t %d\t %d\n" ,t[a],pt[a],pr[a],wt[a]);
	}
	printf("total waiting time=%d\n avg waiting time=%f",totwt,avgwt);
	
	int ts,pid[10],need[10],wt1[10],tat[10],a1,b1,n2,n1;
	int bt[10],flag[10],ttat=0,twt=0;
	float awt,atat;
	printf("\nEnter the number of Processors \n");
	scanf("%d",&n);
	n1=n;
	printf("\n Enter the Timeslice \n");
 	scanf("%d",&ts);
 	for(a=1;a<=n;a++)
	{
   		printf("\n Enter the process ID %d",a);
		scanf("%d",&pid[a]);
   		printf("\n Enter the Burst Time for the process");
   		scanf("%d",&bt[a]);
   		need[a]=bt[a];
 	}
 	for(a=1;a<=n;a++)
	{
		flag[a]=1;
  		wt[a]=0;
 	}
 	while(n!=0)
	{
   		for(a=1;a<=n;a++)
   		{
     		if(need[a]>=ts)
     		{
       			for(b=1;b<=n;b++)
				{
	  				if((a!=b)&&(flag[a]==1)&&(need[b]!=0))
	  				wt[b]+=ts;
       			}
      			need[a]-=ts;
      			if(need[a]==0)
      			{
	 				flag[a]=0;
	 				n--;
       			}
     		}
     		else
    		{
       			for(b=1;b<=n;b++)
       			{
	  				if((a!=b)&&(flag[a]==1)&&(need[b]!=0))
	  				wt[b]+=need[a];
       			}
       			need[a]=0;
       			n--;
       			flag[a]=0;
  			}
 		}
	}
	for(a=1;a<=n1;a++)
	{
  		tat[a]=wt[a]+bt[a];
  		twt=twt+wt[a];
  		ttat=ttat+tat[a];
	}
	awt=(float)twt/n1;
	atat=(float)ttat/n1;
	printf("\n\n Process \t Process ID  \t BurstTime \t Waiting Time \t TurnaroundTime \n ");
	for(a=1;a<=n1;a++)
	{ 
 		printf("\n %5d \t %5d \t\t %5d \t\t %5d \t\t %5d \n", ts,pid[a],bt[a],wt[a],tat[a]);
	}
	printf("\n The average Waiting Time=4.2f",awt);
	printf("\n The average Turn around Time=4.2f",atat);
}

