#include <stdio.h>
#include <stdlib.h>
int comp(const void *a,const void *b){
    return (*(int *)a - *(int *)b);
}
int main(){

    int n=5;

    int br[n],c[n];
    int pr[n],d[n];
    int sig=0;
    printf("enter brust times of process\n");
    for(int i=0;i<n;i++){
        scanf("%d",&br[i]);
        c[i]=br[i];
        sig=sig+br[i];
    }
    printf("enter proiorites of process\n");
    for(int i=0;i<n;i++){
        scanf("%d",&pr[n]);
        d[i]=pr[i];
    }
    qsort(c,n,sizeof(c[0]),comp);
    qsort(d,n,sizeof(d[0]),comp);

//FIFO  FIFFO  FIFFO
    printf("\n");
    printf("in FIFO avg waiting time \t\t  turn around time\n");
    int sum=0;
    int t=0;
    for(int i=0;i<n;i++){
        t=t+br[i];
        printf("for process p%d   %d \t\t  %d\n",i+1,sum,t);
        sum=sum+br[i];
    }
//STF STF STF
    printf("\n");
    printf("in STF avg waiting time \t\t  turn around time\n");
    sum=0;
    t=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(c[i]==br[j]){
                t=t+br[j];
                printf("for process p%d   %d \t\t  %d\n",j+1,sum,t);
                sum=sum+br[j];
            }
        }
    }
//SCF SCF SCF
    printf("\n");
    printf("prioirity is considered with more to zero\n");
    printf("in SCF avg waiting time \t\t  turn around time\n");
    sum=0;
    t=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(d[i]==pr[j]){
                t=t+br[j];
                printf("for process p%d   %d \t\t  %d\n",j+1,sum,t);
                sum=sum+br[j];
            }
        }

    }
//Round robin Round robin Round robin
    printf("\n");
    printf("enter the quantam \n");
    int q;
    scanf("%d",&q);
    int tt[5]={0};
    int re[5]={0};
    int av[5]={0};
    int w[5]={0};
    for(int i=0;i<n;i++){
        re[i]=br[i];
    }
    int si=0;
    int x=0;
    while(si!=sig){
        for(int i=0;i<n;i++){
            if(re[i]>0 && re[i]-q>=0){
                x=si;
                si=si+q;
                re[i]=re[i]-q;
                av[i]=av[i]+(x-w[i]);
                w[i]=si;
                tt[i]=si;
            }
            else if(re[i]>0){
                x=si;
                si=si+(re[i]);
                tt[i]=si;
                re[i]=0;
                av[i]=av[i]+(x-w[i]);
                w[i]=si;
                
            }

        }
        
    }
    printf("in Round robin avg waiting time \\t  turn around time\n");
    for(int i=0;i<n;i++){
        printf("for process p%d   %d \t\t  %d\n",i+1,av[i],tt[i]);
    }
    return 0;
}