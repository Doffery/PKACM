#include <stdio.h>
#include <string.h>
#include <algorithm>
#define MAX (10000 + 10)
int nN, nK;
int nWoods[MAX];

int cmp(const void * a, const void * b) {
	return * ((int *)a) - * ((int *)b);
}

bool IsAnsOk(int nAns)
{
    if (nAns == 0)
    {
        return true;
    }
    else
    {
        int nTotal = 0;
        for (int i = nN - 1; i >= 0; --i)
        {
            nTotal += nWoods[i] / nAns;
            if (nTotal >= nK)
            {
                return true;
            }
        }
        return false;
    }
}
int SearchAns(int nMax)
{
    int nBeg = 0, nEnd = nMax;
    while (nBeg <= nEnd)
    {
        int nMid = (nBeg + nEnd) / 2;
        if (IsAnsOk(nMid))
        {
            nBeg = nMid + 1;
        }
        else
        {
            nEnd = nMid - 1;
        }
    }
    return nBeg - 1;
}
int main()
{
    scanf("%d%d", &nN, &nK);
	int nSum = 0;
	for (int i = 0; i < nN; ++i)
	{
	    scanf("%d", &nWoods[i]);
	    nSum += nWoods[i];
	}
	qsort(nWoods, nN, sizeof(int), cmp);
	int nMax = nSum / nK;
	printf("%d\n", SearchAns(nMax));
    return 0;
}
