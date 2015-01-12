#include<stdio.h>
#include<string.h>

int main() {
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);

	int k1, k2, k3;
	char data[81];

	while (scanf("%d %d %d", &k1, &k2, &k3) != EOF) {
		scanf("%s", data);
		int sp1 = -1, sp2 = -1, sp3 = -1;//start point
		char pre1, pre2, pre3;
		int i = 0, len = strlen(data);
		while(i < len) {
			if(sp1 == -1 && data[i] >= 'a' && data[i] < 'j')
				sp1 = i;

			if(sp2 == -1 && data[i] >= 'j' && data[i] < 's')
				sp2 = i;

			if(sp3 == -1 &&( data[i] >= 's' && data[i] <= 'z'
					   	|| data[i] == '_'))
				sp3 = i;
			++i;

		}

		pre1 = data[sp1];
		pre2 = data[sp2];
		pre3 = data[sp3];
		while(k1 > 0 || k2 > 0 || k3 > 0) {
			for(i = 0; i < len; ++i) {
				if(k1 > 0 && data[i] >= 'a' && data[i] < 'j') {
					char t = data[i];
					data[i] = pre1;
					pre1 = t;
					continue;
				}

				if(k2 > 0 && data[i] >= 'j' && data[i] < 's') {
					char t = data[i];
					data[i] = pre2;
					pre2 = t;
					continue;
				}

				if(k3 > 0 && data[i] >= 's' && data[i] <= 'z'
					   	|| data[i] == '_') {
					char t = data[i];
					data[i] = pre3;
					pre3 = t;
					continue;
				}
			}
			data[sp1] = pre1;
			data[sp2] = pre2;
			data[sp3] = pre3;
			--k1; --k2; --k3;
		}
		printf("%s\n", data);
	}
}
