#include <iostream>
using namespace std;

void countingValleys(int n, char *s)
{
    int level = 0;
    int valleys = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == 'U')
        {
            level++;
        }
        else if (s[i] == 'D')
        {
            if (level == 0)
            {
                valleys++;
            }
            level--;
        }
    }
    cout << valleys;
}

int main()
{
    int n;
    cin >> n;
    char s[n];
    for (int i = 0; i < n; i++)
    {
        cin >> s[i];
    }

    countingValleys(n, s);
}