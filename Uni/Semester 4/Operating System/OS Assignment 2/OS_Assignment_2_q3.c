#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

int critical=0,serious=0,normal=0;

pthread_mutex_t m;
pthread_cond_t cv;

void* pt(void* x)
{
    int type=*(int*)x;

    pthread_mutex_lock(&m);

    if(type==1) critical++;
    else if(type==2) serious++;
    else normal++;

    pthread_cond_signal(&cv);
    pthread_mutex_unlock(&m);

    return NULL;
}

void* dr(void* x)
{
    int senior=*(int*)x;
    int normalCount=0;

    while(1)
    {
        pthread_mutex_lock(&m);

        while(critical==0 && serious==0 && normal==0)
            pthread_cond_wait(&cv,&m);

        if(critical>0)
        {
            critical--;
            printf("C\n");
        }
        else if(senior && serious>0)
        {
            serious--;
            printf("S\n");
        }
        else if(normal>0)
        {
            normal--;
            normalCount++;
            printf("N\n");
        }

        if(serious>=5)
        {
            serious--;
            critical++;
            printf("promote\n");
        }

        if(normalCount==3)
        {
            if(serious>0)
            {
                serious--;
                printf("force S\n");
            }
            normalCount=0;
        }

        pthread_mutex_unlock(&m);
        sleep(1);
    }
}

int main()
{
    pthread_t p[5],d1,d2;

    pthread_mutex_init(&m,NULL);
    pthread_cond_init(&cv,NULL);

    int t1=1,t2=2,t3=3,t4=2,t5=3;
    int s=1,j=0;

    pthread_create(&p[0],NULL,pt,&t1);
    pthread_create(&p[1],NULL,pt,&t2);
    pthread_create(&p[2],NULL,pt,&t3);
    pthread_create(&p[3],NULL,pt,&t4);
    pthread_create(&p[4],NULL,pt,&t5);

    pthread_create(&d1,NULL,dr,&s);
    pthread_create(&d2,NULL,dr,&j);

    for(int i=0;i<5;i++)
        pthread_join(p[i],NULL);

    sleep(6);

    return 0;
}