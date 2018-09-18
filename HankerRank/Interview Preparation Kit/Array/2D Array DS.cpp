#include <bits/stdc++.h>

using namespace std;

// Complete the hourglassSum function below.
int hourglassSum(int arr[][6]) {

    short int sum;
    short int tempSum = 0;
    for(int i = 0; i <=3 ; i++)
    {
        for(int j = 0; j<=3; j++)
        {
            int tempSum = arr[i][j] + arr[i][j+1] + arr[i][j+2] + arr[i+1][j+1] + arr[i+2][j] + arr[i+2][j+1] + arr[i+2][j+2];

            if(sum < tempSum || (j == 0 && i == 0))
                sum = tempSum;

            tempSum = 0;
        }
    }


    return sum;

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int arr[6][6];
    for (int i = 0; i < 6; i++) {

        for (int j = 0; j < 6; j++) {
            cin >> arr[i][j];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    int result = hourglassSum(arr);

    fout << result << "\n";

    fout.close();

    return 0;
}
