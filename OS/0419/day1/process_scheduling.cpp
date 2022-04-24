/**
 * @file process_scheduling.cpp
 * @author Luke Tebo (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-04-19
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <iostream>
#include <vector>
#include <time.h>
// using namespace std;
typedef unsigned int Uint32;
/*常量和状态定义*/
#define        PRO_NUM        0x05
#define        MAX_TIME       0xFF
/*状态宏*/
#define        WAIT           0x01
#define        RUN            0x02
#define        FINISH         0x03

#define        ID_ERROR       0x10
#define        MIN_PRIOR      0xFF
#define        MAX_PRIOR      0x00
class PCB_Info{
    private:
        Uint32      s_id;              // 进程ID
        Uint32      s_static_prior;    // 静态优先级
        Uint32      s_dynamic_prior;   // 动态优先级
        Uint32      s_start_time;      // 开始时间
        Uint32      s_need_time;       // 需要时间
        Uint32      s_used_time;       // 已经使用时间
        Uint32      s_state;           // 进程状态
    public:
        ~PCB_Info(){
            std::cout << "PCB destructor" << std::endl;
        }
        PCB_Info(){

        }
        Uint32 get_id(){
            return s_id;
        }
        Uint32 get_static_prior(){
            return s_static_prior;
        }
        Uint32 get_dynamic_prior(){
            return s_dynamic_prior;
        }
        Uint32 get_start_time(){
            return s_start_time;
        }
        Uint32 get_need_time(){
            return s_need_time;
        }
        Uint32 get_used_time(){
            return s_used_time;
        }
        Uint32 get_state(){
            return s_state;
        }
        void set_id(Uint32 id){
            s_id = id;
        }
        void set_static_prior(Uint32 static_prior){
            s_static_prior = static_prior;
        }
        void set_dynamic_prior(Uint32 dynamic_prior){
            s_dynamic_prior = dynamic_prior;
        }
        void set_start_time(Uint32 start_time){
            s_start_time = start_time;
        }
        void set_need_time(Uint32 need_time){
            s_need_time = need_time;
        }
        void set_used_time(Uint32 used_time){
            s_used_time = used_time;
        }
        void set_state(Uint32 state){
            s_state = state;
        }

};
class Process{
    private:
        PCB_Info g_queue[5];
        Uint32   g_time;
    public:
        ~Process(){};
        Process(){};
        void Simulator(){};
        void Init_Process(){};
        void Init_Queue();
        Uint32 Create_Process();
        void Run_Process();
        Uint32 Get_PriProcess();
        void Work_Process();
        void Change_Process();
        void Print_State();
        void End_Process();
};
void Process::Init_Queue(){
    for(int i = 0; i < PRO_NUM; i++){
        g_queue[i].set_id(i);
        g_queue[i].set_static_prior(MIN_PRIOR);
        g_queue[i].set_dynamic_prior(MIN_PRIOR);
        g_queue[i].set_start_time(0);
        g_queue[i].set_need_time(0);
        g_queue[i].set_used_time(0);
        g_queue[i].set_state(FINISH);
    }
};
void Process::Init_Process(){

    for (int i = 0; i < PRO_NUM; i++) {
        std::cout << "*****************************" << std::endl;
        std::cout << "ProcessID: "    << g_queue[i].get_id() << std::endl;
        std::cout << "StaticPrior: "  << g_queue[i].get_static_prior() << std::endl;
        std::cout << "DynamicPrior: " << g_queue[i].get_dynamic_prior() << std::endl;
        std::cout << "FinishTime: "   << g_queue[i].get_start_time() << std::endl; 
        std::cout << "NeedTime: "     << g_queue[i].get_need_time() << std::endl;
        std::cout << "UsedCPUTime: "  << g_queue[i].get_used_time() << std::endl;
        std::cout << "State: "        << g_queue[i].get_state() << std::endl;

    }

}
Uint32 Process::Create_Process(){
    Uint32 id = 0;
    for (int i = 0; i < PRO_NUM; i++) {
        if(g_queue[i].get_state() == FINISH){
            id = i;
            break;
        }
    }
    if(id == ID_ERROR){
        std::cout << "Create Process Error" << std::endl;
        return ID_ERROR;
    }
    g_queue[id].set_state(WAIT);
    g_queue[id].set_static_prior(MIN_PRIOR);
    g_queue[id].set_dynamic_prior(MIN_PRIOR);
    g_queue[id].set_start_time(g_time);
    g_queue[id].set_need_time(rand() % MAX_TIME + 1);
    g_queue[id].set_used_time(0);
    return id;
};

void Process::Run_Process(){

};
Uint32 Process::Get_PriProcess(){
    Uint32 min_prior = MAX_PRIOR;
    Uint32 min_id = ID_ERROR;
    for(int i = 0; i < PRO_NUM; i++){
        if(g_queue[i].get_state() == WAIT){
            if(g_queue[i].get_dynamic_prior() < min_prior){
                min_prior = g_queue[i].get_dynamic_prior();
                min_id = i;
            }
        }
    }
    return min_id;
};
void Process::Print_State(){
    std::cout << "Time ProcessID status used_time need_time start time static_prior dynamic_prior" << std::endl;
    for (int i = 0; i < PRO_NUM; i++) {
        std::cout << g_time << " " << g_queue[i].get_id() << " " << g_queue[i].get_state() << " " << g_queue[i].get_used_time() << " " << g_queue[i].get_need_time() << " " << g_queue[i].get_start_time() << " " << g_queue[i].get_static_prior() << " " << g_queue[i].get_dynamic_prior() << std::endl;
    }
};
int main(int argc, char *argv[]){
    Process p;
    p.Init_Queue();
    p.Create_Process();
    p.Run_Process();
    p.End_Process();
    return 0;
}