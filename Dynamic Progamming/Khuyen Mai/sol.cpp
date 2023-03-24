#include <bits/stdc++.h>
using namespace std;
const int INF = 300005;
int a[1005];
int n;
int f[1005][1005];

int main() {
	cin >> n;
	for(int i=1; i<=n; i++){
		cin >> a[i];
	}
	for(int i=0; i<=n; i++){
		for(int j=0; j<=n; j++){
			if(i==0 && j==0){
				f[i][j] = 0;
			}else{
				f[i][j] = INF;
			}
		}
	}

	for(int i=0; i<=n; i++){
		for(int j=0; j<=i; j++){
			if(f[i][j] != INF){
				if(a[i+1] <= 100){
					f[i+1][j] = min(f[i+1][j], (f[i][j] + a[i+1]));
				}else{
					f[i+1][j+1] = min(f[i+1][j+1], (f[i][j] + a[i+1]));
				}
			
				if(j > 0){
					f[i+1][j-1] = min(f[i+1][j-1], f[i][j]);
				}	
			}
		}
	}
	
	int ans = INF;
	for(int i=0; i<=n; i++){
		ans = min(ans, f[n][i]);
	}
	
	cout << ans;
	
	return 0;
}
