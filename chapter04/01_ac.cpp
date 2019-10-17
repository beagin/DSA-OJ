#include <iostream>
#include <string>
using namespace std;

string s[55];
string T;

int main() 
{
	int n;
	cin>>n;
	for(int i=0;i<n;++i) 
	{
		cin >> s[i];
	}
	cin>>T;
	int len=T.length();
	
	for(int i=0;i<n;++i) 
	{
		int temp=0;
		int flag=0;
		for(int j=0;j<len;++j) 
		{
			if(T[j]!='[')
			{
				if( T[j]==s[i][temp] || T[j]-s[i][temp]=='A'-'a'|| T[j]-s[i][temp]=='a'-'A')
				{
					temp++;
					continue;
				}
				else
				{
					flag=1;
					break;
				} 
			}
			else 
			{
				j++;
				while(!(T[j]==s[i][temp] || T[j]-s[i][temp]=='A'-'a'|| T[j]-s[i][temp]=='a'-'A') && T[j]!=']')  
				{
					j++;
				}
				if(T[j]==']')
				{
					flag=1;
					break;
				}
				else
				{
					temp++;
					while(T[j]!=']')
					{
						j++;
					}
				}
			} 			
		}
		if(flag==0)
		{
			cout<<i+1<<" "<<s[i]<<endl; 
		}
	}
	return 0;
}