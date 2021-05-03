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

    //a^b
int modular_exponentiation_using_bitmask(int a,int b)   
{
        int res=1;
        while(b)
        {
            if(b&1)
            res=(res*a);
            b=b>>1;
            a*=a;
        }
        return res;
}

int main()
{
    
        freopen("/home/prakersh/Desktop/my_solution/input.txt","r",stdin);
        freopen("/home/prakersh/Desktop/my_solution/output.txt","w",stdout);

       int a;
    int n;
    cin>>a>>n;
    cout<<pow(a,n)<<endl;
    cout<<modular_exponentiation_using_bitmask(a,n);
    return 0;
}