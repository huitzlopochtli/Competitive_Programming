// The easiest solution with O(N)
#include <stdio.h>

void sockPairs(int n, int *ar)
{
    int c[101] = {0};
    for(int i=0; i<n;i++)
    {
        c[ar[i]]++;
    }

    int pairs = 0;
    for(int i=0; i<101;i++){
        pairs += c[i]/2;
    }

    printf("%d",pairs);

}

int main()
{
    int n;
    scanf("%d", &n);
    int ar[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &ar[i]);
    }

    sockPairs(n,ar);

}