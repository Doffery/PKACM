#include<stdio.h>

int lumbers[10000 + 10];

int cmp(const void * a, const void * b) {
	return * ((int *)a) - * ((int *)b);
}
/*
int MbSearch(int j, int *l, int s, int n) {
	if(s == n)
		return s;
	if(n == s + 1) {
		if(l[s] < j)
			return n;
		return s;
	}
	int mid = (s + n) / 2;
	if(l[mid] == j) {
		return mid;
	}
	else if(l[mid] < j) 
		return MbSearch(j, l, mid, n);
	else return MbSearch(j, l, s, mid);
}*/

int main() {
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);

	int n, k;
	scanf("%d %d", &n, &k);

	int i, sum = 0, t;
	for(i = 0; i < n; ++i) {
		scanf("%d", &t);
		sum += t;
		lumbers[i] = t;
	}

	qsort(lumbers, n, sizeof(int), cmp);

	int maxLen = sum / k;
	int quan, j, index;

	int nBeg = 0, nEnd = maxLen, nMid;
	while(nBeg <= nEnd) {
		nMid = (nBeg + nEnd) / 2;
		if(nMid == 0) { 
			nBeg = nMid + 1;
			continue;
		}
		quan = 0;
		for(i = n - 1; i >= 0; --i) {
			quan += lumbers[i] / nMid;
		}
		
		/*j = nMid;
		index = 0;
		while (index != n - 1 || lumbers[index] > j) {
			index = MbSearch(j, lumbers, index, n - 1); 
			quan += n - index;
			j += nMid;
		}*/
		if(quan >= k)
			nBeg = nMid + 1;
		else nEnd = nMid - 1;
	}
	printf("%d\n", nBeg - 1);
}
