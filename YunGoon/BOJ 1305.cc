#include <cstdio>

char str[1000001];
int fail[1000001];

int main() {
	int n;
	scanf("%d %s", &n, str);

	// 그냥 KMP 실패함수를 구현하는 끝나는 매우 간단한 문제.
	// KMP를 사용해야 한다는 것을 깨닫는 것이 포인트.
	for (int i = 1, j = 0; str[i]; ++i) {
		while (j > 0 && str[j] != str[i]) j = fail[j - 1];
		if (str[j] == str[i]) fail[i] = ++j;
	}

	printf("%d", n - fail[n - 1]);

	return 0;
}
