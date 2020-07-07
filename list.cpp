#include<iostream>
#include<stack>
using namespace std;
//单链表删除、查找
struct ListNode{
    int value;
    ListNode * next;
  //  ListNode():value(0),next(NULL){}
   // ListNode(int x):value(x),next(NULL){}
};

//struct DListNode{
//    int value;
//    DListNode* prev,*next;
//};


class LinkedList{
public:
    LinkedList();
    ~LinkedList();
    int CreateList(int n);//创建链表
    int TravalList();//遍历链表
    int ReverseTraverList();//反向遍历链表
    int InsertList(ListNode* node,int n);//任意点插入
    int DeleteList(int n);//任意点删除
    int FindReverseKNode(int k);//倒数第K个节点
    ListNode* FindCrossPoint(LinkedList l);//找相交点
    int IfCircle();//是否成环
    int ReverseList();
 //   LinkedList AddTwoList(LinkedList L1, LinkedList L2);
    ListNode* head;
};


LinkedList::LinkedList()
{
    head=NULL;
//    head=new ListNode();
//    head->next=NULL;
//    head->value=0;
}

LinkedList::~LinkedList()
{
    delete head;
}

LinkedList::CreateList(int n)
{
    if(n<0){
        cout<<"error"<<endl;
        return -1;
    }
    this->head=new ListNode;
    ListNode* p=this->head;
    int v;
    cout<<"按序输入链表节点值："<<endl;
    cin>>v;
    p->value=v;
    for(int i=0; i<n-1; i++){
        ListNode* pNew=new ListNode();
        cin>>v;
        pNew->next=NULL;
        pNew->value=v;
        p->next=pNew;
        p=p->next;
    }
  //  p->next=this->head->next; huan
    cout<<"Done!"<<endl;
    return 0;
}

LinkedList::TravalList()
{
    if(this->head==NULL){
        cout<<"list is empty"<<endl;
        return -1;
    }
    ListNode* p=head;
    while(p!=NULL){
        cout<<p->value<<"->";
        p=p->next;
    }
    cout<<"NULL"<<endl;
    return 0;
}

LinkedList::ReverseTraverList()
{
    if(this->head==NULL){
        cout<<"list is empty"<<endl;
        return -1;
    }
    stack<int> tmp;
    ListNode* p=head;
    cout<<"NULL";
    while(p!=NULL){
        //cout<<p->value<<"->";
        tmp.push(p->value);
        p=p->next;
    }
    while(!tmp.empty()){
        cout<<"->"<<tmp.top();
        tmp.pop();
    }
    cout<<endl;

    return 0;
}

LinkedList::InsertList(ListNode* node,int n)
{
    ListNode* p=this->head;
    if(n==1){
        this->head=node;
        this->head->next=p->next;

        return 0;
    }
    int cnt=0;
    while(p){
        cnt++;
        if(p->next==NULL){
            p->next=node;
            return 0;
        }
        if(cnt==n-1){
            node->next=p->next;
            p->next=node;
            return 0;
        }
        p=p->next;
    }
    return 0;
}

LinkedList::DeleteList(int n)
{
     ListNode* p=this->head;
    if(n==1){
        this->head=this->head->next;
        free(p);
        return 0;
    }
    int cnt=0;
    while(p){
        cnt++;
        if(p->next->next==NULL){
            ListNode* pTmp=p->next;
            p->next=NULL;
            free(pTmp);
            return 0;
        }
        if(cnt==n-1){
            ListNode* pTmp=p->next;
            p->next=pTmp->next;
            free(pTmp);
            return 0;
        }
        p=p->next;
    }
    return 0;
}

LinkedList::FindReverseKNode(int k)
{
    ListNode* slow=this->head;
    ListNode* fast=this->head;
    int cnt=0;
    while(fast->next!=NULL){
        if(cnt!=k) cnt++;
        fast=fast->next;
        if(cnt==k){
            slow=slow->next;
        }
    }
    if(cnt!=k){
        cout<<"noting"<<endl;
        return 0;
    }
    cout<<slow->value<<endl;
    return 0;
}

LinkedList::ReverseList()
{
    ListNode* p=this->head;
    ListNode* pTem=this->head->next;
    ListNode* q=new ListNode;
    p->next=NULL;
    while(pTem!=NULL){
        q=pTem;
        pTem=pTem->next;
        q->next=p;
        p=q;
    }
    this->head=p;
    return 0;
}

