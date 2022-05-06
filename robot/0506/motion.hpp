#include "unitree_legged_sdk/unitree_legged_sdk.h"
using namespace UT;

#ifndef MOTION
#define MOTION

class Move
{
private:
    bool prt;
    static UDP udp;
    static HighCmd cmd;
    static HighState state;
    static int clock;
    static int distanceX;
    static int distanceY;
    static int angle;
    static void *timer(void *)
    {
        printf("时钟线程启动...\n");
        while (true)
        {
            clock++;
            usleep(1000);
        }
    }

    static void *status(void *)
    {
        printf("通信线程启动...\n");
        while (true)
        {
            udp.Send();
            udp.Recv();
            udp.GetRecv(state);
            usleep(1000 * 2);
        }
    }

    static void *walk_timerX(void *)
    {
        printf("计步线程(1/2)启动...\n");
        bool flag = false;
        bool mo_flag = false;
        while (true)
        {
            if (distanceX > 0)
            {
                while (distanceX-- > 0)
                {
                    if(!(clock%42) && !mo_flag)
                    {
                        mo_flag = true;
                        printf("修正偏移... Clock: %d\n", clock);
                        cmd.yawSpeed += 0.1;
                        udp.SetSend(cmd);
                    }
                    if(!(clock%43) && mo_flag)
                    {
                        mo_flag = false;
                        printf("修正结束... Clock: %d\n", clock);
                        cmd.yawSpeed -= 0.1;
                        udp.SetSend(cmd);
                    }
                    printf("distanceX remain: %d\r", distanceX);
                    flag = true;
                    usleep(1000);
                }
                if(mo_flag)
                {
                    cmd.yawSpeed -= 0.1;
                    udp.SetSend(cmd);
                }
                printf("\n");
            }
            if (flag)
            {
                cmd.velocity[0] = 0;
                udp.SetSend(cmd);
                flag = false;
            }
            usleep(1000);
        }
    }

    static void *walk_timerY(void *)
    {
        printf("计步线程(2/2)启动...\n");
        bool flag = false;
        while (true)
        {
            if (distanceY > 0)
            {
                while (distanceY-- > 0)
                {
                    printf("distanceY remain: %d\r", distanceY);
                    flag = true;
                    usleep(1000);
                }
                printf("\n");
            }
            if (flag)
            {
                cmd.velocity[1] = 0;
                udp.SetSend(cmd);
                flag = false;
            }
            usleep(1000);
        }
    }

    static void *spin_timer(void *)
    {
        printf("旋转线程启动...\n");
        bool flag = false;
        while (true)
        {
            if (angle > 0)
            {
                while (angle--)
                {
                    printf("spin remain: %d\r", angle);
                    flag = true;
                    usleep(1000);
                }
                printf("\n");
            }
            if (flag)
            {
                // memset(&cmd, 0, sizeof(cmd));
                cmd.yawSpeed = 0;
                udp.SetSend(cmd);
                flag = false;
            }
            usleep(1000);
        }
    }

public:
    // 各种常量
    const int forward = 0;
    const int backward = 1;
    const int left = 2;
    const int right = 3;
    const int up = 4;
    const int down = 5;
    // mode
    const int idle = 0; // 啥也不干
    const int stand = 1;
    const int walk = 2;
    const int step = 3; // 按照位置信息移动
    const int sitdown = 5;
    const int standup = 6;
    const int backflip = 9;
    const int jumpYaw = 10;
    const int straightHand = 11;
    const int danceA = 12;
    const int danceB = 13;
    // gaitType
    const int slow = 0;
    const int normal = 1;
    const int fast = 2;
    const int stair = 3;

    // 初始化环境
    Move(bool p = false)
    {
        prt = p;
        udp.InitCmdData(cmd);
        pthread_t x[5];
        pthread_create(&x[0], NULL, timer, NULL);
        pthread_create(&x[1], NULL, status, NULL);
        pthread_create(&x[2], NULL, walk_timerX, NULL);
        pthread_create(&x[3], NULL, walk_timerY, NULL);
        pthread_create(&x[4], NULL, spin_timer, NULL);
        usleep(1000);
    }

