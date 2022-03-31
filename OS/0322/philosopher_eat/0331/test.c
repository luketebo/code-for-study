#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <stdio.h>
pthread_mutex_t chopstick[5];
// pthread_mutex chopstick[5];

void *tfn(void *arg){
    int i = (int)arg;
    int left, right;

    if( i = 4) {
        left = i;
        right = 0;
    }else {
        left = i;
        right = i + 1;
    }
    while(1){
        sleep(1);

        pthread_mutex_lock(&chopstick[left]);
        printf("philosopher %d fetches chopstick %d\n",i, left);
        if( pthread_mutex_trylock(&chopstick[right]) != 0){
            pthread_mutex_unlock(&chopstick[left]);
            continue;
        }

        printf("philosopher %d fetches chopstick %d\n",i, right);
        printf("philosopher %d is eating.\n",i);

        sleep(2);

        pthread_mutex_unlock(&chopstick[right]);
        printf("philosopher %d release chopstick %d\n",i, right);

        pthread_mutex_unlock(&chopstick[left]);
        printf("philosopher %d release chopstick %d\n",i, left);
    }
}
int main(){
    pthread_t tid[5];
    int i;
    for( i = 0; i < 5; i++){
        pthread_mutex_init(&chopstick[i],NULL);
        pthread_create(&tid[i],NULL,tfn,(void*)i);

    }
    for(i = 0; i < 5; i++){
        pthread_join(tid[i], NULL);
    }
    return 0;
}