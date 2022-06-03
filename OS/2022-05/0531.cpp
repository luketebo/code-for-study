#define MaxNumber 100
#include <iostream>
#include <iomanip>
using namespace std;
int TrackNum;//磁道数
int StartTrack;//开始磁道
int TrackOrder[MaxNumber];//初始磁道序列
int VisitOrder[MaxNumber];//访问磁道序列
bool Visited[MaxNumber];//标记是否被访问过
int MoveDistance[MaxNumber];//磁头移动距离（磁道数）
int Sum_Distance;//磁头移动的总距离
double AverageDistance;//磁头平均移动距离
bool direction;//选择磁头向内或向外方向
void Enter(); //输入起始磁道号、磁道顺序
void initial();
void display();
int Absolute(int a,int b);//计算与当前所在磁道距离的绝对值
void FCFS();//先来先服务，先进先出
void SSTF();//最短寻道时间优先
void SCAN();//扫描，从开始磁道沿选择方向扫描，直到没有要访问的磁道在沿反方向扫描
void CSCAN();//循环扫描，自开始磁道始终沿一个方向扫描，直到没有要访问的磁道再从最里圈或最外圈扫描
void Enter(){
    int i;
    cout<<"Enter TrackNum: ";
    cin>>TrackNum;  //磁道个数
    cout<<"Enter TrackOrder: ";
    for (i=0;i<TrackNum;i++){
        cin>>TrackOrder[i];   //磁道访问序列
    }
    cout<<"Enter StartTrack: ";
    cin>>StartTrack;  //开始磁道号
    cout<<endl;
}

//计算与当前所在磁道距离的绝对值
int Absolute(int a,int b){
    if (a - b > 0)
        return (a - b);
    else
        return (b - a);
}

void initial(){
    for (int i=0;i<TrackNum;i++){
        MoveDistance[i] = 0;
        VisitOrder[i] = TrackOrder[i];
        Visited[i] = false;
    }
    Sum_Distance = 0;
    AverageDistance = 0;
}

void display(){
    int i;
    cout<<"Start: "<<StartTrack<<endl;
    cout<<"Next"<<"\t"<<"Distance"<<"\t"<<endl;
    for (i=0;i<TrackNum;i++){
        cout<<VisitOrder[i]<<"\t"<<MoveDistance[i]<<"\t"<<endl;
    }
    cout<<"AverageDistance: "<<setprecision(4)<<AverageDistance<<endl;
}

//先来先服务，先进先出
void FCFS(){
    cout<<endl;
    cout<<"FCFS"<<endl;
    initial();

    //按照输入顺序依次访问磁道
    MoveDistance[0] = Absolute(TrackOrder[0],StartTrack);
    Sum_Distance = MoveDistance[0];
    VisitOrder[0] = TrackOrder[0];

    for (int i=1;i<TrackNum;i++){
        MoveDistance[i] = Absolute(TrackOrder[i],TrackOrder[i-1]);
        Sum_Distance += MoveDistance[i];
        VisitOrder[i] = TrackOrder[i];
    }

    AverageDistance = Sum_Distance*1.0/TrackNum;
    display();
}

//最短寻道时间优先
void SSTF(){
    cout<<endl;
    cout<<"SSTF"<<endl;
    initial();
    int CurrentTrack = StartTrack;
    int i,j,pointMin;
    int disTemp[MaxNumber];


    for (i = 0;i<TrackNum;i++){
        for (j = 0;j<TrackNum;j++){
            if (!Visited[j])
                disTemp[j] = Absolute(TrackOrder[j],CurrentTrack);
            else
                disTemp[j] = 10000;  //表示无穷远，即访问过的磁道就不再访问
        }

        pointMin = 0;
        for (j = 0;j<TrackNum;j++){
            if (disTemp[pointMin] > disTemp[j])
                pointMin = j;   //指向最小的位置
        }
        VisitOrder[i] = TrackOrder[pointMin];  //给访问序列赋值
        MoveDistance[i] = Absolute(TrackOrder[pointMin],CurrentTrack);  //计算每次的移动距离
        Sum_Distance += MoveDistance[i];   //累计移动距离
        CurrentTrack = TrackOrder[pointMin];   //改变当前的磁道号
        Visited[pointMin] = true;  //将当前的磁道号设置为已访问
    }

    AverageDistance = Sum_Distance*1.0/(TrackNum);
    display();
}

