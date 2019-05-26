#include <iostream>
#include <cmath>
using namespace std;

int Bound(int* Weights,int* Values,int n,int W,int num,int current_w,int current_v){
	int i=num+1;
	for(;i<n;i++){
		if(current_w+Weights[i]<W){
			current_v+=Values[i];
			current_w+=Weights[i];
		}else{
			current_v+=(Values[i]/Weights[i])*(W-current_w);
			current_w=W;
			return current_v;
		}
	}
	return current_v;
}

int* fun(int *Weights,int* Values,int W,int n){
	int *X=new int[n];
	int *Y=new int[n];
	int Weight=0;
	int Profit=0;
	
	int current_w=0,current_v=0;
	
	int i=0;
	while(true){
		while(i<n&&current_w+Weights[i]<=W){
			X[i]=1;
			current_v+=Values[i];
			current_w+=Weights[i];
			i++;
		}
		
		//�������i==n������˵�������������ײ���
		if(i>=n){
			Weight=current_w;
			Profit=current_v;
			i=n;
			for(int i=0;i<n;i++){
				Y[i]=X[i];
			}
		} else{
			//��i����Ʒ�Ų���
			X[i]=0; 
		}
		
		//������ܻ�ø���ļ�ֵ��������ǰ�� �����л��� 
		while(Bound(Weights,Values,n,W,i,current_w,current_v)<=Profit){
			while(i!=0&&X[i]!=1){
				i--;
			}
			if(i==0){
				cout<<"����ֵ��"<<Profit<<endl;
				return Y;
			}
			X[i]=0;
			current_v-=Values[i];
			current_w-=Weights[i];
		} 
		i++;
	}
}

int main(){
	int n,W;
	cout<<"������Ʒ������"; 
	cin>>n;
	cout<<"�����뱳��������"; 
	cin>>W; 
	int Weight[n];
	int Value[n];
	int *path; 
	cout<<"����������n����Ʒ�������ͼ�ֵ(V/W�Ӵ�С)��"<<endl;
	for(int i=0;i<n;i++){
		cin>>Weight[i]>>Value[i]; 
	} 
	
	path=fun(Weight,Value,W,n);
	for(int i=0;i<n;i++)
	cout<<path[i]<<" ";
	
	return 0;
}

