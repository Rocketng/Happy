#include <iostream>
using namespace std;
int main()
{
	for(int i=0;i<32;i++)
	{
		int n=i;
		int code[5]={0};
		for(int j=0;j<5;j++)
		{
			code[4-j]=n%2;
			n=n/2;
		}	
		for(int k=0;k<5;k++)
		cout<<code[k];
		cout<<endl;
	}
	
	return 0;
}
