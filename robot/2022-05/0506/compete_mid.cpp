#include "motion.hpp"
#include <iostream>
// 前进的距离  正常
#define Forward_Distance 0x04 // 1m
// 前进的距离   过柱子
#define Forward_Distance_pillor 0x01
// 前进的距离  过限高杆
#define Forward_Distance_limit 0x01
// 前进的距离  上斜坡
#define Forward_Distance_slope 0x01
// 前进的距离  下斜坡
#define Forward_Distance_slope_down 0x01
// 前进的距离  上台阶
#define Forward_Distance_stairs 0x01
// 前进的距离  下台阶
#define Forward_Distance_stairs_down 0x01

// 前进的速度   正常
#define Forward_Speed_nomal 0x01
// 前进的速度   过草地
#define Forward_Speed_grass 0x01
// 前进的速度   过窄桥
#define Forward_Speed_Bridge 0x01
// 前进的速度  过障碍
#define Forward_Speed_pillor 0x01
// 前进的速度  过限高杆
#define Forward_Speed_limit 0x01
// 前进的速度  上斜坡
#define Forward_Speed_slope 0x01
// 前进的速度  下斜坡
#define Forward_Speed_slope_down 0x01
// 前进的速度  上台阶
#define Forward_Speed_stairs 0x01
// 前进的速度  下台阶
#define Forward_Speed_stairs_down 0x01

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

// 限高
#define Limit_Height 0x01
/* 基础运动 */
void turn_left(Move &move)
{
    std::cout << "turn_left" << std::endl;
    move.turnLeftByAngle(Left_Angle_nomal, Left_Speed);
};
void turn_right(Move &move)
{
    std::cout << "turn_right" << std::endl;
    move.turnRightByAngle(Right_Angle_nomal, Right_Speed);
};
void Forword(Move &move)
{
    std::cout << "Forword" << std::endl;
    move.moveForwardByDistance(Forward_Distance, (float)Forward_Speed_nomal / 0x05);
};
// 矫正
void Justify(Move &move)
{
    std::cout << "Justify" << std::endl;
};
/* 高级运动 */
// 上斜坡
void Forword_Slope(Move &move)
{
    move.moveForwardByDistance(Forward_Distance, (float)Forward_Speed_nomal / 0x05);
};
// 下斜坡
void Back_Slope(Move &move)
{
    move.moveForwardByDistance(Forward_Distance, (float)Forward_Speed_nomal / 0x05);
};
// 限高杆
void Limit_High(Move &move)
{

    move.setBodyHeight(Limit_Height / 0x05);
    move.moveForwardByDistance(Forward_Distance_limit, (float)Forward_Speed_limit / 0x05);
};
// 路障区
void Pillor(Move &move)
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
};
// 上台阶
void Forword_Step(Move &move)
{
    move.moveForwardByDistance(Forward_Distance_stairs, (float)Forward_Speed_stairs / 0x05);
    move.climbStairs(true); // 上台阶  
};
// 下台阶
void Back_Step(Move &move)
{
    move.moveForwardByDistance(Forward_Distance_stairs_down, (float)Forward_Speed_stairs_down / 0x05);
};

int main(char *argc, char *argv[])
{
    Move move;
    unsigned int input;
    std::cout << " 请输入操作 " << std::endl
              << "1. 上斜坡 " << std::endl
              << "2. 下斜坡 " << std::endl
              << "3. 限高杆 " << std::endl
              << "4. 路障区 " << std::endl
              << "5. 上台阶 " << std::endl
              << "6. 下台阶 " << std::endl
              << "7. 基础测试 " << std::endl;
    std::cin >> input;
    switch (input)
    {
    case 1:
        Forword_Slope(move);
        break;
    case 2:
        Back_Slope(move);
        break;
    case 3:
        Limit_High(move);
        break;
    case 4:
        Pillor(move);
        break;
    case 5:
        Forword_Step(move);
        break;
    case 6:
        Back_Step(move);
        break;
    case 7:
        while (1)
        {
            std::cout << "请输入操作" << std::endl;
            std::cout << "1. 前进 " << std::endl;
            std::cout << "2. 左转 " << std::endl;
            std::cout << "3. 右转 " << std::endl;
            std::cout << "4. 矫正 " << std::endl;
            std::cin >> input;
            switch (input)
            {
            case 1:
                Forword(move);
                break;
            case 2:
                turn_left(move);
                break;
            case 3:
                turn_right(move);
                break;
            case 4:
                Justify(move);
                break;
            default:
                break;
            }
        }
        break;
    default:
        break;
    }
    while (true)
        ;
    return 0;
}