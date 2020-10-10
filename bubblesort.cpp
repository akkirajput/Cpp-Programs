#include<iostream>
using namespace std;

void bubblesort(int a[],int n)
{
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n-i-1;j++)
        {
            if(a[j]>a[j+1])
            swap(a[j],a[j+1]);
        }
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
    bubblesort(a,n);
    for(int i=0;i<n;i++)
    cout<<a[i]<<" ";
    return 0;
}