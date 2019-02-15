#include <iostream>
using namespace std;
int main()
{
	int N;
ll: cin>>N;
    if(N<1990||N>2050)
    goto ll;
    if((N%4==0&&N%100!=0)||N%400==0)
    cout<<"yes"<<endl;
    else
    cout<<"no"<<endl;
    
    return 0;
	
 } 
