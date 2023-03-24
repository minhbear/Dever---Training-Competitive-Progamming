#include <bits/stdc++.h>
using namespace std;

int f[5005][5005];
char s[5005];
int n;

main() {
	cin >> n;
	for(int i=1; i<=n; i++){
		cin >> s[i];
	}
	for(int i=0; i<=n; i++){
		for(int j=0; j<=n; j++){
				f[i][j] = 0;
		}
	}
	
	for(int i=n; i>=1; i--){
		for(int j=i+1; j<=n; j++){
			if(s[i] == s[j]){
				f[i][j] = f[i+1][j-1];
			}else{
				f[i][j] = min(f[i+1][j], f[i][j-1]) + 1;
			}
		}
	}
	
	cout << f[1][n];
	return 0;
}
