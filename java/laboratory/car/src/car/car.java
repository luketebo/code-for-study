/*编写java程序。
定义一个汽车类，其中属性有速度，体积等等，
方法有移动，设置速度，加速、减速等等。
最后在mian方法中实例化一个交通工具对象，并通过方法对它进行初始化。
并且打印出来，调用加减速方法对速度进行改变。
*/
package car;

import java.util.Scanner;

public class car {
    private int speed;
    private int volume; // 体积
    private int distance; //

    car() {
        speed = 0;
        volume = 0;
        distance = 30;
    }

    // 移动
    void set_dis() {
        distance += 100;
        System.out.println("汽车移动了100米");
    }

    // 设置速度
    void set_speed() {
        Scanner read = new Scanner(System.in);
        System.out.println("请输入速度");
        speed = read.nextInt();
    }

    // 加速
    void add_speed() {
        Scanner read = new Scanner(System.in);
        System.out.println("请输入要提高的速度");
        speed = read.nextInt();

    }

    // 减速
    void sub_speed() {
        Scanner read = new Scanner(System.in);
        System.out.println("请输入要减小的速度");
        speed = read.nextInt();
    }

    // 展示信息
    void display() {
        System.out.println("速度：" + speed);
        System.out.println("移动距离：" + distance);
        System.out.println("体积：" + volume);
    }
}
