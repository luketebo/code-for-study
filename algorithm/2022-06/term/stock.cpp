#include <iostream>
using namespace std;

void myFrame();

class Solution
{
public:
    int maxProfit(int *prices, int in[], int out[], int n)
    {
        int dp[n][2], i, j, flag = 1;
        dp[0][0] = 0, dp[0][1] = -prices[0];
        for (int i = 1; i < n; ++i)
        {
            if (dp[i - 1][0] > dp[i - 1][1] + prices[i])
            {
                dp[i][0] = dp[i - 1][0];
                out[i] = 0;
            }
            else if (dp[i - 1][0] < dp[i - 1][1] + prices[i])
            {
                dp[i][0] = dp[i - 1][1] + prices[i];
                out[i - 1] = 0;
                out[i] = 1;
            }
            if (dp[i - 1][1] > dp[i - 1][0] - prices[i])
            {
                dp[i][1] = dp[i - 1][1];
                in[i] = 0;
            }
            else if (dp[i - 1][1] < dp[i - 1][0] - prices[i])
            {
                dp[i][1] = dp[i - 1][0] - prices[i];
                in[i - 1] = 0;
                in[i] = 1;
            }
        }
        if (dp[0][1] == dp[1][1])
            in[0] = 1; //遍历输出最优解
        if (dp[n - 1][0] == 0)
            cout << "没有买入和卖出" << endl;
        else
        {
            for (i = 0; i < n - 1; i++)
                if (in[i] == 1)
                    cout << "第" << i + 1 << "天买入    ";
            cout << endl;
            for (i = 0; i < n; i++)
                if (out[i] == 1)
                    cout << "第" << i + 1 << "天卖出    ";
            cout << endl;
        }
        return dp[n - 1][0];
    }
};

int main()
{
    while (true)
    {
        myFrame();
        int n;
        cout << "请输入股市一共几天：";
        cin >> n;
        int prices[n], in[n] = {0}, out[n] = {0};
        cout << "请依次输入股票的价格：";
        for (int i = 0; i < n; i++)
            cin >> prices[i];
        Solution s;
        int max;
        max = s.maxProfit(prices, in, out, n);
        cout << "您在该股市最大收益为：" << max << endl;
    }
}
void myFrame()
{
    cout << "*************************************" << endl;
    cout << "**                                    **" << endl;
    cout << "**                                    **" << endl;
    cout << "**                                    **" << endl;
    cout << "**           欢迎来到模拟股市!         **" << endl;
    cout << "**                                    **" << endl;
    cout << "**                                    **" << endl;
    cout << "**                                    **" << endl;
    cout << "**                                    **" << endl;
    cout << "*************************************" << endl;
    cout << "                1.打开模拟市.            " << endl;
    cout << "                2.退出程序.              " << endl;
    int choice;
    cout << "请输入您的选择：";
    cin >> choice;
    if (choice == 2)
    {
        exit(0);
    }
}
