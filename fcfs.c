 #include<stdio.h>
 typedef struct process
 {
     int process ;
     int at ;
     int bt ;
     int ct ;
     int wt ;
     int st ;
     int tat ;
     int tct ;
     int rt ;
     
 } fcfs ;
 
 void sort ( fcfs arr[] , int n )
 {
    for( int i = 0 ; i < n-1 ; i++)
    {
        for( int j = i+1 ; j < n ; j++)
        {
            if( arr[i].at > arr[j].at )
            {
                fcfs temp = arr[i] ;
                arr[i] = arr[j] ;
                arr[j] = temp ;
            }
        }
    }
 }
 int main()
 {
     int n , temp = 0 ;
     printf("Enter the number of process :\n");
     scanf("%d",&n);
     fcfs arr[n] ;
     printf("Enter the process details :\n");
     for( int i = 0 ; i < n ; i++)
     {
         arr[i].process = i +1 ;
         printf("\nEnter %d process arrival time :",i+1);
         scanf("%d",&arr[i].at);
         printf("\nEnter %d process burst time :",i+1);
         scanf("%d",&arr[i].bt);
     }
     sort ( arr , n);
     printf ("Process\t\tArrival Time\tBurst Time\tstart time\tCompletion time\t\tTurn Around Time\tWaiting Time\tResponse Time\n");
     for( int i = 0 ; i < n ; i++)
     {
        if( i == 0)
            arr[i].st = 0 ;
        else  if( arr[i].at > arr[i-1].tct)
            arr[i].st = arr[i-1].tct +  arr[i].at - arr[i-1].tct ;
           
        else  
            arr[i].st = arr[i-1].tct ;
           
         arr[i].tct = temp + arr[i].bt ;
         if( arr[i].at > arr[i-1].tct && i != 0)
             arr[i].tct +=  (arr[i].at - arr[i-1].tct ) ;
         temp = arr[i].tct ;
         arr[i].rt = arr[i].st - arr[i].at ;
         arr[i].tat = arr[i].tct - arr[i].at ;
         arr[i].wt = arr[i].tat - arr[i].bt ;
         printf ("%5d\t%15d\t\t%9d\t\t%3d\t%10d\t%15d\t%12d\t%d\n", arr[i].process, arr[i].at , arr[i].bt  , arr[i].st , arr[i].tct, arr[i].tat, arr[i].wt , arr[i].rt);
     }
 }
