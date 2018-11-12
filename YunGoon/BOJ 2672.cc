#include <cstdio>
#include <vector>
#include <algorithm>
#define all(x) x.begin(), x.end()
using namespace std;

struct T {
	double a, b, c, d;
};

int main() {
	int n;
	scanf("%d", &n);

	vector<double> x(2 * n), y(2 * n);
	vector<T> vec(n);
	double a, b, c, d;
	for (int i = 0; i < n; ++i) {
		scanf("%lf %lf %lf %lf", &a, &b, &c, &d);
		vec[i] = { a, b, a + c, b + d };
		x[i * 2] = a;
		y[i * 2] = b;
		x[i * 2 + 1] = a + c;
		y[i * 2 + 1] = b + d;
	}

	sort(all(x));
	sort(all(y));

	double ans = 0;
	// 모든 모서리를 기준으로 토막을 내고
	// 작은 직사각형이 입력으로 받은 n개의 직사각형 중
	// 어느 한 곳에라도 속하면 넓이를 누적한다
	for (int i = 0; i < 2 * n - 1; ++i) {
		for (int j = 0; j < 2 * n - 1; ++j) {
			double nx = (x[i] + x[i + 1]) / 2;
			double ny = (y[j] + y[j + 1]) / 2;

			bool chk = 0;
			for (int k = 0; k < n; ++k) {
				if (vec[k].a < nx && nx < vec[k].c &&
					vec[k].b < ny && ny < vec[k].d) {
					chk = 1;
					break;
				}
			}

			if (chk) ans += (x[i + 1] - x[i]) * (y[j + 1] - y[j]);
		}
	}

	// 소수점 3번째 자리에서 반올림해도 00이면 그냥 정수로 출력
	if (int(ans * 100 + 0.5) % 100 == 0) printf("%d", int(ans));
	else printf("%.2f", ans);

	return 0;
}
