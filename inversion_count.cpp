// //inversion count means you are iInversion Count for an array indicates – how far (or close) the array is from being sorted. If the array is already sorted, then the inversion count is 0, but if the array is sorted in the reverse order, the inversion count is the maximum. 
// Formally speaking, two elements a[i] and a[j] form an inversion if a[i] > a[j] and i < j 
// Example: 

// Input: arr[] = {8, 4, 2, 1}
// Output: 6

// Explanation: Given array has six inversions:
// (8, 4), (4, 2), (8, 2), (8, 1), (4, 1), (2, 1).


// Input: arr[] = {3, 1, 2}
// Output: 2

// Explanation: Given array has two inversions:
// (3, 1), (3, 2) 


#include <bits/stdc++.h>
using namespace std;
#define int long long 
 
// Driver Code
int is_sort(int a,int n, int arr[],vector<int> & let)
{
    if(n==1) 
    {
        if(arr[n-1]==a)
        let.push_back(n);
        return n;
        return -1;
    }
    int ans=is_sort(a,n-1,arr,let);
    if(arr[n-1]==a){
        let.push_back(n);
        return n;
        
    } 
    return ans;
}
int merge(int low,int ,int ,int []);
int merge_sort(int low,int high,int arr[])
{
    if(low<high)
    {
        int mid=low+(high-low)/2;
        int x=merge_sort(low,mid,arr);
        int y=merge_sort(mid+1,high,arr);
        return x+y+merge(low,mid,high,arr);
    }
    return 0;
}
int merge(int low,int mid,int high,int arr[])
{
    int one[mid-low+1];
    for(int i=0;i<mid-low+1;i++)
    {
        one[i]=arr[low+i];
    }
    int two[high-mid];
    for(int i=0;i<high-mid;i++)
    {
        two[i]=arr[i+mid+1];
    }
    int count=0;
    int i=0,j=0;
    int k=low;
    while(i<mid-low+1 && j<high-mid)
    {
            if(one[i]<=two[j])
            {
                arr[k++]=one[i++];
            }
            else
            {
                count+=mid-low-i+1;
                arr[k++]=two[j++];
            }
    }
    while(i<mid-low+1)
    {
        arr[k++]=one[i++];
    }    
while(j<high-mid)
    {
        arr[k++]=two[j++];
    }    
    return count;
}

int32_t main()
{
 
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
        int n;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++)
        cin>>arr[i];
        cout<<merge_sort(0,n-1,arr)<<" ";
    return 0;
}