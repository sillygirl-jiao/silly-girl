#include<iostream>
#include<string>
using namespace std;
string stra,strb;
char ans[30];
int t;
void solve(string s1,string s2)
{
	if(s1.length()==0)
	    return;//这也是可以的 
	else if(s1.length()==1)
	{
		ans[t++]=s1[0];
		return;
    }
    int tt=s2.find(s1[0]);
    solve(s1.substr(1,tt),s2.substr(0,tt));//tt是长度，前面的是起始位置 
    solve(s1.substr(tt+1,s1.length()-tt-1),s2.substr(tt+1,s2.length()-tt-1));
    ans[t++]=s1[0];
    
}

int main()
{
	while(cin>>stra>>strb)
	{
		int len=stra.length();//.length只能用于string 
		t=0;
		solve(stra,strb);
		ans[len]='\0';
		cout<<ans<<endl;
	}
	return 0;
}
