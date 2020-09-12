/*
 * @Descripttion: 
 * @version: 
 * @Author: Lucas
 * @Date: 2020-09-10 14:54:40
 * @LastEditors: Lucas
 * @LastEditTime: 2020-09-10 14:56:05
 */

#include<iostream>
#include<memory>

using namespace std;


template <typename T>
class sm_ptr{

public:

    explicit sm_ptr(T* _pdata){
       pdata = _pdata;
       pcount = new int(1);
       sp_enable_shared_from_this(this,pdata,pcount);	
    }
    void sp_enable_shared_from_this(...){}
    void sp_enable_shared_from_this( sm_ptr<T>* p_smptr,enable_shared_from_this<T> *pdata,int *pcount){}
    sm_ptr(const sm_ptr& _ptr){
       pdata = _ptr.pdata;
       pcount = _ptr.pcount;
       *pcount = *pcount +1;
    }
    ~sm_ptr(){
       *pcount = *pcount -1;
       if(*pcount == 0){
           delete pcount;
           delete pdata;
        }
    }
    sm_ptr& operator= (const sm_ptr<T>& _ptr){
        if(this == &_ptr)
           return *this;
        if(pdata != _ptr.pdata){
           *pcount = *pcount -1;
           if(*pcount == 0){
               delete pcount;
               delete pdata;
            }
        }
        pdata = _ptr.pdata;
        pcount =_ptr.pcount;
        *pcount = *pcount +1;
    }
T*  get(){
     return pdata;
}
int use_count(){
    return *pcount;
}
 T* operator->(){
   return pdata;
}
T& operator*(){
   return *pdata;
}




private:


T *pdata;
int *pcount;

};

struct Node{

 Node(){
   cout<<"construct"<<endl;
 }
 Node(const Node& _data){
   cout<<"copy construct"<<endl;
 }
 Node& operator =(const Node& _data){
   cout<<"assgin contruct"<<endl;
 }
 ~Node(){
  cout<<"destruct"<<endl;
 }


};

int main(){

  sm_ptr<Node> pdata1(new Node);
  sm_ptr<Node> pdata2 = pdata1;
  pdata1 = pdata1;

  
  cout<<pdata1.use_count()<<endl;

 
  cout<<"hello wordl"<<endl;

}
