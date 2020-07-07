#include<iostream>
#include "assert.h"
using namespace std;

char* Strcpy(char* des, const char* src)
{
    char* tem=des;
    assert((des!=NULL)&&(src!=NULL));
    while((*tem++ = *src++)!='\0');
    return des;
}

void* Memcpy(void *des, const void *src, unsigned int n)//n×Ö½ÚÊý
{
    void *p=des;
    if(des==NULL || src==NULL || n<1) return NULL;
    while(n--){
        *(char*)p++ = *(char*)src++;
    }
    return des;
}
 void* Memmove(void *dest,const void *source, unsigned int n)
 {
    assert((dest!=nullptr)&&(source!=nullptr));
    char* tempd=(char*)dest;
    const char *temps=(char*)source;
    if(source<dest&&(source+n)>dest){
        tempd += n-1;
        temps += n-1;
        while(n--){
            *tempd--=*temps--;
        }
    }else{
        while(n--){
            *tempd++=*temps++;
        }

    }
    return dest;
 }

int main()
{
    char a[]={"12345678"};
    char b[]={"bbb"};
 //   Strcpy(a,b);
    Memmove(a+4,a,5);
    for(int i=0; i<9; i++) cout<<a[i]<<endl;
}
