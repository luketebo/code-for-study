//合并有序链表
//我可以创建两个简单的链表呀
#include<iostream>
using namespace std;
//创建链表
typedef struct lnode{
    int data;
    struct lnode*next;
}lnode,*linklist;

void Initlist(linklist &L){
    L=new lnode;   //生成新结点作为头结点，用头指针l指向头结点
    L.next=null;   //头结点的指针域设为空

}
void Createlist(linklist &l,int n){   //前插法创建单链表
    l=new lnode;
    l.next=null;
    linklist p;
    for(int i=0;i<n;i++){
        
        p=new lnode;
        cin>>p.data;
        p.next=l.next;l.next=p;
    }
    //打印链表
    cout<<endl<<"输出链表";
    for(p=l.next;p!=null;p=p.next){
        cout<<p.data<<" ";
        cout<<endl<<endl;
    }
}
void Mergelist(linklist &la,linklist &lb,linllist &lc){
    linklist pa,pb,pc,p;
    pa=la.next;
    pb=lb.next;
    lc=pc=la;
    while(pa&&pb){
        if(pa.data<=pb.data){
            pc.next=pa;
            pc=pa;
            pa=pa.next;
        }
        else{
            pc.next=pb;
            pc=pb;
            pb=pb.next;
        }
    }
    pc.next=pa?pa:pb;
        free(lb);   //释放lb的头结点
        for(p=lc.next;p!=null;p=p.next){
            cout<<p.data<<" ";
            cout<<endl<<endl;
        }
}
int main(){
    linklist la,lb,c;
    cout<<"创建la"<<endl;
    Createlist(la,5);
    cout<<"创建lb"<<endl;
    Createlist(lb,4);
    Mergelist(la,lb,c);
    return 0;
}