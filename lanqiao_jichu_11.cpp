#include <iostream>
#include <cstring>
using namespace std;
int main()
{
	long long sum=0;
	char a[9];
	cin>>a;
	int b[strlen(a)];
	for(int i=0;i<strlen(a);i++)
	{
		switch(a[i])
		{
			case '1':b[i]=1;break;
			case '2':b[i]=2;break;
			case '3':b[i]=3;break;
			case '4':b[i]=4;break;
			case '5':b[i]=5;break;
			case '6':b[i]=6;break;
			case '7':b[i]=7;break;
			case '8':b[i]=8;break;
			case '9':b[i]=9;break;
			case 'A':b[i]=10;break;
			case 'B':b[i]=11;break;
			case 'C':b[i]=12;break;
			case 'D':b[i]=13;break;
			case 'E':b[i]=14;break;
			case 'F':b[i]=15;break;
		}
	}
	
	for(int i=0;i<strlen(a);i++)
	{
		long long add=b[i];
		for(int j=0;j<strlen(a)-i-1;j++)
		{
		   add*=16;
		}
		sum+=add;
	}
	cout<<sum<<endl;
	return 0;
}
