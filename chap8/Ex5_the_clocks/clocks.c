#include<stdio.h>
int f[9]={0};
int a[9]={9};
int flag;
int m[9][9] ={ {1,1,0,1,1,0,0,0,0},
{1,1,1,0,0,0,0,0,0},
{0,1,1,0,1,1,0,0,0},
{1,0,0,1,0,0,1,0,0},
{0,1,0,1,1,1,0,1,0},
{0,0,1,0,0,1,0,0,1},
{0,0,0,1,1,0,1,1,0},
{0,0,0,0,0,0,1,1,1},
{0,0,0,0,1,1,0,1,1}};

void out()
{
	int i, j;
	for (i = 0; i<9; i++)
	for (j = 0; j < f[i];j++)
		printf("%d ",i+1);
	printf("\n");
}
int tmp[9] = {0};
int judge()
{
	int i,j;

	for (i = 0; i < 9; i++) {
		tmp[i] = a[i];
		//cout<<tmp[i]<<' ';
		for (j = 0; j < 9; j++){
			tmp[i]+=f[j]*m[j][i];
		}
		if (tmp[i] % 4) break;
	}
	//cout<<i<<endl;
	if (i == 9)	{
		flag = 0;
		return 1;//!!
	}
	return 0;//!!
}

void dfs(int n){
	if (n == 9)	{
		if ( judge()){
			flag = 0;
			out();
			return;
		}
		return;
	}
	if (flag) {
		int i;
		for (i = 0; i<4; i++) {
			f[n] = i;
			dfs(n+1);
			if (flag == 0) return;
				f[n] = 0;
		}
	}
}

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);

	int i;
	for (i = 0; i<9; i++) scanf("%d",&a[i]);
	flag = 1;
	dfs(0);
	return 0;
}
