#include<bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define ull unsigned long long
void combination(ull n,ull r)
{
    ull p=1,k=1;
    if((n-r)<r)
    r=(n-r);
    if(r==0)
    p=1;
    else
    {
    while(r)
    {
        p*=n;
        if(p>1e18)
        {
           break;
        }
        k*=r;
        ull m=__gcd(p,k);
        p/=m;
        k/=m;
        n--;
        r--;
    }
    }
    cout<<p<<'\n';
}   
int main()
{
    fast;
    ull l,t,n;
    cin>>t;
    while(t--)
    {
        cin>>n>>l;
        ull a[n],mx=0,j,p,q1=0;
        ull b[32]={0};
        for(ull i=0;i<n;i++)
        {
          cin>>a[i];
          
          p=a[i];
          q1=q1|p;
          j=0;
          while(p!=0)
          {
            b[j]+=(p%2);
            j++;
            p/=2;
          }
          mx=max(j,mx);
        }
        bitset<32> c(q1);
        if(c.count()<l)
        cout<<"-1\n";
        else if(c.count()==l)
        cout<<"1\n";
        else
        {
        for(ull i=0;i<mx;i++)
        b[i]=(b[i]*pow(2,i));
        sort(b,b+mx,greater<int>());  
        ull q=b[l-1];
        ull s;
        for(ull i=0;i<mx;i++)
        {
            if(b[i]==q)
            {
                s=i;
                break;
            }
        }
        l-=s;
        ull e= count(b+s,b+mx,q);
        combination(e,l);
        }
    }  
    return 0;
}
