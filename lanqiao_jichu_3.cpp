#include <iostream>
using namespace std;
int main()
{
	int m,n;
ll:	cin>>m>>n;
    if((m<1||m>26)||(n<1||n>26))
    goto ll;
    char code[m][n]={0};
    code[0][0]='A';
	for(int i=1;i<n;i++)
	{
		code[0][i]=code[0][i-1]+1;
	}
	
	for(int i=1;i<m;i++)
	{
		code[i][0]=code[i-1][0]+1;
		for(int j=1;j<n;j++)
		{
			code[i][j]=code[i-1][j-1];
		}
	} 
	 
	 for(int j=0;j<m;j++)
	 {
	 		for(int k=0;k<n;k++)
	 		cout<<code[j][k];
			cout<<endl; 
	 }
	 
	 return 0;
}
