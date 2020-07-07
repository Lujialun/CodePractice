#include<iostream>
#include<vector>
using namespace std;
/*
快速排序
平均时间复杂度：O(NlogN)
最佳时间复杂度：O(NlogN)
最差时间复杂度：O(N^2)
空间复杂度：根据实现方式的不同而不同
稳定性：不稳定
*/
void QuickSort(vector<int> &a, int left,int right)//递归法（非递归后续再补）
{
    if(left>=right) return;//递归结束条件
    int i=left;//更换循环变量，left，right后面需用到
    int j=right;
    int base=a[left],temp;  //挑选最左边为基准值
    while(i<j){
        while(j>i&&a[j]>=base) j--; //从右遍历
        while(i<j&&a[i]<=base) i++; //从左遍历
        if(i<j){//交换
            temp=a[i];
            a[i]=a[j];
            a[j]=temp;
        }
    }
    a[left]=a[i];//交换base值
    a[i]=base;
    QuickSort(a,left,i);
    QuickSort(a,i+1,right);

}
/*
冒泡排序
平均时间复杂度：O(N^2)
最佳时间复杂度：O(N)
最差时间复杂度：O(N^2)
空间复杂度：O(1)
排序方式：In-place
稳定性：稳定
*/
void BubbleSort(vector<int> &a)
{
    int temp,flag=0;;
    for(int i=0;i<a.size(); i++){//需要对序列遍历的次数
        flag=1;//优化的冒泡排序：如果已经有序不再进行遍历
        for(int j=0; j<a.size()-i-1;j++){
            if(a[j]>a[j+1]){
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
                flag=0;
            }
        }
        if(flag) break;//没有交换则break
    }
}

/*
插入排序
平均时间复杂度：O(N^2)
最差时间复杂度：O(N^2)
空间复杂度：O(1)
排序方式：In-place
稳定性：稳定
*/
void InsertionSort(vector<int> &a)
{
    int temp;
    for(int i=1; i<a.size(); i++){//从a[1]开始遍历，将a[0]是为有序序列
        if(a[i]<a[i-1]){//是否小于有序序列最大值
            temp=a[i];//记录要插入的值，便于前值后移
            for(int j=i; j>0; j--){
                if(temp<a[j-1]){//比较前一个值
                    a[j]=a[j-1];
                }else{
                    a[j]=temp;
                    break;
                }

            }
        }
    }
}

/*
希尔排序（优化插入排序）
平均时间复杂度：O(Nlog2N)
最佳时间复杂度：
最差时间复杂度：O(N^2)
空间复杂度：O(1)
稳定性：不稳定
*/
void ShellSort(vector<int> &a)//o(n^1.3)
{
    int n=a.size();
    for(int gap=n/2; gap>0; gap/=2){ //增量值/2
        for(int i=gap; i<n; i++){//此处开始类似于插入排序，插入排序gap=1
            for(int j=i-gap; j>=0&&a[j]>a[j+gap]; j-=gap){
                swap(a[j],a[j+gap]);
            }
        }
    }

}


int BinarySearch(vector<int> &a, int k)
{
    int m;
    int left=0,right=a.size()-1;
    while(left<=right){
        m=(left+right)/2;
        if(a[m]<k){
            left=m+1;
        }else if(a[m]>k){
            right=m-1;
        }else{
            return m;
        }
    }
    return -1;
}

void BinarySort(vector<int> &a)
{
    int left,right,middle,temp;
    for(int i=1; i<a.size(); i++){
        left=0,right=i-1;
        if(a[i]<a[i-1]){
            temp=a[i];
            while(left<=right){
                middle=(left+right)/2;

                if(a[middle]>temp){
                    right=middle-1;
                }else{

                    left=middle+1;
                }
            }

            for(int j=i; j>left; j--)
                a[j]=a[j-1];

            if(left!=i) a[left]=temp;
        }
    }
}

void SelectSort(vector<int> &a)
{
    int min_;
    for(int i=0; i<a.size();i++){
        min_=i;
        for(int j=i+1;j<a.size();j++){
            if(a[j]<a[min_]) min_=j;
        }
        if(min_!=i) swap(a[i],a[min_]);

    }
}
/*¹é²¢*/
void Merge(vector<int> &a, int start, int mid, int End)
{
    vector<int> tmp;

    int i=start,j=mid+1;
    while(i<=mid&&j<=End){
        if(a[i]<=a[j]){
            tmp.push_back(a[i++]);
        }else{
            tmp.push_back(a[j++]);
        }
    }

    while(i<=mid) tmp.push_back(a[i++]);
    while(j<=End) tmp.push_back(a[j++]);

    for(int k=0; k<tmp.size(); k++)
        a[start+k]=tmp[k];
}

void MergeSort(vector<int> &a, int start, int End)
{
    if(a.size()<0||start>=End) return;
    int mid=(start+End)/2;

    MergeSort(a,start,mid);
    MergeSort(a,mid+1,End);

    Merge(a,start,mid,End);

}
//
//void MergeSort_NoRecursive(vector<int> &a)
//{
//    if(a.size()<=0) return;
//     int i, left_min, left_max, right_min, right_max,next;
//    int length=a.size();
//    vector<int> tmp;
//    for (i = 1; i < length; i *= 2) // iÎª²½³¤£¬1,2,4,8¡­¡­
//    {
//        for (left_min = 0; left_min < length - i; left_min = right_max)
//        {
//            right_min = left_max = left_min + i;
//            right_max = left_max + i;
//
//            if (right_max > length)
//                right_max = length;
//
//            next = 0;
//            while (left_min < left_max && right_min < right_max)
//                tmp.push_back(a[left_min] > a[right_min] ? a[right_min++] : a[left_min++]);
//
//            while (left_min < left_max)
//                a[--right_min] = a[--left_max];
//
//            while (next > 0)
//                a[--right_min] = tmp[--next];
//        }
//    }
//
//}

//https://www.cnblogs.com/chengxiao/p/6129630.html
//https://zhuanlan.zhihu.com/p/124885051
void AdjustMaxHeap(vector<int> &a, int father, int len)
{
    int temp=a[father];
    for(int i=2*father+1; i<len; i=i*2+1){
        if(i+1<len&&a[i]<a[i+1]) i++;
        if(a[i]>temp){
            a[father]=a[i];
            father=i;
        }else{
            break;
        }
    }
    a[father]=temp;

}
//下标为 i 的结点的父结点下标为(i-1)/2；其左右子结点分别为 (2i + 1)、(2i + 2)
void HeapSort(vector<int> &a)
{
    for(int i=a.size()/2-1;i>=0;i--){
        AdjustMaxHeap(a,i,a.size());
    }

    for(int i=a.size()-1; i>0; i--){
        swap(a[0],a[i]);
        AdjustMaxHeap(a,0,i);
    }
}

//计数排序https://zhuanlan.zhihu.com/p/125126086
//桶排序 https://zhuanlan.zhihu.com/p/125737294
//基数排序 https://zhuanlan.zhihu.com/p/126116878 https://www.runoob.com/w3cnote/radix-sort.html
int main()
{
    vector<int> a={2,4,6,8,10,12,5};
    BinarySort(a);
    //cout<<BinarySearch(a,11)<<endl;
    for(int i=0; i<a.size(); i++)
        cout<<a[i]<<" ";
}
