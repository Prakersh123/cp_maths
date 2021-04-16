#include<bits/stdc++.h>
using namespace std;

int pow(int a,int n)
{
    if(a==1 || n==0) return 1;
    int cal=pow(a,n/2);
    if(n&1)
    return a*cal*cal;
    return cal*cal;
}


int main()
{   int a;
    int n;
    cin>>a>>n;
    cout<<pow(a,n);
    return 0;
}