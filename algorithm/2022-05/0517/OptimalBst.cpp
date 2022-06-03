/**
 * @file OptimalBst.cpp
 * @author Luke Tebo (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-05-17
 * 
 * @copyright Copyright (c) 2022
 * 
 * 最优二叉搜索树
 */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define MAX 999999
/* 打印二叉树 */
void print_tree(vector<vector<int>>root, int i, int j, int parent)
{
    int r = root[i][j];
    
    if (!parent) {
        cout << "根是k" << r << endl;
    }
    else if (parent == 1) {
        cout << "k" << r << "是k" << j + 1 << "的左孩子" << endl;
    }
    else {
        cout << "k" << r << "是k" << i - 1 << "的右孩子" << endl;
    }
    
    if (j == i) {
        cout << "d" << r - 1 << "是k" << r << "的左孩子" << endl;
        cout << "d" << r << "是k" << r << "的右孩子" << endl;
        return;
    }
    else if (i == r) {
        cout << "d" << r - 1 << "是k" << r << "的左孩子" << endl;
        print_tree(root, r + 1, j, 2);
        return;
    }
    else if (j == r) {
        print_tree(root, i, r - 1, 1);
        cout << "d" << r << "是k" << r << "的右孩子" << endl;
        return;
    }
    else {
        print_tree(root, i, r - 1, 1);
        print_tree(root, r + 1, j, 2);
    }
    
}
/* 动态规划 */
void OptimalBinarySearchTree(vector<int> p, vector<float> q, int n) { 
    // 期望搜索代价
    vector<vector<int>> e(n + 2);
    // 概率总和
    vector<vector<int>> w(n + 2);
    // 存储结果
    vector<vector<int>> root(n + 2);

    // 初始化
    for (int i = 0; i < n + 2; i++) {
        e[i].resize(n + 1);
        w[i].resize(n + 1);
    }
    for (int i = 0; i < n + 1; i++) {
        root[i].resize(n + 1);
    }

    for (int i = 1; i < n + 1; i++) {
        e[i][i - 1] = q[i - 1];
        w[i][i - 1] = q[i - 1];
    }
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n - k + 1; i++) {
            int j = i + k - 1;
            e[i][j] = MAX;
            w[i][j] = w[i][j - 1] + p[j] + q[j];
            for (int r = i; r <= j; r++) {
                float t = e[i][r - 1] + e[r + 1][j] + w[i][j];
                if (t < e[i][j]) {
                    e[i][j] = t;
                    root[i][j] = r;
                }
            }
        }
    }
    cout << "e:" << e[1][n] << endl;
    
    print_tree(root, 1, n, 0);
    


}
int main(){
    int n;
    cin >> n;
    vector<int> p(n + 1);
    vector<float> q(n + 1);
    for (int i = 0; i < p.size() - 1; i++) {
        cin >> p[i];
    }

    for (int i = 0; i < q.size() - 1; i++) {
        cin >> q[i];
    }
    OptimalBinarySearchTree(p, q, n);
    return 0;
}