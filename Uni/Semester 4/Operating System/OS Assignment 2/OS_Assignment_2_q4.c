#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <time.h>

#define M 100

typedef struct {
    int id,priority;
    time_t time;
} F;

F q[M];
int size=0;

pthread_mutex_t m;
pthread_cond_t cv;

void add(F f)
{
    if(size<M)
        q[size++]=f;
}

F get()
{
    int index=0;

    for(int i=1;i<size;i++)
    {
        if(q[i].priority>q[index].priority)
            index=i;
    }

    F f=q[index];
    q[index]=q[--size];

    return f;
}

void* gen(void* x)
{
    int id=1;

    while(1)
    {
        F f;
        f.id=id++;
        f.priority=rand()%5;
        f.time=time(NULL);

        pthread_mutex_lock(&m);
        add(f);
        printf("add f%d p%d\n",f.id,f.priority);
        pthread_cond_signal(&cv);
        pthread_mutex_unlock(&m);

        sleep(1);
    }
}

void* rw(void* x)
{
    int id=*(int*)x;

    while(1)
    {
        pthread_mutex_lock(&m);

        while(size==0)
            pthread_cond_wait(&cv,&m);

        time_t now=time(NULL);

        for(int i=0;i<size;i++)
        {
            if(now - q[i].time > 5)
                q[i].priority++;
        }

        F f=get();

        printf("r%d f%d p%d\n",id,f.id,f.priority);

        pthread_mutex_unlock(&m);

        sleep(2);
    }
}

void* em(void* x)
{
    while(1)
    {
        pthread_mutex_lock(&m);

        for(int i=0;i<size;i++)
        {
            if(q[i].priority>=4)
                printf("em f%d\n",q[i].id);
        }

        pthread_mutex_unlock(&m);
        sleep(2);
    }
}

int main()
{
    pthread_t g,r1,r2,e;

    pthread_mutex_init(&m,NULL);
    pthread_cond_init(&cv,NULL);

    int id1=1,id2=2;

    pthread_create(&g,NULL,gen,NULL);
    pthread_create(&r1,NULL,rw,&id1);
    pthread_create(&r2,NULL,rw,&id2);
    pthread_create(&e,NULL,em,NULL);

    sleep(10);

    return 0;
}