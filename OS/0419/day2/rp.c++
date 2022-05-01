/**
 * @file rp.c++
 * @author Luke Tebo (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-05-01
 * 
 * @copyright Copyright (c) 2022
 * 
 * 算法选择：RP 时间片轮转算法
 */
#include <iostream>
#include <stdio.h>
#include <vector>
#include <windows.h>
typedef unsigned int uint32;
/*常量和状态定义*/


class PCB{
    private:
        uint32 pid;                    // 进程标识符
        uint32 arrive_time;            // 到达时间
        uint32 serve_time;             // 服务时间
        uint32 use_time;               // 已用时间
        uint32 finish_time;            // 完成时间
        uint32 turn_around_time;       // 周转时间
        uint32 status;                 // 进程状态
    public:
        PCB(){};
        ~PCB(){};
        void init(uint32 pid, uint32 arrive_time, uint32 serve_time){
            this->pid = pid;
            this->arrive_time = arrive_time;
            this->serve_time = serve_time;
            this->use_time = 0;
            this->finish_time = 0;
            this->turn_around_time = 0;
            this->status = 0;
        };
        uint32 get_pid(){
            return pid;
        };
        uint32 get_arrive_time(){
            return arrive_time;
        };
        uint32 get_finish_time(){
            return finish_time;
        };
        uint32 get_turn_around_time(){
            return turn_around_time;
        };
        uint32 get_serve_time(){
            return serve_time;
        };
        uint32 get_status(){
            return status;
        };
        uint32 get_use_time(){
            return use_time;
        };
        void set_status(uint32 status){
            this->status = status;
        };
        void set_finish_time(uint32 finish_time){
            this->finish_time = finish_time;
        }
        void set_turn_around_time(uint32 turn_around_time){
            this->turn_around_time = turn_around_time;
        }
        void set_use_time(uint32 use_time){
            this->use_time = use_time;
        }
};
// 初始化进程信息
void init_process(std::vector<PCB> &process_list, uint32 process_num){
    uint32 i = 0;
    uint32 pid = 0;
    uint32 arrive_time = 0;
    uint32 finish_time = 0;
    for(i = 0; i < process_num; i++){
        printf("请输入进程%d的到达时间和完成时间: ", i);
        scanf("%d %d %d", &pid, &arrive_time, &finish_time);
        process_list.push_back(PCB());
        process_list[i].init(pid, arrive_time, finish_time);
    }
}
// 打印进程信息
void print_process(std::vector<PCB> &process_list){
    int size = process_list.size();
    std::cout << "进程ID 到达时间 服务时间 完成时间 周转时间 已用时间" << std::endl;
    for (int i = 0; i < size; i++) {
        printf("  %d\t  %d\t  %d\t    %d\t    %d\t    %d\n", process_list[i].get_pid(), process_list[i].get_arrive_time(), process_list[i].get_serve_time(), process_list[i].get_finish_time(), process_list[i].get_turn_around_time(), process_list[i].get_use_time());
    }
}
// RP算法
void RP(std::vector<PCB> &process_list){
    uint32 q = 0;
    printf("输入时间片大小：");
    scanf("%d", &q);
    uint32 time = 0; // 初始化时间
    uint32 count = 0;
    // // std::vector<uint32> process_serve_time(process_list.size(), 0); // 进程服务时间
    // if(process_list[0].get_arrive_time() == 0){
    //     process_list[0].set_status(1);
    // }
    boolean flag = true;
    while(count < process_list.size()){
        uint32 i = 0;
     
        //  为每一次进程调度做准备 设置这个进程的状态，是否能够执行
        for(i = 0; i < process_list.size(); i++){
            if(time >= process_list[i].get_arrive_time() && process_list[i].get_status() == 0 && (i == time || i == time % process_list.size())){
                printf("%d\n", i);
                flag = false;
                process_list[i].set_status(1);  // 设置为就绪状态 可以运行
            }
        }
        
        time++;
        // 通过时间片 开始执行  时间 1 才开始
        for(i = 0; i < process_list.size(); i++){
            // 如果就绪状态就运行
            if(process_list[i].get_status() == 1 && process_list[i].get_status() != 2){
                process_list[i].set_use_time(process_list[i].get_use_time() + q);
                if(process_list[i].get_use_time()  == process_list[i].get_serve_time()){
                    process_list[i].set_status(2); // 设置为完成状态
                    process_list[i].set_finish_time(time);
                    count++;
                    process_list[i].set_turn_around_time(time - process_list[i].get_arrive_time());
                }else{
                    process_list[i].set_status(0); // 阻塞
                }
            }
        }
        printf("------%d------\n", time);
        print_process(process_list);
        
        // 判断是否所有进程都已经运行完成
        // for(i = 0; i < process_list.size(); i++){
        //     if(process_list[i].get_serve_time() == process_serve_time[i]){
        //         process_list[i].set_status(2); // 设置为完成状态
        //     }
        // }
        Sleep(10);
    }

}

int main(){

    std::vector<PCB> pcb_list;
    init_process(pcb_list, 5);
    RP(pcb_list);
    print_process(pcb_list);

    return 0;
}