    // 功能性代码
    void printimu()
    {
        printf("%f\t%f\t%f\n", state.imu.quaternion[0], state.imu.accelerometer[1], state.imu.accelerometer[2]);
    }

    void printclock()
    {
        printf("%d", clock);
    }

    int getclock()
    {
        return clock;
    }

    float getQuaternionW()
    {
        return state.imu.quaternion[0];
    }

    float getQuaternionX()
    {
        return state.imu.quaternion[1];
    }

    float getQuaternionY()
    {
        return state.imu.quaternion[2];
    }

    float getQuaternionZ()
    {
        return state.imu.quaternion[3];
    }

    float getAcceleroMeterX()
    {
        return state.imu.accelerometer[0];
    }

    float getAcceleroMeterY()
    {
        return state.imu.accelerometer[1];
    }

    float getAcceleroMeterZ()
    {
        return state.imu.accelerometer[2];
    }

    float getdistanceX()
    {
        return state.position[0];
    }

    float getdistanceY()
    {
        return state.position[1];
    }

    float getdistanceZ()
    {
        return state.position[2];
    }

    float getBodyHeight()
    {
        return state.bodyHeight;
    }

    float getVelocitySpeedX()
    {
        return state.velocity[0];
    }

    float getVelocitySpeedY()
    {
        return state.velocity[1];
    }

    void reset() // 重置动作
    {
        if (prt)
            printf("重置指令\n");
        memset(&cmd, 0, sizeof(cmd));
    }

    void recovery() // 恢复站立状态
    {
        if (prt)
            printf("恢复站立状态\n");
        reset();
        cmd.mode = walk;
        cmd.velocity[0] = 0.01;
        exec(1000);
        cmd.mode = stand;
        exec(0);
    }

    void exec(int t = 0) // 执行之前的动作 动作执行所需时间
    {
        if (prt)
            printf("执行动作\n");
        udp.SetSend(cmd);
        usleep(1000 * t);
    }

    void setMode(int t)
    {
        if (prt)
            printf("设置模式\n");
        cmd.mode = t;
        exec();
    }

    void setGaitType(int t)
    {
        if (prt)
            printf("设置步频\n");
        cmd.gaitType = t;
        exec();
    }

    void setBodyHeight(float t) // 设置高度 完成
    {
        if (prt)
            printf("设置高度\n");
        if (!cmd.mode)
            cmd.mode = 1;
        printf("height: %f\n", 0.01 * t);
        cmd.bodyHeight = 0.01 * t;
        exec();
    }

    void setSpeed(int c, float t)
    {
        if (prt)
            printf("设置速度\n");
        switch (c)
        {
        case 0:
            cmd.velocity[0] = t;
            break;
        case 1:
            cmd.velocity[0] = -1 * t;
            break;
        case 2:
            cmd.velocity[1] = t;
            break;
        case 3:
            cmd.velocity[1] = -1 * t;
            break;
        }
        exec();
    }

    void Do(int a, bool flag = true) // 特殊动作 完成
    {
        if (prt)
            printf("执行特殊动作\n");
        reset();
        switch (a)
        {
        case 9:
            cmd.mode = backflip;
            udp.SetSend(cmd);
            usleep(1000 * 1000 * 6);
            break;
        case 10:
            cmd.mode = jumpYaw;
            udp.SetSend(cmd);
            usleep(1000 * 1000 * 2);
            break;
        case 11:
            cmd.mode = straightHand;
            udp.SetSend(cmd);
            usleep(1000 * 1000 * 9);
            break;
        case 12:
            cmd.mode = danceA;
            udp.SetSend(cmd);
            break;
        case 13:
            cmd.mode = danceB;
            udp.SetSend(cmd);
            break;
        }
    }

