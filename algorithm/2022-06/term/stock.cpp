# include<iostream>
using namespace std;

void myFrame();

class Solution {
public:
    int maxProfit(int *prices,int n) {
        int dp[n][2];
        dp[0][0] = 0, dp[0][1] = -prices[0];
        for (int i = 1; i < n; ++i) {
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i]);
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] - prices[i]);
        }
        return dp[n - 1][0];
    }
};

int main(){
    while(true){
        myFrame();
        int n;
        cout<<"请输入股市一共几天："; 
        cin>>n;
        int prices[n];
        cout<<"请依次输入股票的价格：";
        for(int i=0;i<n;i++)
            cin>>prices[i];
        Solution s;
        int max;
        max=s.maxProfit(prices,n);
        cout<<"您在该股市最大收益为："<<max<<endl; 
    }
}

void myFrame(){
    cout<<"*************************************"<<endl;
    cout<<"**                                    **"<<endl; 
    cout<<"**                                    **"<<endl; 
    cout<<"**                                    **"<<endl;
    cout<<"**           欢迎来到模拟股市!         **"<<endl; 
    cout<<"**                                    **"<<endl; 
    cout<<"**                                    **"<<endl; 
    cout<<"**                                    **"<<endl;
    cout<<"**                                    **"<<endl;
    cout<<"*************************************"<<endl;
    cout<<"               1.打开模拟市.            "<<endl;
    cout<<"               2.退出程序.              "<<endl;
    int choice;
    cout<<"请输入您的选择";
    cin>>choice;
    if(choice==2){
        exit(0);
    }
}
