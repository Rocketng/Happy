#include <iostream>
#include <algorithm>
#include <iomanip>
#include <cmath>
using namespace std;
int x[4],l[4],t[4];
int ans=0;
int w[4],p[4],a[4]={3,3,3,3};

bool near(int s){
	for(int i=1;i<=3;i++){
		if(s==x[i]-1||s==x[i]+1)
		return true;
	}
	return false;
}

void dfs(int d){
	int e=0;
	for(int i=1;i<=3;i++){
		ans=max(ans,x[i]);
	}
	for(int i=1;i<=3;i++){
		if(w[i])continue;
		//δ�����ƶ����Ҳ����� 
		if((a[i]&1)&&!(a[i]&4)){
			for(int j=1;j<=l[i];j++){
				x[i]+=j;                       //ǰ�� 
				a[i]^=1;
				if(near(x[i])||j==l[i]){
					dfs(d+1);
				}
				x[i]-=2*j;                     //���� 
				if(near(x[i])||j==l[i]){
					dfs(d+1);
				} 
				x[i]+=j;                      //��ԭ 
				a[i]^=1;                       
			}
		}
		//δ���о���
		if(a[i]&2){
			for(int j=1;j<=3;j++){
				if(i!=j&&!w[j]&&t[i]>0){
					if(x[i]==x[j]+1||x[j]==x[i]+1){
						w[j]=1;
						a[i]^=2;            //���� 
						a[i]^=4;            //���׳�
						p[i]=j;
						e=x[j];
						x[j]=-j;
						dfs(d+1);
						x[j]=e;
						a[i]^=2;
						a[i]^=4;
						w[j]=0;	
					}	
				}
			}
		} 
		//���׳�a[i]==4||a[i]==5
		if(a[i]&4){
			for(int j=1;j<=t[i];j++){
				w[p[i]]=0;
				a[i]^=4;
				e=x[p[i]];
				x[p[i]]=x[i]+j;
				if(near(x[p[i]])||j==t[i]){
					dfs(d+1);
				}
				x[p[i]]-=2*j;
				if(near(x[p[i]])||j==t[i]){
					dfs(d+1);
				}
				x[p[i]]=e;
				a[i]^=4;
				w[p[i]]=1;
			}
		}
	}
	return ;
}


int main(){
    for(int i=1;i<=3;i++)
	cin>>x[i]>>l[i]>>t[i];
	dfs(1);
	cout<<ans<<endl;	
	return 0;
 } 
