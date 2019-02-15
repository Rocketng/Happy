#include <iostream>
using namespace std;
int main()
{
	int N;
	cin>>N;
ll:	if(N<1||N>54)
	goto ll;
	
   for(int i=1;i<10;i++)
   {
   	 for(int j=0;j<10;j++)
   	 {
   	 	if(N-2*i-2*j>=0&&N-2*i-2*j<10)
   	 	cout<<i*10001+j*1010+(N-2*i-2*j)*100<<endl;
		}
   }	
	
    for(int i=1;i<10;i++)
    {
    	for(int j=0;j<10;j++)
    	{
    		for(int k=0;k<10;k++)
    		if(N==2*i+2*j+2*k)
    		cout<<i*100001+j*10010+k*1100<<endl;
		}
	}
	return 0;
}
