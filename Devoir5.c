#include<stdio.h>
#include<pthread.h>
#include<unistd.h>
#include<stdlib.h>
#include<semaphore.h>

sem_t sem;

int i=1; //numero du thread en cours

void* fonctionThread(void* args)
{
    int a =   *((int*)args );

    while(1)
    {
        sem_wait(&sem);
        if(a < i)
            i=1 ;

        printf(" Tread %d\n",i++);
        sem_post(&sem);
    }
     pthread_exit(NULL);
}

int main(int argc ,char* const argv[])
{
    if(argc <2)
    {
        perror("Nombre argument insuffissant");
        return 0;
    }
   int n= atoi(argv[1]);

    pthread_t p[n];
    int result;
    result = sem_init(&sem,0,1);

    if(result == -1)
     {
         perror("Erreur d'initialisation de la sempahore");
         return 0;
     }
    for(int j= 1;j<n ;j++)
    {
      int th = pthread_create(&p[j],NULL,fonctionThread,&n);

      if(th == -1)
      {
          perror("erreur de creation du thread secondaire");
          return 0;
      }
    }

    for(int i=0; i<n;i++)
        pthread_join(p[i] ,NULL);

    sem_destroy(&sem);

    return 0;
}
#include<stdio.h>
#include<pthread.h>
#include<unistd.h>
#include<stdlib.h>
#include<semaphore.h>

sem_t sem;

int i=1; //numero du thread en cours

void* fonctionThread(void* args)
{
    int a =   *((int*)args );

    while(1)
    {
        sem_wait(&sem);
        if(a < i)
            i=1 ;

        printf(" Tread %d\n",i++);
        sem_post(&sem);
    }
     pthread_exit(NULL);
}

int main(int argc ,char* const argv[])
{
    if(argc <2)
    {
        perror("Nombre argument insuffissant");
        return 0;
    }
   int n= atoi(argv[1]);

    pthread_t p[n];
    int result;
    result = sem_init(&sem,0,1);

    if(result == -1)
     {
         perror("Erreur d'initialisation de la sempahore");
         return 0;
     }
    for(int j= 1;j<n ;j++)
    {
      int th = pthread_create(&p[j],NULL,fonctionThread,&n);

      if(th == -1)
      {
          perror("erreur de creation du thread secondaire");
          return 0;
      }
    }

    for(int i=0; i<n;i++)
        pthread_join(p[i] ,NULL);

    sem_destroy(&sem);

    return 0;
}
