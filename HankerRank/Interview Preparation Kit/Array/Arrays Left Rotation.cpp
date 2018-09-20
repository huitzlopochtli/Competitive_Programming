#include<iostream>

// Function to leftRotate array multiple times
void leftRotate(int arr[], int n, int k)
{
    /* To get the starting point of rotated array */
    int mod = k % n;

    // Prints the rotated array from start position
    for (int i = 0; i < n; i++)
        std::cout << (arr[(mod + i) % n]) << " ";

    std::cout << "\n";
}


int main()
{
    int number;
    std::cin >> number;

    int rotation;
    std::cin >> rotation;

    int arr[number];

    for(int i = 0; i < number; i++)
        std::cin >> arr[i];


    rotation = rotation  % number; // 4

    for (int i = 0; i < number; i++)
        std::cout << (arr[(rotation + i) % number]) << " ";

    return 0;
}
