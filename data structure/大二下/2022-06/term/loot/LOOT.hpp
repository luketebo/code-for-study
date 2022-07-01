#include <bits/stdc++.h>
using namespace std;

#ifndef LOOT_H
#define LOOT_H
class loot
{
private:
    struct TreeNode
    {
        int val;
        TreeNode *left;
        TreeNode *right;
        TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    };

public:
    int rob(TreeNode *root)
    {
        vector<int> result = robTree(root);
        cout << "最高金额为: " << max(result[0], result[1]) << endl;
        return max(result[0], result[1]);
    }
    // 长度为2的数组，0：不偷，1：偷
    vector<int> robTree(TreeNode *cur)
    {
        if (cur == NULL)
            return vector<int>{0, 0};
        vector<int> left = robTree(cur->left);
        vector<int> right = robTree(cur->right);
        // 偷cur
        int val1 = cur->val + left[0] + right[0];
        cout << "偷当前的获得的价值: " << val1 << endl;
        // 不偷cur
        int val2 = max(left[0], left[1]) + max(right[0], right[1]);
        cout << "不偷当前的获得的价值: " << val2 << endl
             << endl;
        return {val2, val1};
    }

    void main()
    {
        int n;
        cout << "示例 7 [3,2,3,-1,3,-1,1]" << endl
             << "输入一课完全二叉树" << endl
             << "节点数：";
        cin >> n;
        cout << "输入完全二叉树的值：" << endl;
        TreeNode *root = new TreeNode(n);
        int t;
        cin >> t;
        root->val = t;
        cout << endl
             << "开始构造二叉树" << endl;

        for (int i = 2; i <= n; i += 2)
        {
            TreeNode *cur = root;
            // input left right child
            int l, r;
            cin >> l >> r;
            cout << endl
                 << "寻找" << l << "," << r << "的父节点"
                 << ", i: " << i << endl;

            // find the father node
            int target_layer = 1, target_nodes = 0, next_nodes = 0, pre_nodes = 0;
            for (int j = 1; j < n; j++)
            {
                int t = pow(2, j) - 1;
                if (t >= i)
                {
                    target_layer = j;
                    break;
                }
            }
            cout << "目标父节点在" << target_layer - 1 << "层" << endl;

            target_nodes = pow(2, target_layer) - pow(2, target_layer - 1);
            cout << "目标层的节点个数: " << target_nodes << endl;

            pre_nodes = pow(2, target_layer) - pow(2, target_layer - 1);

            for (int j = 1; j <= n; j++)
            {
                next_nodes = pow(2, j + 1) - pow(2, j);
                cout << "当前层: " << j << ", 下一层的节点个数: " << next_nodes << endl;

                for (int k = 0; k < next_nodes; k++)
                {
                    cout << "已累计的目标层节点: " << pre_nodes << endl;
                    if (target_layer == 2)
                        break;
                    if (i <= pow(2, j) - 1 + pre_nodes)
                    {
                        cout << "目标父亲节点在当前节点左孩子上, 当前节点值为: " << cur->val << endl;
                        cur = cur->left;
                        pre_nodes -= target_nodes / next_nodes;
                        break;
                    }
                    else
                    {
                        cout << "目标父亲节点在当前节点右孩子上, 当前节点值为: " << cur->val << endl;
                        pre_nodes += target_nodes / next_nodes;
                        cur = cur->right;
                        break;
                    }
                }
                if (cur->left == NULL && cur->right == NULL)
                {
                    cout << "目标父亲节点在当前节点上, 当前节点值为: " << cur->val << endl;
                    break;
                }
            }

            // build children
            if (l != -1)
            {
                cur->left = new TreeNode(l);
            }
            if (r != -1)
            {
                cur->right = new TreeNode(r);
            }
        }

        cout << endl
             << "构造完成" << endl << endl
             << "开始偷" << endl
             << loot::rob(root) << endl;
    }
};
#endif // LOOT_H