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
    //指定结束标志的构造函数
    BinaryTree(char value) : RefValue(value), root(NULL) {}
    void CreatBinaryTree();//用广义表创建，待完善
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
        BinTreeNode  *p, *t;    //p用来记住当前创建的节点，char用来记住栈顶的元素
        int k;    //k是处理左、右子树的标记
        char ch;
        cout<<"输入树的广义表序列：\n";
        cin >> ch;

        while (ch != RefValue)
        {
            switch (ch)
            {
            case '(':    //对(做处理
                s.push(p);
                k = 1;
                break;

            case ')':    //对)做处理
                s.pop();
                break;

            case ',':    //对,做处理
                k = 2;
                break;

            default:
                p = new BinTreeNode (ch);    //构造一个结点
                if (BT == NULL)    //如果头节点是空
                {

                    BT = p;
                }
                else if (k == 1)    //链入*char的左孩子
                {
                    t = s.top();
                    t->left = p;
                }
                else    //链入*char的右孩子
                {
                    t = s.top();
                    t->right = p;
                }
            }
            cin >> ch;
        }
        cout<<"构造完成！"<<endl;
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
        while(s.top()->left!=NULL){//保持栈顶为最底层左叶子
            s.push(s.top()->left);
        }

        while(!s.empty()){
            if(LastPop==s.top()->right || s.top()->right==NULL){//1、如果栈顶右孩子刚出栈，则栈顶可出栈。2、
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
    cout<<"\n前序遍历：\n";
    BT.PreOrder_NoRecurve(BT.root);
    cout<<"\n中序遍历：\n";
    BT.InOrder_NoRecurve(BT.root);
    cout<<"\n后序遍历：\n";
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
