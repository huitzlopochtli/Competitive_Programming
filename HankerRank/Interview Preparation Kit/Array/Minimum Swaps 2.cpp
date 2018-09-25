#include<iostream>

void printArray(int arr[], int n)
{
    for (int i=0; i < n; i++)
        std::cout << arr[i] <<" ";
}

int partition(int a[],int l,int u)
{
    int v,i,j,temp;
    v=a[l];
    i=l;
    j=u+1;

    do
    {
        do
            i++;

        while(a[i]<v&&i<=u);

        do
            j--;
        while(v<a[j]);

        if(i<j)
        {
            temp=a[i];
            a[i]=a[j];
            a[j]=temp;
        }
    }while(i<j);

    a[l]=a[j];
    a[j]=v;

    return(j);
}


void quick_sort(int a[],int l,int u)
{
    int j;
    if(l<u)
    {
        j=partition(a,l,u);
        quick_sort(a,l,j-1);
        quick_sort(a,j+1,u);
    }
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

    quick_sort(arrCopy,0, length-1);

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

