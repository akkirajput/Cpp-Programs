#include<iostream>
using namespace std;

void insertionsort(int a[],int n)
{
    for(int i=1;i<n;i++)
    {
        int val=a[i];
        int j=i;
            while(j>0 && a[j-1]>val)
            {
                a[j]=a[j-1];
                j--;
            }
            a[j]=val;
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
    insertionsort(a,n);
    for(int i=0;i<n;i++)
    cout<<a[i]<<" ";
    return 0;
}