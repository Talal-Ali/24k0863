#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <math.h>

#define N 1000
#define T 100

float a[N][N];

typedef struct {
    int r1,r2,c1,c2;
} B;

void* sat(void* x)
{
    for(int i=1;i<N-1;i++)
    {
        for(int j=1;j<N-1;j++)
        {
            if(a[i][j]==-999)
            {
                a[i][j]=(a[i-1][j]+a[i+1][j]+a[i][j-1]+a[i][j+1])/4;
            }
        }
    }
    return NULL;
}

void* blk(void* x)
{
    B* b=(B*)x;

    float sum=0,max=-9999,min=9999;
    int count=0;

    for(int i=b->r1;i<b->r2;i++)
    {
        for(int j=b->c1;j<b->c2;j++)
        {
            float v=a[i][j];
            sum+=v;

            if(v>max) max=v;
            if(v<min) min=v;

            count++;
        }
    }

    float mean=sum/count;
    float var=0;

    for(int i=b->r1;i<b->r2;i++)
    {
        for(int j=b->c1;j<b->c2;j++)
        {
            float d=a[i][j]-mean;
            var+=d*d;
        }
    }

    var/=count;

    printf("block mean=%.2f var=%.2f max=%.2f min=%.2f\n",mean,var,max,min);
    return NULL;
}

void* hot(void* x)
{
    int count=0;

    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
            if(a[i][j]>35) count++;

    printf("hotspots=%d\n",count);
    return NULL;
}

void* cold(void* x)
{
    int count=0;

    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
            if(a[i][j]<-10) count++;

    printf("coldspots=%d\n",count);
    return NULL;
}

void* norm(void* x)
{
    float min=-20,max=50;

    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
            a[i][j]=(a[i][j]-min)/(max-min);

    return NULL;
}

int main()
{
    pthread_t ts[4];
    pthread_t tb[10];
    B b[10];

    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
            a[i][j]=rand()%60-20;

    pthread_create(&ts[0],NULL,sat,NULL);
    pthread_join(ts[0],NULL);

    int k=0;
    for(int i=0;i<N;i+=T)
    {
        b[k].r1=i;
        b[k].r2=i+T;
        b[k].c1=0;
        b[k].c2=N;

        pthread_create(&tb[k],NULL,blk,&b[k]);
        k++;
        if(k==10) break;
    }

    for(int i=0;i<k;i++)
        pthread_join(tb[i],NULL);

    pthread_create(&ts[1],NULL,hot,NULL);
    pthread_create(&ts[2],NULL,cold,NULL);
    pthread_create(&ts[3],NULL,norm,NULL);

    for(int i=1;i<4;i++)
        pthread_join(ts[i],NULL);

    return 0;
}