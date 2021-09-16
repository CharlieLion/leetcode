//找到最大的质数
#include<iostream>
#include<math.h>
using namespace std;

int main()
{
	int n, tag;
	cin>>n;
	for(int i =n-1; i>=0;i--)
	{
		tag = 0;
		for(int j=2, q = sqrt(n) ; j<= q;j++)
		{
			if(n%j==0)
			{
				tag==1;
                break;
			}
		}
		if(tag==0)  
		{
			cout<<i<<endl;
			break;
		}
	}
}