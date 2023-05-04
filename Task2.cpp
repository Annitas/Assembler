
#include <iostream>
using namespace std;

double funcTwo(double x, double epsilon = 1e-18) {
	double m = 1.0/3.0;
	double suma = 1.0;
	__asm {
		finit
		fld qword ptr epsilon
		fld qword ptr m
		fldz
		fld qword ptr x
		fld1
		fld1
		fld1
		faddp st(4), st(0)
		WHILE:
			fmul st(0), st(2)
			fmul st(0), st(4)
			fdiv st(0), st(1)
			fld st(0)
			fabs
			fcomp st(6)
			fstsw ax
			sahf
			jb FIN
			fadd st(3), st(0)
			fld1
			fsubp st(5), st(0)
			fld1
			faddp st(2), st(0)
			jmp WHILE
		FIN:
			fld st(3)
	}
}

int main() {
	double x = 0.75;
	double result = funcTwo(0.5);
	cout << result << endl;
	cout << pow(x + 1, 1.0/3.0);
}