    void moveForward(bool flag = true) // 前进 完成
    {
        if (prt)
            printf("前进\n");
        if (flag)
            reset();
        cmd.mode = walk;
        cmd.gaitType = normal;
        cmd.velocity[0] = 0.5f; // -1 ~ +1
        turnLeft(0.01f,false);
        exec();
    }

    void moveForwardBySpeed(float t, bool flag = true) // 以设定速度前进 完成
    {
        if (prt)
            printf("前进\n");
        if (flag)
            reset();
        cmd.mode = walk;
        cmd.gaitType = normal;
        cmd.velocity[0] = t;
        exec();
    }

    void moveForwardByDistance(float d = 1, float t = 0.5, bool flag = true, bool suspend = false) // 以一定速度前进固定距离 完成
    {
        if (flag)
            reset();
        moveForwardBySpeed(t, false);
        distanceX = d*660/t;
        for (int tmp = d*660 / t; suspend && tmp; tmp--)
            usleep(1000);
    }

    void moveBackward(bool flag = true) //后退
    {
        if (prt)
            printf("后退\n");
        if (flag)
            reset();
        cmd.mode = walk;
        cmd.gaitType = normal;
        cmd.velocity[0] = -0.5f;
        exec();
    }

    void moveBackwardBySpeed(float t, bool flag = true) //以设定速度后退
    {
        if (prt)
            printf("后退\n");
        if (flag)
            reset();
        cmd.mode = walk;
        cmd.gaitType = normal;
        cmd.velocity[0] = -1.0 * t;
        exec();
    }

    void moveBackwardByDistance(float d = 1, float t = 0.5f, bool flag = true, bool suspend = false) //后退固定距离 完成
    {
        if (prt)
            printf("后退\n");
        if (flag)
            reset();
        moveBackwardBySpeed(t, false);
        distanceX = d * 660 / t;
        for (int tmp = d * 660 / t; suspend && tmp; tmp--)
            usleep(1000);
    }

    void moveLeft(bool flag = true) //左平移  完成
    {
        if (prt)
            printf("左移\n");
        if (flag)
            reset();
        cmd.mode = walk;
        cmd.gaitType = normal;
        cmd.velocity[1] = 0.5f;
        exec();
    }

    void moveLeftBySpeed(float t, bool flag = true) //以设定速度向左平移
    {
        if (prt)
            printf("左移\n");
        if (flag)
            reset();
        cmd.mode = walk;
        cmd.gaitType = normal;
        cmd.velocity[1] = t;
        exec();
    }

    void moveLeftByDistance(float d = 1, float t = 0.5, bool flag = true, bool suspend = false) //左平移固定距离 完成
    {
        if (flag)
            reset();
        moveLeftBySpeed(t, false);
        distanceY = d * 660 / t;
        for (int tmp = d * 660 / t; suspend && tmp; tmp--)
            usleep(1000);
    }

    void moveRight(bool flag = true) //右平移  完成
    {
        if (flag)
            reset();
        cmd.mode = walk;
        cmd.gaitType = normal;
        cmd.velocity[1] = -0.5f;
        exec();
    }

    void moveRightBySpeed(float t, bool flag = true) //以设定的速度右平移
    {
        if (prt)
            printf("右移\n");
        if (flag)
            reset();
        cmd.mode = walk;
        cmd.gaitType = normal;
        cmd.velocity[1] = -t;
        exec();
    }

    void moveRightByDistance(float d = 1, float t = 0.5f, bool flag = true, bool suspend = false) //右平移固定的距离
    {
        if (flag)
            reset();
        moveRightBySpeed(t, false);
        distanceY = d * 660 / t;
        for (int tmp = d * 660 / t; suspend && tmp; tmp--)
            usleep(1000);
    }

