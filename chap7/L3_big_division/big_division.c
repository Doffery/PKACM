#include<stdio.h>
#include<string.h>
#define MAX_LEN 100

char f_line[MAX_LEN + 1];
char s_line[MAX_LEN + 1];

int f_num[MAX_LEN];
int s_num[MAX_LEN];
int result_[MAX_LEN];

int s_num_leng, f_num_leng;

int Minus(int minus_position) {
	if(f_num[minus_position] < s_num[0])
		return -1;
	int i, j;
	for(i = minus_position + s_num_leng - 1, j = s_num_leng - 1; j >= 0; --i, --j) {
		f_num[i] -= s_num[j];
		if(f_num[i] < 0) {
			f_num[i] += 10;
			f_num[i-1] -= 1;
		}
	}
	if(i != 0 && f_num[i-1] < 0) {
		for(i = minus_position + s_num_leng - 1, j = s_num_leng - 1; j >= 0; --i, --j) {
			f_num[i] += s_num[j];
			if(f_num[i] > 10) {
				f_num[i] -= 10;
				f_num[i-1] += 1;
			}
		}
		return -1;
	}
	return 1;
}

int DivideResult(int divide_position) {
	int r = 0;
	int e = Minus(divide_position);
	while(e > 0) {
		r += 1;
		e = Minus(divide_position);
	}
	return r;
}

void Plus2Result(int i, int carry) {
	result_[carry] += i;
	int j;
	for(j = carry; j <= MAX_LEN; ++j) {
		if(result_[j] >= 10) {
			result_[j] -= 10;
			result_[j+1] += 1;
		} else break;
	}

}

int main() {
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
				
	int n;
	scanf("%d", &n);
	memset(result_, 0, sizeof(result_));

	while(--n >= 0) {
		scanf("%s%s", f_line, s_line);
		int f_len = strlen(f_line), s_len = strlen(s_line);
		s_num_leng = s_len;
		f_num_leng = f_len;
		if(f_len < s_len) {
			printf("0\n");
			continue;
		}
		int i;
		for(i = 0; i < f_len; ++i) {
			f_num[i] = f_line[i] - '0';
		}
		for(i = 0; i < s_len; ++i) {
			s_num[i] = s_line[i] - '0';
		}

		int dp = 0;// divide position
		while (dp < f_len - s_len + 1) {
			result_[dp] = DivideResult(dp);
			++dp;
		}
		for(i = 0; i < dp && result_[i] == 0; ++i);
		for(; i < dp; ++i)
			printf("%d", result_[i]);
		printf("\n");


	}

}
