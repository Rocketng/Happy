#include <iostream>
using namespace std;

int main()
{
	int N,M;
	cin>>N;
	int a[N]={0};
	for(int i=0;i<N;i++)
	cin>>a[i];
	cin>>M;
	int j;
	for(j=0;j<N;j++)
	{
		if(M==a[j])
		break;
	}
	if(j==N)
	cout<<"-1"<<endl;
	else
	cout<<j+1<<endl;
	
	return 0;
	
 } 
