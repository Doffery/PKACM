#include <stdio.h>
#include <math.h>

int dp(int i,int n)
{
    int sum=1;
    for(;i<=sqrt(n);i++)
    {
        if(n%i==0)
        {
            sum+=dp(i,n/i);
        }
	 }
	 return sum;
}
int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);

	int n,t,ans;
	scanf("%d", &t);
	while(t--)
	{
		scanf("%d", &n);
		ans=dp(2,n);
		printf("%d\n", ans);
	}
	return 0;
}
