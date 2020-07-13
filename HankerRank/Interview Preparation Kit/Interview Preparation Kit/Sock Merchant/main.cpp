// The easiest solution with O(N)
#include <iostream>
using namespace std;

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

    cout << pairs;

}

int main()
{
    int n;
    cin >> n;
    int ar[n];
    for (int i = 0; i < n; i++)
    {
        cin >> ar[i];
    }

    sockPairs(n,ar);

}