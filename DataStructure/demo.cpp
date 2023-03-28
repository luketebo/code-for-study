#include "iostream"
using namespace std;
struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
int main(){
    ListNode *head = new ListNode(5);
    ListNode* demo = new ListNode(5);

    cout << head << endl;
    cout << demo << endl;

    return 0;
}