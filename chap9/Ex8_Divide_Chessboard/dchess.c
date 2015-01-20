#include<stdio.h>
#include<math.h>

int chess[9][9];

int pieces[50];

float min_average_variance = 1000000;
int n;
int point_x, point_y;

float AverageVariance() {
	int i;
	int powSum = 0;
	int sum = 0;
	for(i = 1; i <= n; ++i) {
		powSum += pieces[i] * pieces[i];
		sum += pieces[i];
	}
	return sqrt(n*powSum - sum*sum)/n;
}

int CaculateSum(int px, int py, int x, int y) {
	int i, j, sum = 0;
	for(i = 0; i < x; ++i)
		for(j = 0; j < y; ++j)
			sum += chess[px + i][py + j];
	return sum;
}

void Divide(int x, int y, int num) {

	if(x == 1 && y == 1 && num != 1)
		return;
	if(num == 1) {
		pieces[num] = CaculateSum(point_x, point_y, x, y);
		float a = AverageVariance();
		if(a < min_average_variance)
			min_average_variance = a;
		return;
	}

	int i;
	for(i = 1; i < x; ++i) {
		//remain the first half
		pieces[num] = CaculateSum(point_x + i, point_y, x - i, y);
		Divide(i, y, num - 1);

		//remain the second half
		pieces[num] = CaculateSum(point_x, point_y, i, y);
		point_x += i;
		Divide(x - i, y, num - 1);
		point_x -= i;
	}
	for(i = 1; i < y; ++i) {
		//remain the first half
		pieces[num] = CaculateSum(point_x, point_y + i, x, y - i);
		Divide(x, i, num - 1);

		//remain the second half
		pieces[num] = CaculateSum(point_x, point_y, x, i);
		point_y += i;
		Divide(x, y - i, num - 1);
		point_y -= i;

	}
}

int main() {
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	point_x = 1; point_y = 1;
	scanf("%d", &n);
	int i, j;
	for(i = 1; i < 9; ++i)
		for(j = 1; j < 9; ++j)
			scanf("%d", &chess[i][j]);
	Divide(8, 8, n);
	printf("%0.3f\n", min_average_variance);
}
