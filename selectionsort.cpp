#include<iostream>
using namespace std;

void selectionsort(int a[],int n)
{
    for(int i=0;i<n-1;i++)
    {
        int min=i;
        for(int j=i+1;j<n;j++)
        {
            if(a[j]<a[min])
            min=j;
        }
        swap(a[i],a[min]);
    }
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
    selectionsort(a,n);
    for(int i=0;i<n;i++)
    cout<<a[i]<<" ";
    return 0;
}