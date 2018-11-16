#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int main() {
	char str[2501];
	scanf("%s", str);

	int n = strlen(str) * 2 + 1;
	char dat[5005];
	// 마나커 알고리즘을 사용하기 위한 전처리
	for (int i = 0; i < n; ++i) {
		if (i & 1) dat[i] = str[i >> 1];
		else dat[i] = '#';
	}

	// 본격적인 마나커 알고리즘
	int r = -1, p = -1, plen[5005];
	for (int i = 0; i < n; ++i) {
		if (i <= r) plen[i] = min(plen[2 * p - i], r - i);
		else plen[i] = 0;

		while (i + plen[i] + 1 < n && i - plen[i] - 1 >= 0 &&
			dat[i + plen[i] + 1] == dat[i - plen[i] - 1]) ++plen[i];

		if (i + plen[i] > r) {
			r = i + plen[i];
			p = i;
		}
	}

	// dp 테이블
	int dp[5005]{ 0, 1, 1 };
	for (int i = 3; i < n; ++i) {
		if (i % 2 == 0) {
			dp[i] = dp[i - 1];
			continue;
		}

		int mn = dp[i - 2] + 1;
		for (int j = 1; j + 1 <= i - j; ++j) {
			if (plen[i - j] >= j) {
				mn = min(mn, dp[i - 2 * j - 1] + 1);
			}
		}

		dp[i] = mn;
	}

	printf("%d", dp[n - 1]);

	return 0;
}

/*
 * 처음엔 마나커 돌리고 그리디하게 긴 팰린드롬 조각부터 취하는 방식으로 코딩했는데
 * aadaaakaaacaa 의 경우 가운데 [aaakaaa]를 먼저 취하게 되면
 * 양 끝은 1개씩 조각나기 때문에 [a, a, d, aaakaaa, c, a, a]로 7개가 된다.
 * 하지만 [aadaa, aka, aacaa]로 취하면 3개로 가능하다.
 * 그래서 그냥 2중 반복문을 돌려서 DP를 사용해 풀었다.
 */
