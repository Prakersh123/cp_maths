#include<bits/stdc++.h>
using namespace std;
#define int long long 


//brute force approach O(n)
void prime_factor_brute(int n)
{
    for(int i=2;i<=n;i++)
    {
        if(n%i==0)
        {
            int count=0;
            while(n%i==0)
            {
                cout<<i<<"*";
                n/=i;
            }
        }
    }
}


//Oprtimized approach O(sqrt(n))
void prime_factor_optimized(int n)
{
    for(int i=2;i*i<=n;i++)
    {
        if(n%i==0)
        {
            int count=0;
            while(n%i==0)
            {
                cout<<i<<"*";
                n/=i;
            }
        }
    }
    if(n>1)
    cout<<n;
}

//sieve approach O()
//first we will calculate all the primes upto sqrt(n) using sieve
//now we will use the same concept of dividing the number to get the factors but this time we are dividing only with prime numbers not with every number
//here i am creating a vector which will contain all prime numbers upto 100000
vector<int>sieve()
{
    vector<int>prime;
    int n=100000;
    int arr[100000]={0};
    arr[0]=arr[1]=1;

    for(int i=2; i*i<=n;i++)
    {
        if(arr[i]==0)
        {
            for(int j=i*i;j<=n;j+=i)
            arr[j]=1;
        }
    }
    for(int i=2;i<=n;i++)
    if(arr[i]==0) prime.push_back(i);
    return prime;
}
void best_approach(int n,vector<int>prime)
{
    int i=0;
    int p=prime[0];
    while(p*p<=n)
    {
        if(n%p==0)
        {
            while(n%p==0)
            {
                cout<<p<<"*";
                n/=p;
            }
        }
        i++;
        p=prime[i];
    }
    if(n>1)
    cout<<n;
}

int32_t main()
{
    
    freopen("/home/prakersh/Desktop/input.txt","r",stdin);
    freopen("/home/prakersh/Desktop/output.txt","w",stdout);
    int n;
    cin>>n;
    // prime_factor_brute(n);
    // cout<<endl;
    // prime_factor_optimized(n);
    vector<int> prime;
    prime=sieve();
    best_approach(n,prime);
    
    cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;

}