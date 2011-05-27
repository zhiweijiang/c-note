#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

struct msg
{
    int num;
    struct msg *next;
};

struct msg *head;
pthread_cond_t has_product = PTHREAD_COND_INITIALIZER;
pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;

void *consumer(void *p)
{
    struct msg *mp;

    for(;;)
    {
        pthread_mutex_lock(&lock);
        while(head == NULL)
            pthread_cond_wait(&has_product, &lock);
        mp = head;
        head = mp->next;
        pthread_mutex_unlock(&lock);
        printf("Consume %d \n", mp->num);
        free(mp);
        sleep(rand()%5);
    }
}

void *producer(void *p)
{
    struct msg *mp;
    struct msg *q;

    for(;;)
    {
        mp = malloc(sizeof(struct msg));
        mp->num = rand()%1000 + 1;
        printf("Producer %d\n", mp->num);
        pthread_mutex_lock(&lock);
        q = head;
        if(q == NULL)
        {
            head = mp;
            mp->next = NULL;
        }
        else
        {
            while(q->next != NULL)
                q = q->next; mp->next = NULL; q->next = mp;
        }
     // head = mp;
        pthread_mutex_unlock(&lock);
        pthread_cond_signal(&has_product);
        sleep(rand()%5);
    }
}


int main(int argc, const char *argv[])
{
    pthread_t pid, cid;

    srand(time(NULL));
    pthread_create(&pid, NULL, producer, NULL);
    pthread_create(&cid, NULL, consumer, NULL);
    pthread_join(pid, NULL);
    pthread_join(cid, NULL);

    return 0;
}
