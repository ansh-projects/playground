#include <iostream>
#include <string.h>

using namespace std;

int f(int n) {
	if (n < 0) {
		return -1;
	} else if (n == 0) {
		return 0;
	} else {
		return 1;
	}
}
int main(int argc, char* argv[]) {
	char a[10];
	char b[10];
	int n;

	strcpy(a, "");
	strcpy(b, "abc");

	n = strcmp(a, b);
	cout << f(n) << endl;
}
