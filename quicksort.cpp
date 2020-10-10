#include <iostream>
#include <algorithm>
using namespace std;

int partition(int a[],int start,int end)
{
    int pivot=a[end];
    int pindex=start;

    for(int i=start;i<end;i++)
    {
        if(a[i]<=pivot)
        {
            swap(a[i],a[pindex]);
            pindex++;
        }
    }
    swap(a[pindex],a[end]);
    return pindex;
}
void quicksort(int a[],int start,int end)
{
    if(start>=end)
    return;

    int pivot=partition(a,start,end);

    quicksort(a,start,pivot-1);
    quicksort(a,pivot+1,end);
}


int main()
{
    int n;
    cout<<"Enter number of elements in an array : ";
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    a[i]=rand()%100-50;
    for(int i=0;i<n;i++)
    cout<<a[i]<<" ";
    cout<<endl;
    quicksort(a,0,n-1);
    for(int i=0;i<n;i++)
    cout<<a[i]<<" ";
    return 0;
}