    void turnLeft(float t = 0.5f, bool flag = true) //左转 完成
    {
        if (prt)
            printf("左转\n");
        if (flag)
            reset();
        cmd.mode = walk;
        cmd.gaitType = normal;
        cmd.yawSpeed = t;
        exec();
    }

    void turnLeftByAngle(int a = 90, float t = 0.5f, bool flag = true, bool suspend = false)
    {
        turnLeft(t, false);
        angle = a*1.0/180 * 3.14 * 1200 / t;
        for (int tmp = a*1.0/180 * 3.14 * 1200 / t; suspend && tmp; tmp--)
            usleep(1000);
    }

    void turnRight(float t = 0.5f, bool flag = true) //右转 完成
    {
        if (prt)
            printf("右转\n");
        if (flag)
            reset();
        cmd.mode = walk;
        cmd.gaitType = normal;
        cmd.yawSpeed = -1.0 * t;
        exec();
    }

    void turnRightByAngle(int a = 90, float t = 0.5f, bool flag = true, bool suspend = false)
    {
        turnRight(t, false);
        angle = a*1.0/180 * 3.14 * 1200 / t;
        for (int tmp = a*1.0/180*3.14 * 1200 / t; suspend && tmp; tmp--)
            usleep(1000);
    }

    void toLeft(bool flag = true) //左倾 完成
    {
        if (prt)
            printf("左倾身体\n");
        if (flag)
            reset();
        cmd.mode = stand;
        cmd.euler[0] = -0.5;
        exec();
    }

    void toRight(bool flag = true) //右倾 完成
    {
        if (prt)
            printf("右倾身体\n");
        if (flag)
            reset();
        cmd.mode = stand;
        cmd.euler[0] = 0.5;
        exec();
    }

    void
    leanForward(bool flag = true) //前倾 完成
    {
        if (prt)
            printf("低头\n");
        if (flag)
            reset();
        cmd.mode = stand;
        cmd.euler[1] = 0.7;
        exec();
    }

    void leanBackward(bool flag = true) //后仰 完成
    {
        if (prt)
            printf("抬头\n");
        if (flag)
            reset();
        cmd.mode = stand;
        cmd.euler[1] = -0.7;
        exec();
    }

    void squats(bool flag = true) //蹲下 完成
    {
        if (prt)
            printf("仰头蹲下\n");
        if (flag)
            reset();
        cmd.mode = stand;
        cmd.euler[1] = -0.9;
        setBodyHeight(-6);
        exec();
    }

    void standUp(bool flag = true) //起立
    {
        if (prt)
            printf("起立\n");
        if (flag)
            reset();
        cmd.mode = standup;
        exec();
    }

    void jump(bool flag = true) //跳跃
    {
        if (prt)
            printf("\n");
        if (flag)
            reset();
    }
    void jumpLeft(bool flag = true) //跳转90度
    {
        if (prt)
            printf("跳起并转向\n");
        if (flag)
            reset();
        cmd.mode = jumpYaw;
        exec();
    }

    void climbStairs(bool flag = true) // 爬楼梯
    {
        if (prt)
            printf("\n");
        if (flag)
            reset();
        cmd.mode = stand;
        cmd.gaitType = stair;
        exec();
    }

    void lieDown(bool flag = true) //卧倒
    {
        if (prt)
            printf("趴下\n");
        if (flag)
            reset();
        setBodyHeight(-90);
        exec();
    }

    void standStill(float t = 0.5, bool flag = true) //自定义速度原地踏步
    {
        if (prt)
            printf("原地踏步\n");
        if (flag)
            reset();
        cmd.mode = walk;
        cmd.velocity[0] = 0.1;
        exec();
    }
};

#endif

int Move::clock;
HighCmd Move::cmd = {0};
HighState Move::state = {0};
int Move::distanceX = 0;
int Move::distanceY = 0;
int Move::angle = 0;
UDP Move::udp(8090, "192.168.123.161", 8082, sizeof(HighCmd), sizeof(HighState));
