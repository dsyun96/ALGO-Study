#include <cstdio>
#include <utility>
#define X first
#define Y second
using namespace std;

struct Rec {
	pair<int, int> p[4];
};

int main() {
	int a, b, c, d;
	Rec r[2];
	for (int i = 0; i < 2; ++i) {
		scanf("%d %d %d %d", &a, &b, &c, &d);
		r[i].p[0] = { a, b };
		r[i].p[1] = { c, b };
		r[i].p[2] = { c, d };
		r[i].p[3] = { a, d };
	}

	// 설명이 필요없는 하드코딩
	if (r[1].p[2].Y < r[0].p[0].Y ||
		r[1].p[0].X > r[0].p[2].X ||
		r[1].p[0].Y > r[0].p[2].Y ||
		r[1].p[2].X < r[0].p[0].X) return !printf("NULL");

	if (r[0].p[0] == r[1].p[2] ||
		r[0].p[1] == r[1].p[3] ||
		r[0].p[2] == r[1].p[0] ||
		r[0].p[3] == r[1].p[1]) return !printf("POINT");

	if (r[1].p[2].Y == r[0].p[0].Y ||
		r[1].p[0].X == r[0].p[2].X ||
		r[1].p[0].Y == r[0].p[2].Y ||
		r[1].p[2].X == r[0].p[0].X) return !printf("LINE");

	printf("FACE");

	return 0;
}
