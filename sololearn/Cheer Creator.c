#include <stdio.h>

int main() {
	int yard;

	scanf("%d", & yard);

	if (yard < 1) printf("shh");
	else if (yard > 10) printf("High Five");
	else if (yard > 0 && yard < 11) {
		while (yard > 0) {
			printf("Ra!");
			yard--;
		}
	}
	return 0;
}

/*
You are cheering on your favorite team. After each play, if your team got over 10 yards further down the field, you stand up and give your friend a high five. If they don't move forward by at least a yard you stay quiet and say 'shh', and if they move forward 10 yards or less, you say 'Ra!' for every yard that they moved forward in that play.

Task
Given the number of yards that your team moved forward, output either 'High Five' (for over 10), 'shh' (for <1), or a string that has a 'Ra!' for every yard that they gained.

Input Format
An integer value that represents the number of yards gained or lost by your team.

Output Format
A string of the appropriate cheer.

Sample Input
3

Sample Output
Ra!Ra!Ra!
*/
