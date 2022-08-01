#include<stdio.h>
struct process{
 int id,wt,tat,at,bt,cmp;
} ;
struct process a[10];
void main()
{
int n;
float tot_wt=0,tot_tat=0;
printf("Enter the number of processors :");
scanf("%d",&n);
for(int i=0;i<n;i++){
printf("Enter the processor[%d] BT and AT :",i+1);
scanf("%d%d",&a[i].bt,&a[i].at);
a[i].id=i+1;
}

for(int i=0;i<n;i++)
{
 for(int  j=0;j<n-i-1;j++)
 {
 if(a[j].at>a[j+1].at)
 {
 int temp=a[j+1].bt;
			a[j+1].bt=a[j].bt;
			a[j].bt=temp;
			temp=a[j+1].at;
			a[j+1].at=a[j].at;
			a[j].at=temp;
			temp=a[j+1].id;
			a[j+1].id=a[j].id;
			a[j].id=temp;
 }
 }
}
printf("%d\n",a[0].id);
a[0].cmp=a[0].at+a[0].bt;
a[0].tat=a[0].cmp-a[0].at;
printf("*******%d--%d****\n",a[0].tat,a[0].bt);
a[0].wt=a[0].tat-a[0].bt;
tot_wt=a[0].wt;
tot_tat=a[0].tat;
int tot_cmp=a[0].cmp;

for(int i=1;i<n;i++)
{	
	int min=a[i].bt;
	for(int j=i+1;j<n;j++)
	{
		if(min>a[j].bt && a[j].at<=tot_cmp)
		{
			min=a[j].bt;
			int temp=a[j].bt;
			a[j].bt=a[i].bt;
			a[i].bt=temp;
			temp=a[j].at;
			a[j].at=a[i].at;
			a[i].at=temp;
			temp=a[j].id;
			a[j].id=a[i].id;
			a[i].id=temp;
			
		}
	}
		printf("*******%d****\n",a[i].bt);
	a[i].cmp=tot_cmp+a[i].bt;

	a[i].tat=a[i].cmp-a[i].at;
	a[i].wt=a[i].tat-a[i].bt;
	tot_cmp=a[i].cmp;
	tot_wt=tot_wt+a[i].wt;
	tot_tat=tot_tat+a[i].tat;
}
printf("\n************************************************");
    printf("\n RESULT:-");
    printf("\nProcess\t Burst\t Arrival\t Waiting\t Turn-around" );
    for(int i=0;i<n;i++)
    {
        printf("\n p%d\t %d\t %d\t\t %d\t\t\t%d", a[i].id, a[i].bt, a[i].at, a[i].wt, a[i].tat);
    }
    
    printf("\n\nAvg waiting time is:- %f\n",tot_wt/(float)n);
    printf("Avg turn around time is:- %f",tot_tat/(float)n);

}
