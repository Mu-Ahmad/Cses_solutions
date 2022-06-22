#include <iostream>
#include <vector>
#define mod 1000000007

using namespace std;


int main(){
	int n; cin >> n;
	long long target = n*(n+1) / 2;

	if (target & 1) {
		puts("0"); return 0;
	}

	target /= 2;

 	vector <int> dp(target+1);
 	dp[0] = 1;
 	for (int num=1; num<=n; num++){
 		for (int curr = target; curr>=num; curr--)
 			(dp[curr] += dp[curr-num]) %= mod;
 	}
	
	if (dp[target] % 2 == 0)
		cout << (dp[target]) / 2 << '\n';
	else 
		cout << (dp[target] + mod) / 2 << '\n';



	return 0;
}
