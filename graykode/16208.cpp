#include<bits/stdc++.h>
using namespace std;
long long a[500001], s[500001], n;
long long sum(int left, int right) {
	return s[right] - s[left - 1];
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	s[1] = a[1];
	for (int i = 2; i <= n; i++)
		s[i] = s[i - 1] + a[i];
	long long ans = 0;
	for (int i = 1; i < n; i++) {
		ans += a[i] * sum(i + 1, n);
	}
	cout << ans;
}
