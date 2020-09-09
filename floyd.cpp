/*
 * @Descripttion: https://blog.csdn.net/m0_38106954/article/details/77465618 https://blog.csdn.net/nightwizard2030/article/details/72639203
 * @version: 
 * @Author: Lucas
 * @Date: 2020-09-07 11:50:45
 * @LastEditors: Lucas
 * @LastEditTime: 2020-09-07 11:50:54
 */
#include<iostream>  
#define MAX_VERTEX 100  
#define INFINITE 65535  
using namespace std;
//array   
 
char vertex_infos[MAX_VERTEX];  
int matrix[MAX_VERTEX][MAX_VERTEX];
int main(){
 
    for(int i=0;i<MAX_VERTEX;i++){   
        vertex_infos[i]=0;  
        for(int j=0;j<MAX_VERTEX;j++){   
            matrix[i][j]=INFINITE;   
            matrix[i][j]=INFINITE;   
        }
    }  
       
    cout<<"input vertex and side nums:";   
    int num_vertex;   
    int num_side;   
    cin>>num_vertex>>num_side;   
       
    cout<<"input vertex char data:";   
    for(int i=0;i<num_vertex;i++){   
        cin>>vertex_infos[i];   
    }   
       
    for(int i=0;i<num_side;i++){   
        int v1;   
        int v2;   
        int weight;  
        cout<<"input two vertex:";   
        cin>>v1>>v2;   
        cout<<"input weight:";   
        cin>>weight;   
        matrix[v1][v2]=weight;  
        matrix[v2][v1]=weight;  
    }
    
    for(int k=1;k<num_vertex;k++){
    	for(int i=0;i<num_vertex;i++){
	    	for(int j=0;j<num_vertex;j++){
	    		if(i!=j&&matrix[i][k]+matrix[k][j]<matrix[i][j]){
		    		matrix[i][j]=matrix[i][k]+matrix[k][j];
		    	}
	    	}
	    }
    }
    
    
    for(int i=0;i<num_vertex;i++){   
        for(int j=0;j<num_vertex;j++){
			cout<<matrix[i][j]<<' ';
        }
        cout<<endl;
    }  
	return 0;
}