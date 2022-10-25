#include <bits/stdc++.h>
using namespace std;
#define NMH ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
void rec(int n,int i)
{
    if(n==1)
    {
        for(int j=0; j<i; j++)
            cout<<" ";
        cout<<"*";
    }
    else
    {
        rec(n/2,i);
        cout<<"\n";
        for(int j=0; j<i; j++)
            cout<<" ";
        for(int j=0; j<n; j++)
            cout<<"* ";
        cout<<"\n";
        rec(n/2,i+n);
    }
}

int main()
{
    NMH
    rec(8,0);
    return 0;
}
