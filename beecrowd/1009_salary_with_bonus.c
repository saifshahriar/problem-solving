#include <stdio.h>

int main() {
	char   seller[100];
	double fixed_salary, sales_total;
	scanf("%s %lf %lf", seller, &fixed_salary, &sales_total);

	double total_salary = fixed_salary + sales_total * 0.15;
	printf("TOTAL = R$ %0.2lf\n", total_salary);
	return 0;
}
