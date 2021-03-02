#include<bits/stdc++.h>
#define PB push_back
#define MP make_pair
#define F first
#define S second
#define MOD	1000000007
#define int	long long
#define pii pair<int,int> 
#define vi vector<int>
using namespace std;

int GCD(int a, int b){
	if(b == 0){
		return a;
	}
	else{
		return GCD(b, a%b);
	}
}

int32_t main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	vector<int>prime;
	int n = 1000000;
	vector<bool> V(n+1, true);
	V[0] = false;
	V[1] = false;
	for(int i = 2; i <= n+1; i++){
		if(V[i] == true){
			prime.PB(i);
			for(int j = i*i; j <= n+1; j += i){
				V[j] = false;
			}
		}
	}
	
	int t;
	cin >> t;
	while(t--){
		int a, b;
		cin >> a >> b;
		map<int,int> ma;
		int s = 1;
		int m = GCD(a,b);
		int M = m;
		for(auto i : prime){
			if(i > M){
				break;
			}
			while(m % i == 0){
				m /= i;
				ma[i]++;
			}
			if(ma.count(i)){
				s *= (ma[i] + 1);
			}
		}
		cout << s << "\n";
	}

	return 0;
}

