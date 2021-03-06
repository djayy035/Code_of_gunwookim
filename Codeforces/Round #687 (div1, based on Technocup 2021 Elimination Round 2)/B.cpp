#include <bits/stdc++.h>
#define x first
#define y second
#define pb push_back
#define all(v) v.begin(),v.end()
#pragma gcc optimize("O3")
#pragma gcc optimize("Ofast") 
#pragma gcc optimize("unroll-loops")
using namespace std;
const int INF = 1e9;
const int TMX = 1 << 18;
const long long llINF = 5e18;
const long long mod = 1e9+7;
const long long hmod1 = 1e9+409;
const long long hmod2 = 1e9+433;
const long long base = 257;
typedef long long ll;
typedef long double ld;
typedef pair <int,int> pi;
typedef pair <ll,ll> pl;
typedef vector <int> vec;
typedef vector <pi> vecpi;
typedef long long ll;
int n;
int s[100005],a[100005];


int main() {
	ios_base::sync_with_stdio(false), cin.tie(0);
	cin >> n;
	for(int i = 1;i <= n;i++) {
		cin >> a[i], s[i] = s[i-1]^a[i];
	}
	for(int i = 1;i <= n-2;i++) {
		if((a[i+2]^a[i+1]) < a[i]) {
			cout << "1\n";
			return 0;
		}
	}
	for(int i = 1;i <= n-2;i++) {
		if((a[i+1]^a[i]) > a[i+2]) {
			cout << "1\n";
			return 0;
		}
	}
	int ans = INF;
	for(int i = 1;i <= n;i++) {
		for(int j = i+1;j <= n;j++) {
			if((s[i]^s[j]) < a[i]) ans = min(ans,j-i-1);
		}
	}
	for(int i = 0;i < n;i++) {
		for(int j = i+1;j < n;j++) {
			if((s[i]^s[j]) > a[j+1]) ans = min(ans,j-i-1);
		}
	}
	if(ans == INF) ans = -1;
	cout << ans << '\n';
}
