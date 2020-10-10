#include<iostream>
// #include<algorithm>
// #include<stdlib.h>
#include<string>
using namespace std;
void permu(string s,int l,int r)
{
    
    if(l==r)
    cout<<s<<" ";
    else
    {
        for(int i=l;i<=r;i++)
        {
            swap(s[l],s[i]);
            permu(s,l+1,r);
            swap(s[l],s[i]);
        }
    }
    
}

int main()
{
    string s;
    cin>>s;
    int l=s.length();
    
    permu(s,0,l-1);
    return 0;
}