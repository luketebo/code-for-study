#include "pthread.h"
#include "iostream"
using namspace std;
#define MAX 5
void* say(void* args){
    cout<<"Hello thread"<<end;
    return 0;
}
int main(){
    pthread_t tid[MAX];
    for(int i = 0;i< MAX;i++){
        int ret = pthread_create(&tids[i],NULL,say,NULL);
        if(ret != 0){
            cout<<"pthread :"<<ret<<endl;
        }
    }
    pthread_exit(NULL);

}