#include <stdio.h>

int main() {
	float inp;
	scanf("%f", &inp);

	int cents = (int)(inp * 100 + 0.5);

	int currens[] = {
		10000,
		5000,
		2000,
		1000,
		500,
		200,
		100,
		50,
		25,
		10,
		5,
		1
	};

	const char* labels[] = {
		"NOTAS:\n",
		" nota(s) de R$ 100.00\n",
		" nota(s) de R$ 50.00\n",
		" nota(s) de R$ 20.00\n",
		" nota(s) de R$ 10.00\n",
		" nota(s) de R$ 5.00\n",
		" nota(s) de R$ 2.00\n",
		"MOEDAS:\n",
		" moeda(s) de R$ 1.00\n",
		" moeda(s) de R$ 0.50\n",
		" moeda(s) de R$ 0.25\n",
		" moeda(s) de R$ 0.10\n",
		" moeda(s) de R$ 0.05\n",
		" moeda(s) de R$ 0.01\n"
	};

	for (int i = 0, l = 0; i < 12; i++) {
		if (i == 0 || i == 6)
			printf("%s", labels[l++]);
		int cnt = cents / currens[i];
		cents %= currens[i];
		printf("%d%s", cnt, labels[l++]);
	}

	return 0;
}
