#include <cstdio>
#include <algorithm>
using std::max;

void simul() {
	int n, m;
	scanf("%d %d", &n, &m);

	int price[20], pref[20];
	for (int i = 0; i < n; ++i) {
		scanf("%d %d", price + i, pref + i);
		price[i] /= 100;
	}
	m /= 100;

	int ans = 0, c[201];
	for (int budget = 0; budget <= m; ++budget) {
		int cand = 0;
		for (int dish = 0; dish < n; ++dish) {
			if (budget >= price[dish]) {
				cand = max(cand, c[(budget - price[dish]) % 201] + pref[dish]);
			}
		}

		c[budget % 201] = cand;
		ans = max(ans, cand);
	}

	printf("%d\n", ans);
}

int main() {
	int tc;
	scanf("%d", &tc);
	
	while (tc--) simul();

	return 0;
}
