#include <iostream>
#include <algorithm>

int main()
{
    int length;
    std::cin >> length;

    int cost;
    std::cin >> cost;

    int arr[length];
    for(int i = 0; i < length; i++)
        std::cin >> arr[i];


    std::sort(arr, arr+length);


    int maxToy = 0;

    for(int i = 0; i < length; i++)
    {
        cost -= arr[i];
        if(cost > 0)
        {
            maxToy++;
        }
        else
            break;
    }


    std::cout << maxToy;

}
