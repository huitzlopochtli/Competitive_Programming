#include<iostream>

void checkMin(int *arr, int t)
{

}
int main()
{
    int t;
    std::cin >> t;



    while(t>0)
    {
        int t1;
        std::cin >> t1;
        int arr[t1];
        for(int i = 0; i < t1; i++)
            std::cin >> arr[i];

        int count = 0;
        bool choatic = false;


        for(int i = t1 - 1; i >= 0; i--)
        {
            if(arr[i] - (i+1) > 2)
            {
                std::cout << "Too chaotic"<<std::endl;
                choatic = true;
                break;
            }
            for(int j = arr[i] - 2 > 0? arr[i] - 2 : 0; j<i; j++)
            {
                if(arr[j] > arr[i])
                {
                    count++;
                }
            }
        }

        std::cout<<count<<std::endl;

        --t;
    }
}

