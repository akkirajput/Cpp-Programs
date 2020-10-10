#include<iostream>
#include<vector>
using namespace std;

int main()
{
    int n,m;
    cout<<"Enter number of row and column : ";
    cin>>n>>m;

    int a[n][m];
    for(int i=1;i<=n;i++)
    for(int j=1;j<=m;j++)
    // a[i][j]=0;
    cin>>a[i][j];

   
    
    int dp[n][m];

    for(int i=n;i>=1;i--)
    {
        for(int j=m;j>=1;j--)
        {
            if(i==n && j==m)
            dp[i][j]=1;
            else{
                int op1=(i==n)?0:dp[i+1][j];
                int op2=(j==m)?0:dp[i][j+1];
                if(a[i][j]==1)
                dp[i][j]=0;
                else
                dp[i][j]=op1+op2;
            }
        }
    }
    
    if(a[n][m]!=1)
    cout<<"Possible paths : "<<dp[1][1];
    else
    cout<<"Possible paths : 0";
    

   

   
    return 0;
}