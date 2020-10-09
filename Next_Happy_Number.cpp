#include<bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);
#define T int t; cin>>t; while(t--)
#define llin(a) int a; cin>>a;
map<int,int> m;
int happy(int n,int n2) {
    
    int d1=0,n1=n;
    if(m[n]>0){
     return 0;
    }
    else {
    m[n1]=1;
   // cout<<m[n1]<<" ";
    while(n1>0) {
        d1+=((n1%10)*(n1%10));
        n1/=10;
    }
    if(d1==1)
        return n2;
    else
       return happy(d1,n2);
   }
}
int main() {
    
    fast;
    T{
        llin(n);
        int d=0;
        while(d==0) {
        d=happy(n+1,n+1);
        m.clear();
        if(d)
        cout<<d<<'\n';
        else
        n+=1;
        }
    }
	return 0;
}
