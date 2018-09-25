#include <iostream>

int bubbleSort(int arr[], int n)
{
    int numSwap = 0;

    for(int i = 0; i < n; i++)
        for(int j = 0; j<n-1; j++)
        {
            if(arr[j] > arr[j+1])
            {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                numSwap++;
            }
        }
    return numSwap;
}


int main()
{
    int n;
    std::cin>>n;

    int arr[n];
    for(int i =0; i< n; i++)
        std::cin>>arr[i];

    int numSwap = bubbleSort(arr, n);


    std::cout<<"Array is sorted in "<<numSwap<<" swaps."<<std::endl;
    std::cout<<"First Element: "<<arr[0]<<std::endl;
    std::cout<<"Last Element: "<<arr[n-1]<<std::endl;

}
