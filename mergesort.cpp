#include<iostream>


using namespace std;

void merge(int a[],int l[],int r[],int nl,int nr)
{
	int i,j,k;
	i=j=k=0;
	while(i<nl && j<nr)
	{
		if(l[i]<=r[j])
			a[k++]=l[i++];
		else
			a[k++]=r[j++];
	}
	while(i<nl)
		a[k++]=l[i++];
	while(j<nr)
		a[k++]=r[j++];
	
}

void mergesort(int a[],int n)
{
	if(n<2)
	return ;
	int mid=n/2;	
	int l[mid],r[n-mid];
	for(int i=0;i<mid;i++)
		l[i]=a[i];
	for(int i=mid;i<n;i++)
		r[i-mid]=a[i];
		
	mergesort(l,mid);
	mergesort(r,n-mid);
	
	merge(a,l,r,mid,n-mid);
}


int main()
{
	int a[]={2,4,1,6,8,5,3,7};
	int len;
	cout<<"Enter length of array ";
	cin>>len;
	for(int i=0;i<len;i++)
	a[i]=(rand()%1000 - 100);
	for(int i=0;i<len;i++)
	{
		cout<<a[i]<<" ";
	}
	cout<<endl;
	mergesort(a,len);
	
	for(int i=0;i<len;i++)
	{
		cout<<a[i]<<" ";
	}
	return 0;
	
}
