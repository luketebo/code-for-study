#include<iostream>
using namespace std;
struct Node{
    int data;
    struct Node*next;
};
Node *Creatlist(){
    int n;
    Node *head =new Node;
    Node *pre =head;
    cout<<"请输入该集合元素数量"<<endl;
    cin>>n;
    for(int i=0;i<n;i++){
        Node *p =new Node;
        cout<<"请输入"<<i+1<<"个元素"<<endl;
        cin>>p->data;
        pre->next=p;
        pre =p;
        p->next=NULL;
    }
    return head;
}
void prin(Node *head){
    Node *p=head->next;
    while(p!=NULL){
        cout<<p->data;
        p=p->next;
        cout<<" ";
    }
    cout<<endl;
}
void Diff(Node* La,Node* Lb)
{
	Node* p = La->next;
	Node* q = Lb->next;
	
	while(p != NULL && q != NULL)
	{
		if(p->data < q->data)
		{
			cout << p->data << "  ";
			p = p->next;
		}
		else if (p->data > q->data)
		{
			cout << q->data <<"  ";
			q = q->next;
		}
		else if (p->data == q->data)
		{
			q = q->next;
			p = p->next;
		}
	}
	while(p != NULL)
	{
		cout << p->data << "  ";
		p = p->next;
	}
	while(q != NULL)
	{
		cout << q->data <<"  ";
		q = q->next;
	}
}
int main(){
    Node* LA=Creatlist();
    Node* LB=Creatlist();
    Diff(LA,LB);
}
