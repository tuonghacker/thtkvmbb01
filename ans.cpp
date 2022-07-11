#pragma GCC optimize("Ofast")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define gcd __gcd
#define pb push_back
#define pf push_front
#define reset(x, val) memset(x, val, sizeof(x))
#define FastIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
const int Mod = 1e9 + 7;

map<pair<long long,int>,int> f;
int n,m,i,k,a[38],kq,s1;

void dq1(int i, int d, int s){
	if (i>n/2+1 || d>m || s>k) return; 
	//if (i<=n/2) f[s]++;
	if (d+a[i]==m){
		if (s==k) ++kq;
	   return;
   }
   if (i==n/2+1) return; 
   f[{d+1,s+a[i]}]++;  
   dq1(i+1, d+1, s+a[i]);
   dq1(i+1, d, s);
}

void dq2(int i, int d, int s){
	if (i==n+1 || d>m || s>k) return; 
	if (f[{m-d-1,k-(s+a[i])}]>0) kq+=f[{m-d-1,k-(s+a[i])}]; 
   dq2(i+1, d+1, s+a[i]);
   dq2(i+1, d, s);
}

int main () { 
   FastIO;
   cin>>n>>m>>k;
   for (i=1; i<=n; ++i){
   	cin>>a[i];
   }
   dq1(1,0,0);
   f[{0,0}]=1; 
   dq2(n/2+1,0,0);
   cout<<kq;
}
