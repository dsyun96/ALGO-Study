#include <cstdio>
#include <cstring>
#include <algorithm>
using std::min;

int n, arr[16][16];
int dp[1 << 16];
const int INF = 10000;

int ans(int state, int cnt) {
	// 현재 상태가 state이고, cnt개를 고를 때
	// 드는 최소 비용을 구하는 함수
	if (cnt <= 0) return 0;

	int &ret = dp[state];
	if (ret != -1) return ret;

	ret = INF;
	for (int i = 0; i < n; ++i) if (state & 1 << i) {
		for (int j = 0; j < n; ++j) {
			if (state & 1 << j) continue;
			ret = min(ret, arr[i][j] + ans(state | 1 << j, cnt - 1));
		}
	}

	return ret;
}
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			scanf("%d", arr[i] + j);

	char on[17];
	int p;
	scanf("%s %d", on, &p);

	int state = 0, cnt = 0;
	// 현재 켜진 상태를 비트로 저장
	for (int i = 0; i < n; ++i)
		if (on[i] == 'Y') ++cnt, state |= 1 << i;

	memset(dp, -1, sizeof(dp));

	int r = ans(state, p - cnt);
	printf("%d", r == INF ? -1 : r);

	return 0;
}

/*******************************************************************************

처음엔 그리디하게 늘리면 되는 줄 알고 프림 알고리즘처럼 짰더니 틀리길래
잘 생각해 봤더니 아래의 케이스에 대해서 먼저 3을 고르기 때문에 그 다음엔 17을 고른다.
하지만 17을 고르고 1을 고르면 18이 될 수 있으므로 그리디하게는 풀 수 없다.

4
0 3 50 17
50 0 50 50
50 50 0 50
50 50 1 0
YNNN
3

********************************************************************************/