ListNode* LinkedList::FindCrossPoint(LinkedList l)
{
    ListNode* l1=this->head;
    ListNode* l2=l.head;
    int size1=0,size2=0,dis;
    while(l1!=NULL){
        size1++;
        l1=l1->next;
    }

    while(l2!=NULL){
        size2++;
        l2=l2->next;
    }
    l1=this->head;
    l2=l.head;
    if(size1>size2){
        dis=size1-size2;
        while(dis--) l1=l1->next;
    }else{
        dis=size2-size1;
        while(dis--) l2=l2->next;
    }

    while(l1!=NULL){
        if(l1==l2) return l1;
        l1=l1->next;
        l2=l2->next;
    }

    return NULL;
}

LinkedList::IfCircle()
 {
     ListNode* fast=this->head;
     ListNode* slow=this->head;
     while(fast!=NULL){
        fast=fast->next;
        if(!fast) return 0;
        fast=fast->next;
        slow=slow->next;
        if(slow==fast) return 1;
     }
     return 0;
 }

 LinkedList AddTwoList(LinkedList &L1, LinkedList &L2)
 {
    stack<ListNode*> a,b;
    ListNode* p1=L1.head;
    ListNode* p2=L2.head;
    int temp=0;
    int c1=0,c2=0;
    while(p1!=NULL){
        a.push(p1);
        p1=p1->next;
        c1++;
    }
    while(p2!=NULL){
        b.push(p2);
        p2=p2->next;
        c2++;
    }

    if(c1>=c2){
        while(!a.empty()){
            temp+=a.top()->value;
            if(!b.empty()){
                temp+=b.top()->value;
                b.pop();
            }
            a.top()->value=temp%10;
            temp/=10;
            a.pop();
        }
        if(temp>0){
            ListNode* node=new ListNode;
            node->value=temp;
            node->next=L1.head;
            L1.head=node;
        }
        return L1;
    }else{
        while(!b.empty()){
            temp+=b.top()->value;
            if(!a.empty()){
                temp+=a.top()->value;
                a.pop();
            }
            b.top()->value=temp%10;
            temp/=10;
            b.pop();
        }
        if(temp>0){
            ListNode* node=new ListNode;
            node->value=temp;
            node->next=L2.head;
            L2.head=node;
        }
        return L2;
    }
 //   while()
 }

//  ListNode* EntryNodeOfLoop(ListNode* pHead)
//    {
//        ListNode* slow=pHead;
//        ListNode* fast=pHead;
//        while(fast!=NULL){
//            fast=fast->next->next;
//            slow=slow->next;
//            if(slow==fast) break;
//        }
//
//        slow=pHead;
//        while(fast!=NULL){
//            fast=fast->next;
//            slow=slow->next;
//            if(slow==fast) return slow;
//        }
//    }

    ListNode* deleteDuplication(ListNode* pHead)
    {
        if(pHead==NULL||pHead->next==NULL) return pHead;
        ListNode* PCUR=new ListNode;
        PCUR->next=pHead;
        pHead=PCUR;
        ListNode *L,*R;
        while(PCUR->next != NULL)
        {
            L=PCUR->next;
            R=PCUR->next;
            while(R->next && R->next->val==L->val)
                R=R->next;
            //如果循环后，L与R节点相同，说明不重复
            if(L == R) PCUR=PCUR->next;
            //L与R节点不相同，将PCUR的next指向R->next,继续重复上述操作
            else
            {
                PCUR->next=R->next;
                //C++没有内存回收机制，应该释放这些指针，虽然不释放能通过，但是应该养成好习惯
                while(L!=R)
                {
                    ListNode*tmp=L;
                    L=L->next;
                    delete tmp;
                }
                delete L;
            }
        }
        return pHead->next;
    }

int main()
{
    LinkedList l1,l2;
//   // l.TravalList();
    l1.CreateList(6);
    deleteDuplication(l1.head);
    l1.TravalList();
   // cout<<l1.IfCircle()<<endl;
//    l1.TravalList();
 //   l2.CreateList(5);
//    l2.TravalList();
//    ListNode* p=new ListNode;
//    p->value=66;
//    p->next=NULL;
//    l1.InsertList(p,7);
  //  l1.TravalList();
//    l2.InsertList(p,7);
//    l2.TravalList();
//    l.DeleteList(3);
//    l.TravalList();
//    l.ReverseTraverList();
////    l.FindReverseKNode(1);
//    l.ReverseList();
//    l.TravalList();
//    ListNode* q=l1.FindCrossPoint(l2);
//    if(q==NULL) cout<<"无"<<endl;
//    else cout<<p->value<<endl;
   // LinkedList l3=AddTwoList(l1,l2);
    //l3.TravalList();

}
