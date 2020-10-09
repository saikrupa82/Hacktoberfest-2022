#include<bits/stdc++.h>
#include<climits>
using namespace std;

int main() 
{
    int t,n;
    cin>>t;
    while(t--)
    {
        cin>>n;
        int a[n],mx=INT_MIN,mn,p=-1,f=0,q=-1,i;
        for(int j=0;j<n;j++)
        cin>>a[j];
        mn=a[0];
        p=0;
        for(i=1;i<n;i++)
        {
            if(a[i]-mn<0 && mx==INT_MIN)
            {
                mn=a[i];
                p=i;
            }
            else if(mn!=a[i] && a[i]>mx)
            {
                mx=a[i];
                q=i;
            }
            if(mx==a[i-1] && a[i]<mx)
            {
                cout<<"("<<p<<" "<<q<<") ";
                f=1;
                mn=a[i];
                p=i;
                mx=INT_MIN;
            }
        }
        if(i==n && p<q)
        cout<<"("<<p<<" "<<q<<") \n";
        else if(f==0)
        cout<<"No Profit\n";
        else
        cout<<"\n";
    }
	return 0;
}
