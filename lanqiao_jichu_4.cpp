#include <iostream>
using namespace std;
int main()
{
	int n;
	cin>>n;
	int code[n]={0};
	
	for(int i=0;i<n;i++)
	cin>>code[i];
	
	int max,min,sum=0;
	min=max=code[0];
	for(int i=1;i<n;i++)
	{
		if(code[i]<min)
		min=code[i];
	}
	for(int i=1;i<n;i++)
	{
		if(code[i]>max)
		max=code[i];
	}
	
	for(int i=0;i<n;i++)
	sum+=code[i];
	
	cout<<max<<endl<<min<<endl<<sum<<endl;
	
	return 0;
	
}
