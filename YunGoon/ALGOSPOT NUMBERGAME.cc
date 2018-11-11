#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int INF = 0x3f3f3f3f;

int dp[50][50];
int arr[50];

int ans(int s, int e) {
	if (s > e) return 0;
	if (s == e) return arr[s];

	int &ret = dp[s][e];
	if (ret != INF) return ret;

	// 왼쪽 2개를 버리는 경우, 오른쪽 2개를 버리는 경우,
	// 왼쪽 1개를 취하는 경우, 오른쪽 1개를 취하는 경우
	// 4가지 중에 최댓값이 곧 최선의 플레이
	return ret = max({ -ans(s + 2, e), -ans(s, e - 2),
		arr[s] - ans(s + 1, e), arr[e] - ans(s, e - 1) });
}
int main() {
	int c;
	scanf("%d", &c);

	while (c--) {
		int n;
		scanf("%d", &n);

		for (int i = 0; i < n; ++i) scanf("%d", arr + i);

		// 절대 나올 수 없는 INF로 초기화
		memset(dp, 0x3f, sizeof(dp));
		printf("%d\n", ans(0, n - 1));
	}

	return 0;
}
