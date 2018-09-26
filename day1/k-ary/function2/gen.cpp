#include <bits/stdc++.h>

using namespace std;

int rand(int l, int r)
{
	int len = r - l + 1;
	return l + rand() % len;
}

int randk()
{
	if (rand() % 5 == 0) return rand();
	return rand() % 100;
}

int main()
{
	srand(time(NULL));
	int T = 20;

	cout << T << endl;

	int small = T - 3;
	for (int i = 0; i < small; i++) printf("%d %d\n", rand(1, 3000), randk());

	for (int i = small; i < T; i++) {
		printf("%d %d\n", rand(40000, 60000), randk());
	}

	return 0;
}