//扫描，从开始磁道沿选择方向扫描，直到没有要访问的磁道在沿反方向扫描
void SCAN(){
    cout<<endl;
    cout<<"SCAN"<<endl;
    cout<<"Choose direction,0-add,1-reduce: "<<endl;
    cin>>direction;
    initial();

    int i,j,temp,tempIndex;
    int SortTrackOrder[MaxNumber];
    for (i = 0;i<TrackNum;i++){
        SortTrackOrder[i] = TrackOrder[i];
    }

    //冒泡排序
    for (i = 0;i<TrackNum;i++){
        for (j = i;j<TrackNum;j++){
            if (SortTrackOrder[i]>=SortTrackOrder[j]){
                temp = SortTrackOrder[i];
                SortTrackOrder[i] = SortTrackOrder[j];
                SortTrackOrder[j] = temp;
            }
        }
    }

    //找到既在当前磁道之外，又是距离最近的磁道号
    int point = 0;
    while(StartTrack>=SortTrackOrder[point]){
        point++;
    }

    int count = 0;
    int currentTrack = StartTrack;

    if (direction == 0){  //向磁道增加的方向访问
        cout<<"Add"<<endl;
        for (i = point;i<TrackNum;i++){
            VisitOrder[count] = SortTrackOrder[i];
            MoveDistance[count] = Absolute(VisitOrder[count],currentTrack);
            currentTrack = VisitOrder[count];
            count++;
        }

        for (i = point - 1;i>=0;i--){
            VisitOrder[count] = SortTrackOrder[i];
            MoveDistance[count] = Absolute(VisitOrder[count],currentTrack);
            currentTrack = VisitOrder[count];
            count++;
        }
    }
    else if (direction == 1){  //向磁道减少的方向访问
        cout<<"Reduce"<<endl;
        for (i = point - 1;i>=0;i--){
            VisitOrder[count] = SortTrackOrder[i];
            MoveDistance[count] = Absolute(VisitOrder[count],currentTrack);
            currentTrack = VisitOrder[count];
            count++;
        }

        for (i = point;i<TrackNum;i++){
            VisitOrder[count] = SortTrackOrder[i];
            MoveDistance[count] = Absolute(VisitOrder[count],currentTrack);
            currentTrack = VisitOrder[count];
            count++;
        }
    }

    for (i = 0;i<TrackNum;i++){
        Sum_Distance += MoveDistance[i];
    }

    AverageDistance = (Sum_Distance*1.0)/TrackNum;
    display();
}

//循环扫描，自开始磁道始终沿一个方向扫描，直到没有要访问的磁道再从最里圈或最外圈扫描
void CSCAN(){
    cout<<endl;
    cout<<"CSCAN"<<endl;
    cout<<"Choose direction,0-add,1-reduce: "<<endl;
    cin>>direction;

    initial();
    int SortTrackOrder[MaxNumber];
    int i,j,temp,tempIndex;
    for (i = 0;i<TrackNum;i++){
        SortTrackOrder[i] = TrackOrder[i];
    }

    //冒泡排序
    for (i = TrackNum - 1;i>0;i--){
        for (j = 0;j<i;j++){
            if (SortTrackOrder[j]>=SortTrackOrder[j+1]){
                temp = SortTrackOrder[j];
                SortTrackOrder[j] = SortTrackOrder[j+1];
                SortTrackOrder[j+1] = temp;
            }
        }
    }

    //找到既在当前磁道之外，又是距离最近的磁道号
    int point = 0;
    while(StartTrack>=SortTrackOrder[point]){
        point++;
    }

    int count = 0;
    int currentTrack = StartTrack;
    if (direction == 0){  //向磁道增加的方向访问
        cout<<"Add"<<endl;
        for (i = point;i<TrackNum;i++){
            VisitOrder[count] = SortTrackOrder[i];
            MoveDistance[count] = Absolute(VisitOrder[count],currentTrack);
            currentTrack = VisitOrder[count];
            count++;
        }

        for (i =0;i<point;i++){
            VisitOrder[count] = SortTrackOrder[i];
            MoveDistance[count] = Absolute(VisitOrder[count],currentTrack);
            currentTrack = VisitOrder[count];
            count++;
        }
    }
    else if (direction == 1){//向磁道减少的方向访问
        cout<<"Reduce"<<endl;
        for (i = 0;i<point;i++){
            VisitOrder[count] = SortTrackOrder[i];
            MoveDistance[count] = Absolute(VisitOrder[count],currentTrack);
            currentTrack = VisitOrder[count];
            count++;
        }

        for (i = point;i<TrackNum;i++){
            VisitOrder[count] = SortTrackOrder[i];
            MoveDistance[count] = Absolute(VisitOrder[count],currentTrack);
            currentTrack = VisitOrder[count];
            count++;
        }
    }

    for (i = 0;i<TrackNum;i++){
        Sum_Distance += MoveDistance[i];
    }
    AverageDistance = (Sum_Distance*1.0)/TrackNum;

    display();
}
