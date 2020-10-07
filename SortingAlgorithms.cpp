#include<iostream>
using namespace std;
void print(int a[],int n)
{
     cout<<"Array AFTER sorting.\n";
    for(int i=0;i<n;i++)
    cout<<a[i]<<" ";
    cout<<"\n====================\n";
}
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

    print(a,n);
}

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
     print(a,n);
}

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
     print(a,n);
}

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
    int e;
    do{
        system("CLS");
        cout<<"------------SORTING ALGORITHMS------------\n";
        cout<<"1. Bubble Sort\n";
        cout<<"2. Insertion Sort\n";
        cout<<"3. Selection Sort\n";
        cout<<"4. Merge Sort\n";
        cout<<"5. Quick Sort\n";
        cout<<"6. Exit\n";
        cout<<"Enter choice :\t";
      
    
        int n,ch;
        cin>>ch; 
        if(ch==6)
        {
            cout<<"----Thanks for using...-----\n";
            system("pause");
            return 0;
        }
        if(ch>6 ||ch<1)
        {
            cout<<"Choose correct option!!!\n";
            system("PAUSE");
            continue;
        }
        cout<<"Enter how many number you want to sort ? ";
        cin>>n;
        int a[n];
        cout<<"Do you want to enter those "<<n<<" numbers or system take it for you\n(Press 'Y' for you or 'S' for system ? : ";
        char choice;
        cin>>choice;
        if(choice=='y'||choice=='Y')
        {
            for(int i=0;i<n;i++)
            cin>>a[i];
        }
        else
        {
            for(int i=0;i<n;i++)
            a[i]=rand()%100-60;
        }
       
        
        cout<<"Array BEFORE sorting.\n";
        for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
        cout<<"\n-------------------------\n";
        switch(ch)
        {
              
        case 1: bubblesort(a,n);            
                break;     
        case 2: insertionsort(a,n);
                break;
        case 3: selectionsort(a,n);
                break;
        case 4: {
                mergesort(a,n);
                print(a,n);
                break;
                }
        case 5: {
                quicksort(a,0,n-1);
                print(a,n);
                break;
                }
    	default:cout<<"Please enter correct choice!!!\n";
                break;
        }
        system("PAUSE");
        }while(e!=6 );
    
     return 0;
}
