#include "Quadratic.h"



QuadraticF::QuadraticF(char Form, double Term1, double Term2, double Term3) : a(0), b(0), c(0), R1((0, 0)), R2((0, 0)), h(0), k(0) {
	if (Form == 'S' || Form == 's') {
		a = Term1;
		b = Term2;
		c = Term3;
		
		//Calculate vertex values
		CalcHfromStand();
		CalcKfromStand();

		//Calculate factored values
		CalcR1fromStand();
		CalcR2fromStand();
	}
	else if (Form == 'F' || Form == 'f') {
		a = Term1;
		R1 = Term2;
		R2 = Term3;

		//Calculate factored values
		CalcBfromFactor();
		CalcCfromFactor();
		
		//Calculate standard form values
		CalcHfromStand();
		CalcKfromStand();
	}
	else if (Form == 'V' || Form == 'v') {
		a = Term1;
		h = Term2;
		k = Term3;

		//Caculate vertex values
		CalcBfromVert();
		CalcCfromVert();

		//Calculate factored values
		CalcR1fromStand();
		CalcR2fromStand();
	}
}

void QuadraticF::GetFactored(){
	//If statement to catch real/imaginary values
	if (R1.imag() == 0) cout << "Factored: " << a << ", " << R1.real() << ", " << R2.real() ;
	else {
		
		cout << "Factored: " << a << ", " << R1.real() << "+" << abs(R1.imag()) <<"i, " << R1.real() << "-" << abs(R2.imag()) << "i";
	}
}

void QuadraticF::CalcHfromStand() {
	if (b == 0) h = 0;
	else h = -b / (2 * a);
}

void QuadraticF::ModStandardA(double A) {
	a = A;
	
	//Calculate and modify member attributes of vertex values 
	CalcHfromStand();
	CalcKfromStand();

	//CCalculate and modify member attributes of factored values
	CalcR1fromStand();
	CalcR2fromStand();
}
void QuadraticF::ModStandardB(double B) {
	b = B;

	//Calculate and modify member attributes of vertex values
	CalcHfromStand();
	CalcKfromStand();

	//Calculate and modify member attributes of factored values
	CalcR1fromStand();
	CalcR2fromStand();
}
void QuadraticF::ModStandardC(double C) {
	c = C;

	//Calculate and modify member attributes of vertex values
	CalcHfromStand();
	CalcKfromStand();

	//Calculate and modify member attributes of factored values
	CalcR1fromStand();
	CalcR2fromStand();
}
void  QuadraticF::DispStandard() {
	//Create strings of standard form values 
	ostringstream A, B, C;
	string func;
	A << a;
	B << b;
	C << c;
	//Handle a values
	if (a == 1)func+= "x^2";
	else if (a != 0) func += A.str() + "x^2";
	//Handle b values
	if (b < 0)func += B.str() + "x";
	else if (b == 1) func += "+x";
	else if (b>0) func += "+" + B.str() + "x";
	//Handle c values
	if (c < 0) func += C.str();
	else if (c>0) func+= "+" + C.str();
	cout << func;

}
void QuadraticF::DispFactored() {
	//Display factored form of function
	if (a == 1)cout << "(x";
	else if (a != 0) cout << a << "(x";
	else return;
	//First if statement to ascertain if the roots of the function are real 
	if (R1.imag() == 0) {
		if (R1.real() == 0) {
			if (R2.real() > 0)cout << ")(x-" << R2.real() << ")";
			else if (R2.real() < 0) cout << ")(x+" << abs(R2.real()) << ")";
			else cout << ")^2";
			return;
		}
		else if (R1.real() < 0) {
			cout << "+" << -R1.real() << ")(x";
			if (R2.real() > 0) cout << "-" << R2.real() << ")";
			else if (R2.real() < 0) cout << "+" << abs(R2.real()) << ")";
			else cout << ")";
			return;
		}
		else if (R1.real() > 0) {
			cout << "-" << R1.real() << ")(x";
			if (R2.real() > 0) cout << "-" << R2.real() << ")";
			else if (R2.real() < 0) cout << "+" << abs(R2.real()) << ")";
			else cout << ")";
			return;
		}
	}

	//Handling of imaginary roots of funciton
	else {
		if (R1.real() == 0) {
			if (abs(R1.imag())!=1) cout << "-" << abs(R1.imag()) << "i)(x+" << abs(R1.imag()) << "i)";
			else cout << "-i)(x+i)";
		}
		else if (R1.real() < 0) {
			if (abs(R1.imag()) != 1) cout << "+" << -R1.real() << "-" << abs(R1.imag()) << "i)(x+" << -R1.real() << "+" << abs(R1.imag()) << "i)";
			else cout << "+" << -R1.real() << "-i)(x+" << -R1.real() << "+i)";
		}
		else {
			if (abs(R1.imag()) != 1) cout << "-" << R1.real() << "-" << abs(R1.imag()) << "i)(x-" << R1.real() << "+" << abs(R1.imag()) << "i)";
			else cout << "-" << R1.real() << "-i)(x-" << R1.real() << "+i)";
		}
	}
}
void  QuadraticF::DispVertex() {
	//Display vertex form of function

	//Manage a values
	if (a == 1)cout << "(x";
	else if (a != 0) cout << a << "(x";
	else return;

	//Manage h values
	if (h == 0) cout << ")^2";
	else if (h < 0) cout << "+" << -h << ")^2";
	else cout << "-" << h << ")^2";

	//Manage k values
	if ( k < 0) cout << k;
	else if (k > 0) cout << "+" << k;
}
void QuadraticF::DispAll() {
	//Display all forms of function
	cout << "f(x)=";
	DispStandard();
	cout << "=";
	DispFactored();
	cout << "=";
	DispVertex();
}

void GetFunctionsFromFile(vector<QuadraticF>& FuncList, string FileName) {
	//Create objects from function values stated in file and append to vector
	ifstream DataFile(FileName);
	if (!DataFile.fail()) {
		char type;
		double t1, t2, t3;
		while (DataFile >> type) {
			DataFile >> t1;
			DataFile >> t2;
			DataFile >> t3;
			QuadraticF NewFunc(type, t1, t2, t3);
			FuncList.push_back(NewFunc);
		}
	}
}

//Multiplication of an object by an integer
QuadraticF operator* (int number, const QuadraticF& function) { return QuadraticF('S', number * function.a, number * function.b, number * function.c); }