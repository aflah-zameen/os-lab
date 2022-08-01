#include<stdio.h>
int p[30],bt[30],tat[30],wt[30],n,tot_wt=0,tot_tat=0,fcfs_wt=0,fcfs_tat=0;
void wt_tat(int *a,int *b){
tat[0]=bt[0];
for(int i=1;i<n;i++)
{
	tat[i]=tat[i-1]+bt[i];
	tot_tat=tot_tat+tat[i];
}
wt[0]=0;
*a=tot_tat;
for(int i=1;i<n;i++)
{
 wt[i]=wt[i-1]+bt[i-1];
 tot_wt=tot_wt+wt[i];
}
*b=tot_wt;

}

void main()
{
printf("Enter the number of processor");
scanf("%d",&n);
for(int i=0;i<n;i++)
{
	scanf("%d",&bt[i]);
}

printf("Processes  Burst   Waiting   Turn around \n");
wt_tat(&fcfs_tat,&fcfs_wt);
for(int i=0;i<n;i++)
{
	printf("%d\t   %d\t   %d\t\t%d\n", i+1, bt[i], wt[i], tat[i]);
}

printf("Average waiting time = %f\n", (float)fcfs_wt / (float)n);
   printf("Average turn around time = %f\n", (float)fcfs_tat / (float)n);

}
