#include<iostream>
#include<string.h>
using namespace std;
int main()
{
	freopen("A.txt","r",stdin);
	int t;
	int n,k,max,x;
	//int pos;
	int s[100100];
	cin>>t;
	while(t--)
	{
		cin>>n>>k;
		max=0;
		//pos=0;
		memset(s,0,sizeof(s));
		for(int i=0;i<n;i++)
		{
			cin>>x;
			if(i<=k)
			{
				s[i]=x;
				if(s[i]>max)
				    max=s[i];
				else
				    s[i]=max;
			}
			    
			else if(s[i-k-1]+x>max)
			{
				s[i]=s[i-k-1]+x;
				max=s[i];
				//pos=i;
			}
			else
			    s[i]=max;
		}
		cout<<max<<endl;
	}
	return 0;
}
