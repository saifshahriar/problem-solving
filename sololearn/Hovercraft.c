//Input the number of hovercrafts that were sold that month.

#include <stdio.h>

int main() {
	int nh, cost, sell;; 					// nh = number of hovercrafts that were sold that month.

	scanf("%d", & nh);

	cost = (10 * 2000000) + 1000000;
	sell = nh * 3000000;

	if (nh <= 10 && sell > cost) printf("Profit");
	else if (nh <= 10 && sell < cost) printf("Loss");
	else if (sell == cost) printf("Broke Even");
	else printf("You can only make 10 upto hovercrafts in a month.");

	return 0;
}

/*

*** Problem Link: https://www.sololearn.com/coach/42?ref=app


*** Problem:

* You run a hovercraft factory. Your factory makes ten hovercrafts in a month. Given the number of customers you got that month, did you make a profit? It costs you 2,000,000 to build a hovercraft, and you are selling them for 3,000,000. You also pay 1,000,000 each month for insurance.

* Task:
Determine whether or not you made a profit based on how many of the ten hovercrafts you were able to sell that month.

* Input Format:
An integer that represents the sales that you made that month.

* Output Format:
A string that says 'Profit', 'Loss', or 'Broke Even'.

* Sample Input:
5

* Sample Output:
Loss
*/
