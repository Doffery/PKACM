#include<stdio.h>
#include<string.h>

char floats[10000][51];
//int dotPlace[10000];

int cmp(const void *a, const void *b) {
	char * ac = (char *)a;
	char * bc = (char *)b;
	int ad, bd;
	char *dot = strchr(ac, '.');
	ad = dot - ac;
	dot = strchr(bc, '.');
	bd = dot - bc;
	return ad==bd ? strcmp(a, b) : (ad - bd);
}

int main() {
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);

	int n;
	scanf("%d", &n);
	int i;
	for (i = 0; i < n; ++i) {
		scanf("%s", floats[i]);
		
	//	char *dot = strchr(floats[i], '.');
	//	dotPlace[i] = dot - floats[i];
	}
	qsort(floats, n, sizeof(floats[0]), cmp);
	for(i = 0; i < n; ++i) {
		printf("%s\n", floats[i]);
	}
}
