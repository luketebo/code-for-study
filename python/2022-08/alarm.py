# 实现闹钟功能
class Alarm:
    def __init__(self):
        pass

    def alarm(self):
        """
        闹钟
        :return:
        """
        pass

    def input(self, things, count=1, time=25):
        """
        根据事件或者任务来进行定时
        count: 数量
        time: 时间
        things: 事件
        处理输入
        :return:
        """
        print(things)

        pass

    def countdown(self):
        """
        倒计时
        :return:
        """
        pass


a = Alarm()
event = input("请输入事件：")
a.input(event)