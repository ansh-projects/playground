#include <iostream>

using namespace std;

class C {
public:
	C() {i = 1; cout << "C0:" << i << endl;}

	C(int i0) {i = i0; cout << "C1:" << i << endl;}

	~C() {cout << "C2:" << i << endl;}
private:
	int i;
};

class D {
public:
	D() {cout << "D0" << endl;}
	~D() {cout << "D1" << endl;}
private:
	C c;
};

int main(int argc, char* argv[]) {
	cout << "X" << endl;
	D *d = new D;
	cout << "Y" << endl;

	delete d;
}
