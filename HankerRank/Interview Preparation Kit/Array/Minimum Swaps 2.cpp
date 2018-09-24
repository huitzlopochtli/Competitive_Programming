#include<iostream>

void printArray(int arr[], int n)
{
    for (int i=0; i < n; i++)
        std::cout << arr[i] <<" ";
}

void bubbleSort(int arr[], int n)
{
    if (n == 1)
        return;

    for (int i=0; i<n-1; i++)
        if (arr[i] > arr[i+1])
        {
            int temp = arr[i];
            arr[i] = arr[i+1];
            arr[i+1] = temp;
        }
    bubbleSort(arr, n-1);
}

int main()
{
    int length;
    std::cin>>length;

    int arr[length];
    int arrCopy[length];
    for(int i = 0; i< length; i++)
    {
        std::cin>>arr[i];
        arrCopy[i] = arr[i];
    }

    bubbleSort(arrCopy, length);

    int minSwap = 0;

    for(int i = 0; i < length; i++)
    {
        if(arr[i] != arrCopy[i])
        {
            minSwap++;
            for(int j = i + 1; j < length; j++)
            {
                if(arr[j] == arrCopy[i])
                {
                    int temp = arr[j];
                    arr[j] = arr[i];
                    arr[i] = temp;
                    break;
                }
            }
        }
    }

    std::cout<<minSwap;

}

