
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

int subsum(int arr[],int n,int s){
    if(n==0 || s==0)
    return 0;
    else{
        if(arr[n-1]<=s)
        return max((arr[n-1]+subsum(arr,n-1,s-arr[n-1])),subsum(arr,n-1,s));
        else
        return subsum(arr,n-1,s);
    }
}
class Solution{

	public:
	int minDiffernce(int arr[], int n) 
	{ 
	    int s=0,s1,s2;           
	    for(int i=0;i<n;i++){
	        s+=arr[i];
	    }
	    s1=s>>1;
	    int dp[n+1][s1+1];
	    for(int i=0;i<n+1;i++){
	        for(int j=0;j<s1+1;j++){
	            if(i==0 || j==0)
	            dp[i][j]=0;
	            else{
	                if(arr[i-1]<=j)
	                dp[i][j]=max((arr[i-1]+dp[i-1][j-arr[i-1]]),dp[i-1][j]);
	                else
	                dp[i][j]=dp[i-1][j];
	            }
	        }
	    }
	    return abs(s-(2*dp[n][s1]));
	} 
};


// { Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.minDiffernce(a, n) << "\n";
	     
    }
    return 0;
}  // } Driver Code Ends
