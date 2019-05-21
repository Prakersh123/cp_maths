#include<bits/stdc++.h>
using namespace std;


    //brute force to check isprime(n) T.C. O(N)
    bool isprime(int n)
    {
        if(n==1) return false;
        if(n==2) return true;
        for(int i=2;i<=n-1;i++)
            if(n%i==0)
                return false;
        return true;
    }
    // better approach O(sqrt(n))
    bool isprime_better(int n)
    {
        if(n==1) return false;
        if(n==2) return true;
        for(int i=2;i*i<=n;i++)
            if(n%i==0)
                return false;
        return true;
    }

        //sieve of erathosense O(nlog(n)log(n)) sc O(n) 
    void sieve(int arr[],int n)
    {
        for(int i=2;i*i<=n;i++)
        {
            if(arr[i]==1){
                 //as our i is prime no , so now we will unmark all those no which are divisible by this i
                for(int j=i*i;j<=n;j+=i)
                {
                    arr[j]=0;
                }
            }
        }
    }
       //here we just used bitset to optimize the space. 
    void bitset_sieve()
    {
        int n;
        cin>>n;
        bitset<n+1> arr;
        arr.set();
        arr[0]=arr[1]=0;
        for(int i=2;i*i<=n;i++)
        {
            if(arr[i]==1){
                 //as our i is prime no , so now we will unmark all those no which are divisible by this i
                for(int j=i*i;j<=n;j+=i)
                {
                    arr[j]=0;
                }
            }
        }
        for(int i=2;i<=n;i++)
        if(arr[i]==1)
        cout<<i<<" ";
    }
int main()
{
        // int n;
        // cin>>n;
        // int prime[n+1];
        // for(int i=0;i<=n;i++)prime[i]=1;
        // sieve(prime,n);
        // for(int i=2;i<=n;i++)
        // if(prime[i]==1)
        // cout<<i<<" ";
        bitset_sieve();
        return 0;
}