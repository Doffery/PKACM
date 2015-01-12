#include<stdio.h>
#include<string.h>

int main() {
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);

	char enCode[201];
	int enTimes;
	char enData[201], enDataP[201];

	while (scanf("%s", enCode) != EOF) {
		scanf("%d", &enTimes);
		scanf("%s", enData);

		int lenC = strlen(enCode);
		int lenD = strlen(enData);

		for (;lenC < lenD; ++lenC) {
			enData[lenC] = ' ';
		}

		while (enTimes -- != 0) {
			int i;
			for(i = 0; i < lenC; ++i) {
				enDataP[i] = enData[enCode[i] - '1'];
			}
			strcpy(enData, enDataP);
		}
		enDataP[lenC] = '\0';
		printf("%s\n", enDataP);
	}
}
