#include "motion.hpp"
#include <iostream>
#include <thread>
// 前进的距离
#define Forward_Distance 0x04 // 1m
// 前进的距离   过柱子
#define Forward_Distance_pillor 0x01

// 前进的速度   正常
#define Forward_Speed_nomal 0x01
// 前进的速度   过草地
#define Forward_Speed_grass 0x01
// 前进的速度   过窄桥
#define Forward_Speed_Bridge 0x01
// 前进的速度
#define Forward_Speed_pillor 0x01

// 左转的角度
#define Left_Angle_nomal 0x5A // 90
// 右转的角度
#define Right_Angle_nomal 0x5A // 90
// 左转的角度   过柱子
#define Left_Angle_pillor 0x1E // 30
// 右转的角度   过柱子
#define Right_Angle_pillor 0x1E // 30

// 左转的速度   正常
#define Left_Speed 0x01
// 右转的速度   正常
#define Right_Speed 0x01

/* 基础运动 */
void turn_left(Move &move)
{
    std::cout << "turn_left" << std::endl;
    move.turnLeftByAngle(Left_Angle_nomal, Left_Speed);
}
void turn_right(Move &move)
{
    std::cout << "turn_right" << std::endl;
    move.turnRightByAngle(Right_Angle_nomal, Right_Speed);
}
void Forword(Move &move)
{
    std::cout << "Forword" << std::endl;
    move.moveForwardByDistance(Forward_Distance, (float)Forward_Speed_nomal / 0x05);
}
// 矫正
void Justify(Move &move)
{
    std::cout << "Justify" << std::endl;
}
/* 高级运动 */
// 草地
void grass(Move &move)
{
    std::cout << "grass" << std::endl;
    move.moveForwardByDistance(Forward_Distance, (float)Forward_Speed_grass);
}
// 柱子
void pillar(Move &move)
{
    std::cout << "pillar" << std::endl;
    // left
    move.turnLeftByAngle(Left_Angle_pillor, Left_Speed, true, true);
    // forword
    move.moveForwardByDistance(Forward_Distance_pillor, (float)Forward_Speed_pillor / 0x05, true, true);
    // right
    move.turnRightByAngle(Right_Angle_pillor * 2, Right_Speed, true, true);
    // forword
    move.moveForwardByDistance(Forward_Distance_pillor, (float)Forward_Speed_pillor / 0x05, true, true);
}
// 窄桥
void narrow_bridge(Move &move)
{
    std::cout << "narrow_bridge" << std::endl;
    // 抬头
    move.leanBackward(true);
    // 上楼梯
    move.climbStairs(true);
    // 平视
    move.recovery();
    // 过桥
    move.moveForwardByDistance(Forward_Distance, Forward_Speed_Bridge, true, true);
    // 前倾
    move.leanForward(true);
    // 下楼梯

    //平视
    move.recovery();
}
// 减速带
void speed_band(Move &move)
{
    std::cout << "speed_band" << std::endl;
    move.moveForward(true);
}

int main(int argc, char *argv[])
{

    Move move(true);
    unsigned int input = 0;
    std::cout << " 请输入操作 " << std::endl
              << "1. 过草地 " << std::endl
              << "2. 过柱子 " << std::endl
              << "3. 过窄桥 " << std::endl
              << "4. 过减速带 " << std::endl
              << "5. 左转 " << std::endl
              << "6. 右转 " << std::endl
              << "7. 前进 " << std::endl;
    std::cin >> input;
    switch (input)
    {
    case 1:
        grass(move);
        break;
    case 2:
        pillar(move);
        break;
    case 3:
        narrow_bridge(move);
        break;
    case 4:
        speed_band(move);
        break;
    case 5:
        turn_left(move);
        break;
    case 6:
        turn_right(move);
        break;
    case 7:
        Forword(move);
        break;
    default:
        std::cout << " 输入有误 " << std::endl;
    }

    cout << "\n结束按CTRL+C退出\n";
    while (true)
        ;
    return 0;
}
