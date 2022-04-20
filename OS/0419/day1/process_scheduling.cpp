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
using namespace std;
typedef unsigned int Uint32;
/*常量和状态定义*/
#define        PRO_NUM        0x05
#define        MAX_TIME    0xFF
/*状态宏*/
#define        WAIT        0x01
#define        RUN            0x02
#define        FINISH        0x03

#define        ID_ERROR    0x10
#define        MIN_PRIOR    0xFF
#define        MAX_PRIOR    0x00
class PCB_Info{
    private:
        Uint32      s_id;
        Uint32      s_static_prior;
        Uint32      s_dynamic_prior;
        Uint32      s_start_time;
        Uint32      s_need_time;
        Uint32      s_used_time;
        Uint32      s_state;
    public:
        ~PCB_Info(){
            cout << "PCB destructor" << endl;
        }
        PCB_Info(){

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
// void Process::Init_Queue(){
//     for(int i = 0; i < 5; i++){
//         g_queue[i].s_id = i;
//         g_queue[i].s_static_prior = i;
//         g_queue[i].s_dynamic_prior = i;
//         g_queue[i].s_start_time = 0;
//         g_queue[i].s_need_time = 0;
//         g_queue[i].s_used_time = 0;
//         g_queue[i].s_state = WAIT;
//     }
// }