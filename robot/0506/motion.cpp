#include "motion.hpp"
#include <iostream>

using namespace std;

int main()
{
    Move move(true);
    float t = 0;
    // move.Do(move.straightHand);
    // move.moveForward();
    // move.standStill();
    // while(t != 2)
    // {
    //     cin >> t;
    //     move.setBodyHeight(t);
    //     printf("%f,next: ",t);
    // }
    int choose;
        int d;
    cout << "输入操作: " << endl
    << "1. 向前后行走" << endl
    << "2. 向右走" << endl
    << "3. 左转" << endl
    << "4. 调头" << endl
    << "5. 向后走" << endl
    << "6. 拜年" << endl
    << "7. 移动测试" << endl
    << "8. 原地踏步" << endl
    << "9. 左转90度" << endl
    << "10. 行进测试" << endl
    << "11. 阻塞测试" << endl
    << "12. 高度调节" << endl
    << "13. 蹲下" << endl
    << endl;
    cin >> choose;
    switch (choose)
    {
    case 1:
        cout << "1. 向前\n2.向后: ";
        cin >> d;
        cout << "输入距离 速度: ";
        switch (d)
        {
        case 1:
            cin >> d;
            cin >> t;
            move.moveForwardByDistance(d,t);
            break;
        case 2:
            cin >> d;
            cin >> t;
            move.moveBackwardByDistance(d,t);
            break;
        }
        break;

    case 2:
        move.moveRight();
        break;

    case 3:
        cout << "请输入转向速度";
        cin >> t;
        move.turnLeft(t);
        break;
    
    case 4:
        move.turnRightByAngle(90);
        move.moveBackwardByDistance(1,0.5,false);
        sleep(2);
        move.turnLeftByAngle(90);
        move.moveForwardByDistance(1,0.5,false);
        sleep(2);
        move.recovery();
        break;
    case 5:
        cout << "请输入移动距离: ";
        cin >> d;
        move.moveBackwardByDistance(d);
        break;
    case 6:
        move.Do(move.straightHand);
        break;
    case 7:
        move.moveForwardByDistance(1,0.5,true,true);
        move.moveBackwardByDistance(1,0.6,true,true);
        move.moveRightByDistance(1,0.7,true,true);
        move.moveLeftByDistance(1,0.8,true,true);
        break;
    case 8:
        move.standStill();
        break;
    case 9:
        cin >> d;
        cin >> t;
        move.turnLeftByAngle(d,t);
        break;
    case 10:
        move.moveForwardByDistance(3);
        sleep(4);
        move.turnLeftByAngle(90);
        sleep(1);
        move.moveForwardByDistance(1);
        sleep(2);
        move.turnLeftByAngle(180);
        sleep(2);
        move.moveForwardByDistance(2);
        sleep(3);
        move.turnRightByAngle(90);
        sleep(1);
        move.moveForwardByDistance(3);
        break;
    case 11:
        move.moveForwardByDistance(1,0.5,true,true);
        move.lieDown();
        break;
    case 12:
        while(true)
        {
            float h = 0;
            cin >> h;
            move.setBodyHeight(h);
        }
    case 13:
        // move.sitDown();
        move.squats();
        break;
    }

    // move.turnRight();
    // move.recovery();
    cout << "\n结束按CTRL+C退出\n";
    while (true);
}