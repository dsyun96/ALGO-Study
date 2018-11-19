#include <cstdio>
#include <vector>
using namespace std;

using vd = vector<double>;
using vvd = vector<vd>;

vvd mul(vvd &a, vvd &b) {
	int len = a.size();
	vvd ret(len, vd(len));

	for (int i = 0; i < len; ++i) {
		for (int j = 0; j < len; ++j) {
			for (int k = 0; k < len; ++k)
				ret[i][j] += a[i][k] * b[k][j];
		}
	}

	return ret;
}

class SqrMat {
public:
	vvd vec;
	int size;

	SqrMat(int n) : size(n) {
		vec.resize(n);
		for (int i = 0; i < n; ++i) vec[i].resize(n);
	}
	SqrMat(const vvd& tmp) : vec(tmp) {}

	vvd pow(int k) {
		vvd tmp(size, vd(size));
		for (int i = 0; i < size; ++i) tmp[i][i] = 1.0;

		while (k) {
			if (k & 1) tmp = mul(tmp, vec);
			vec = mul(vec, vec);
			k >>= 1;
		}

		return tmp;
	}
};

void simul() {
	int n, k, m;
	scanf("%d %d %d", &n, &k, &m);

	int L[50];
	for (int i = 0; i < n; ++i) scanf("%d", L + i);

	double T[50][50];
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			scanf("%lf", T[i] + j);

	SqrMat W(4 * n);
	for (int i = 0; i < 3 * n; ++i)
		W.vec[i][i + n] = 1.0;

	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			W.vec[3 * n + i][(4 - L[j]) * n + j] = T[j][i];

	SqrMat Wk(W.pow(k));

	vd ret(n);
	for (int song = 0; song < n; ++song)
		for (int start = 0; start < L[song]; ++start)
			ret[song] += Wk.vec[(3 - start) * n + song][3 * n];
	
	int q;
	for (int i = 0; i < m; ++i) {
		scanf("%d", &q);
		printf("%.8f ", ret[q]);
	}
	puts("");
}
int main() {
	int t;
	scanf("%d", &t);

	while (t--) simul();

	return 0;
}
