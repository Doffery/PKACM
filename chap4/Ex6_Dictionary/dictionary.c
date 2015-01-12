#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct dictItem {
	char fWord[11];
	char eWord[11];
}DictItem;

int cmp(const void *a, const void *b) {
	return strcmp(((DictItem *)a)->fWord, ((DictItem *)b)->fWord);
}

int cmp2(const void *a, const void *b) {
	return strcmp((char *)a, ((DictItem *)b)->fWord);
}

int main() {
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);

	DictItem di;
	DictItem dItems[100000];
	int n = 0;
	while (scanf("%s %s", di.fWord, di.eWord) != EOF) {
		dItems[n++] = di;// Is this OKAY?
	}

	qsort(dItems, n, sizeof(di), cmp);
	
	//char wordD[11];
	FILE *fpi = fopen("doc.txt", "r");
	while (fscanf(fpi, "%s", di.fWord) != EOF) {
		DictItem *d;
		d = (DictItem *) bsearch(&di, dItems, n, sizeof(di), cmp);
		if(d != NULL) printf("%s\n", d->eWord);
		else printf("eh\n");
	}

	fclose(fpi);
}
