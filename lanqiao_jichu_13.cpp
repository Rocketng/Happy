#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
	int n;
	cin>>n;
ll:	if(n<1||n>200)
	goto ll;

	int a[n];
	for(int i=0;i<n;i++)
	cin>>a[i];
	sort(a,a+n);
	for(int i=0;i<n;i++)
	cout<<a[i]<<" ";
	cout<<endl;
	
	return 0;
}
