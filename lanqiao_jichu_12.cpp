#include <iostream>
#include <string>
#include <cstdio>
using namespace std;
int main()
{
	int n;
	cin>>n;
	while(n--)
	{
		long long sum=0,add;
		string str_1,str_2;
		cin>>str_1;
		for(int i=0;i<str_1.size();i++)
		{
			switch(str_1[i])
			{
				case '1':
				case '2':
				case '3':
				case '4':
				case '5':
				case '6':
				case '7':
				case '8':
				case '9':add=str_1[i]-'0';break;
				case 'A':
				case 'B':
				case 'C':
				case 'D':
				case 'E':
				case 'F':add=str_1[i]-'A'+10;break;
				default:break;
			}
			for(int j=0;j<str_1.size()-i-1;j++)
			add=add*16;
			sum=sum+add;
		}
		printf("%o",sum);
		
	}
	
	return 0;
 } 
