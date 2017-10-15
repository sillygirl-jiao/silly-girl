#include<iostream>
#define M 30005
using namespace std;

int fx[M],r[M],mx[M];
void init()
{
	for(int i=1;i<=M;i++)
	{
		fx[i]=i;
		r[i]=0;
		mx[i]=1;
	}
}
int find(int n)
{
	int fa=fx[n];
	if(fa!=n)
	{
		fa=find(fx[n]);
		r[n]+=r[fx[n]];
	}
	return fx[n]=fa;
}

void unit(int n,int m)
{
	int fn=find(n);
	int fm=find(m);
	fx[m]=n;
	r[fm]+=mx[fn];
	mx[fn]+=mx[fm];
}

int main()
{
	int x;
	char w;
	while(cin>>x)
	{
		int a,b,c;
	    init();
	    while(x--)
     	{
		    cin>>w;
		    if(w=='M')
		    {
			    cin>>a>>b;
			    unit(a,b);
		    }
	    	else
		    {
			    cin>>c;
		        cout<<mx[find(c)]-r[c]-1<<endl;	
		    }
	    }
	}
	return 0;
}











