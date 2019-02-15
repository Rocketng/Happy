#include <iostream>
using namespace std;
int main()
{
	int N;
	cin>>N;
ll:	if(N<1||N>34)
	goto ll;
	int code[N][N]={0};
	for(int i=0;i<N;i++)
	{
		code[i][0]=1;
		for(int j=1;j<i;j++)
			code[i][j]=code[i-1][j-1]+code[i-1][j];
		code[i][i]=1;	
	}
	
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<i+1;j++)
		   cout<<code[i][j]<<" ";
		cout<<endl;
	}
	
	return 0;
 } 
