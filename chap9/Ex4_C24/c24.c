#include<stdio.h>
#include<math.h>
double a[4];
int result(int n) 
{
	int i,j;
	double p,q; 
	if(n==1)
	{
		if(fabs(a[0]-24)<1e-2)
			return 1;
		else
			return 0;
	}
	for(i=0;i<n-1;i++)
		for(j=i+1;j<n;j++)
		{
			p=a[i];q=a[j];
			a[j]=a[n-1];
			a[i]=p+q;
			if(result(n-1)==1) return 1;
			a[i]=p-q;
			if(result(n-1)==1) return 1;
			a[i]=q-p;
			if(result(n-1)==1) return 1;
			a[i]=p*q;
			if(result(n-1)==1) return 1;
			if(q!=0){
				a[i]=p/q;
				if(result(n-1)==1) return 1;
			}
			if(p!=0){
				a[i]=q/p;
				if(result(n-1)==1) return 1;
			}
			a[i]=p;a[j]=q;
		}
	return 0;
}
int main()
{
	int i;
	while(1)
	{
		for(i=0;i<4;i++)
		{
			scanf("%lf",&a[i]);
		}
		if(a[0]==0&&a[1]==0&&a[2]==0&&a[3]==0)
			break;
		if(result(4))
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}
