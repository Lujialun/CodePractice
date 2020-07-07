#include <iostream>
#include <stack>
using namespace std;

struct BinTreeNode{
    char data;
    BinTreeNode *left,*right;
    BinTreeNode():left(NULL),right(NULL){}
    BinTreeNode(char x,BinTreeNode *l=NULL,BinTreeNode *r=NULL):data(x),left(l),right(r){}
};
class BinaryTree{
public:
    BinaryTree():root(NULL){}
    //ָ��������־�Ĺ��캯��
    BinaryTree(char value) : RefValue(value), root(NULL) {}
    void CreatBinaryTree();//�ù��������������
    void PreOrder(BinTreeNode *&r);
    void InOrder(BinTreeNode *&r);
    void PostOrder(BinTreeNode *&r);

    void PreOrder_NoRecurve(BinTreeNode *r);
    void InOrder_NoRecurve(BinTreeNode *r);
    void PostOrder_NoRecurve(BinTreeNode *r);

    BinTreeNode  *root;
private:
    char RefValue;
};
void BinaryTree::CreatBinaryTree()
{
        stack< BinTreeNode * > s;
        BinTreeNode  *&BT=this->root;

        BT = NULL;
        BinTreeNode  *p, *t;    //p������ס��ǰ�����Ľڵ㣬char������סջ����Ԫ��
        int k;    //k�Ǵ������������ı��
        char ch;
        cout<<"�������Ĺ�������У�\n";
        cin >> ch;

        while (ch != RefValue)
        {
            switch (ch)
            {
            case '(':    //��(������
                s.push(p);
                k = 1;
                break;

            case ')':    //��)������
                s.pop();
                break;

            case ',':    //��,������
                k = 2;
                break;

            default:
                p = new BinTreeNode (ch);    //����һ�����
                if (BT == NULL)    //���ͷ�ڵ��ǿ�
                {

                    BT = p;
                }
                else if (k == 1)    //����*char������
                {
                    t = s.top();
                    t->left = p;
                }
                else    //����*char���Һ���
                {
                    t = s.top();
                    t->right = p;
                }
            }
            cin >> ch;
        }
        cout<<"������ɣ�"<<endl;
}

void BinaryTree::PreOrder(BinTreeNode *&r)
{
   // cout<<r->data<<endl;
    if(r==NULL) return;
    cout<<r->data<<" ";
    PreOrder(r->left);
    PreOrder(r->right);

}

void BinaryTree::InOrder(BinTreeNode *&r)
{
    if(r==NULL) return;
    InOrder(r->left);
    cout<<r->data<<" ";
    InOrder(r->right);
}

void BinaryTree::PostOrder(BinTreeNode *&r)
{
   // cout<<r->data<<endl;
    if(r==NULL) return;
    PostOrder(r->left);
    PostOrder(r->right);
    cout<<r->data<<" ";

}

void BinaryTree::PreOrder_NoRecurve(BinTreeNode *r)
{
    stack<BinTreeNode*> s;
    s.push(NULL);
    while(r!=NULL){
        cout<<r->data<<" ";
        if(r->right!=NULL) s.push(r->right);
        if(r->left!=NULL) r=r->left;
        else{
            r=s.top();
            s.pop();
        }
    }
}

void BinaryTree::InOrder_NoRecurve(BinTreeNode *p)
{
    stack<BinTreeNode*> s;
    while(p!=NULL || !s.empty()){
        while(p!=NULL){
            s.push(p);
            p=p->left;
        }
        if(!s.empty()){
            p=s.top();
            s.pop();
            cout<<p->data<<" ";
            p=p->right;
        }
    }
}

void BinaryTree::PostOrder_NoRecurve(BinTreeNode *p)
{
    if(p==NULL) return;
    stack<BinTreeNode*> s;
    s.push(p);
    BinTreeNode *LastPop=NULL;
    while(!s.empty()){
        while(s.top()->left!=NULL){//����ջ��Ϊ��ײ���Ҷ��
            s.push(s.top()->left);
        }

        while(!s.empty()){
            if(LastPop==s.top()->right || s.top()->right==NULL){//1�����ջ���Һ��Ӹճ�ջ����ջ���ɳ�ջ��2��
                cout<<s.top()->data<<" ";
                LastPop=s.top();
                s.pop();
            }else if(s.top()->right != NULL){
                s.push(s.top()->right);
                break;
            }
        }
    }

}

int main()
{
    BinaryTree BT('#');
    BT.CreatBinaryTree();
    cout<<"\nǰ�������\n";
    BT.PreOrder_NoRecurve(BT.root);
    cout<<"\n���������\n";
    BT.InOrder_NoRecurve(BT.root);
    cout<<"\n���������\n";
    BT.PostOrder_NoRecurve(BT.root);
}


/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> vin) {
        int len=pre.size();
        if(len==0) return NULL;
        TreeNode* root = new TreeNode(pre[0]);
        if(len==1) return root;
        int p=0;
        for(int i = 0; i<len; i++){
            if(vin[i]==pre[0])   {p=i; break;}
        }
        vector<int> preL,vinL,preR,vinR;

        for(int i=0; i<p; ++i){
            preL.push_back(pre[i+1]);
            vinL.push_back(vin[i]);
        }

        for(int i=p+1; i<len; ++i){
            preR.push_back(pre[i]);
            vinR.push_back(vin[i]);
        }
        root->left = reConstructBinaryTree(preL,vinL);
        root->right = reConstructBinaryTree(preR,vinR);
        return root;
    }
};
