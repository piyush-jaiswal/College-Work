#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    int n, k, s, i, mindays=100000, k_pos=0, event_pos=-1, no_of_event=0, no_of_days=0;
    int start_day[100000], end_day[100000];
    scanf("%d %d %d",&n,&k,&s);
    for(i=0;i<n;i++)
        scanf("%d %d",&start_day[i],&end_day[i]);
    for(i=0;i<n;i++)
        {
        if(start_day[i]-k_pos<=k)
            {
            if((end_day[i]-start_day[i]+1)<mindays)
            {
            mindays = end_day[i]-start_day[i]+1;
            event_pos=i;
            }
        }
        else if(start_day[i]-k_pos>k)
            {
            no_of_event++;
            if(no_of_days<s)
            no_of_days+= mindays;
            else
                break;
            k_pos=end_day[event_pos];
            i = end_day[event_pos];
            event_pos=-1;
            mindays=100000;
        }
        }
        if(no_of_event==0 && no_of_days==0)
            printf("%d", -1);
        else
    printf("%d %d",no_of_event, no_of_days);
    getch();
    return 0;
    }
