#include <cstdio>

int main() {
	char str[160]{};
	scanf("%s", str);

	for (int i = 0; str[i]; ++i) {
		// 처음에 1이 나오는 경우 -> 100~1~에 매칭
		if (str[i] == '1') {
			++i;
			// 0이 2개 이상인지 확인
			if (str[i] != '0' || str[i + 1] != '0') return !printf("NOISE");

			while (str[i] == '0') ++i;
			// 0이 다 매칭되고 문자열이 끝났다면 NOISE
			if (!str[i]) return !printf("NOISE");

			// 연속인 1도 끝까지 간다
			while (str[i] == '1') ++i;

			// 만약 이대로 문자열이 끝났으면 정상
			// 하지만 아직 안 끝났다면 그 다음이 100~1~인지 01인지 확인해야 함
			if (str[i]) {
				// 만약 01로 이어진다면 빼박 01
				// 00으로 이어진다면 100~1~이므로 이전에 1이 2번 이상인지 확인
				// 아니라면 NOISE
				if (str[i + 1] == '1') --i;
				else if (str[i - 2] == '1') i -= 2;
				else return !printf("NOISE");
			}
		}
		else {
			// 01 일경우
			if (str[i + 1] == '1') ++i;
			else return !printf("NOISE");
		}
	}

	printf("SUBMARINE");

	return 0;
}
