#include "Quadratic.h"


using namespace std;

int main() {
	cout << """This programme is demonstrating the use of the QuadraticF class. \nThis class can be used to manipulate univariate quadratic funcitons between three different forms; \nStandard: (ax^2+bx+c), Factored: a(x-R1)(x-R2) and Vertex: a(x-h)^2+k\n""";
	cout << "An object of the QuadraticF class takes 4 arguments, a single character S,F or V \nto dictate the form of the function (Standard, Factored or Vertex), followed by the three values.\n";
	cout << "For example ('S', 1, 2, 3) or ('V', 1, 2, 3) or ('F',1 ,2 ,3)\n\n";


	cout << "******* Q1 Demonstrating the class and member function created: *******" << endl;
	QuadraticF Quad('v', -4, 0, 36);
	cout << "Below is a demonstration of an object of the class QuadraticF originally \ncreated in vertex form with values a = -4, h = 0, k = 36.\nIt shows the values of each form of the function as follows:\n";
	cout << "Standard: a, b, c\n";
	cout << "Factored : a, R1, R2\n";
	cout << "Vertex : a, h, k\n\n";

	cout << "The methods GetStandard(), GetFactored() and GetVertex() are used to \ndisplay the values of each form to the terminal as follows.\n\n";
	cout << "GetStandard() outputs:\n";
	Quad.GetStandard();
	cout << "\n";
	cout << "GetFactored() outputs:\n";
	Quad.GetFactored();
	cout << "\n";
	cout << "GetVertex() outputs:\n";
	Quad.GetVertex();
	cout << "\n\n";

	cout << "The individual values of the standard form funciton can be modified with the methods:\n";
	cout << "ModStandardA(), ModStandardB()and ModStandardC() which all take a single argument of type double.\n";

	Quad.ModStandardA(2);
	cout << "\nFollowing modifaction of variable a in standard form to 2 using ModStandardA(2): " << endl;
	Quad.GetStandard();
	cout << "\n";
	Quad.GetFactored();
	cout << "\n";
	Quad.GetVertex();
	cout << "\n";

	Quad.ModStandardB(5);
	cout << "\nFollowing modifaction of variable b in standard form to 5 using ModStandardB(5): " << endl;
	Quad.GetStandard();
	cout << "\n";
	Quad.GetFactored();
	cout << "\n";
	Quad.GetVertex();
	cout << "\n";

	Quad.ModStandardC(10);
	cout << "\nFollowing modifaction of variable c in standard form to 10 using ModStandardC(10): " << endl;
	Quad.GetStandard();
	cout << "\n";
	Quad.GetFactored();
	cout << "\n";
	Quad.GetVertex();
	cout << "\n";
	cout << endl;


	cout << "******* Q2 Demonstrating the Display functions created: *******" << endl;
	QuadraticF Quad0('S', 1, 2, 2);
	cout << "This section demonstrates the use of member functions \nthat can be used to display the separate forms of the univariate function\n\n";
	cout << "Following the creation of an object in the standard form with values: a = 1, b = 2, c = 2\n\n";
	cout << "The method DispStandard() will display the standard form in the terminal as:\n";
	Quad0.DispStandard();
	cout << "\n\n"; 

	cout << "The method DispFactored() will display the factored form in the terminal as:\n";
	Quad0.DispFactored();
	cout << "\n\n";

	cout << "The method DispVertex() will display the vertex form in the terminal as:\n";
	Quad0.DispVertex();
	cout << "\n\n";

	cout << "The method DispAll() will display all of the forms, equating them to each other as:\n";
	Quad0.DispAll(); 
	cout << "\n\n";


	cout << "******* Q3 Demonstrating the reading of the text file: *******" << endl;
	cout << "This section demonstrates the use of the function GetFunctionsFromFile. \nThis function takes two arguments, the first being a vector of QuadraticF \nobjects and the second being the file contating the list of funcitons.\n";
	cout << "This function stores all the functions in the file in this vector.\n\n";
	cout << "As a demonstration this is all of the functions contained in the file FunctionList.txt \ndisplayed using the DisplayAll() method:\n\n";
	vector<QuadraticF> FuncList;
	GetFunctionsFromFile(FuncList,"FunctionList.txt");

	for (auto i = 0; i < FuncList.size(); i++) {
		FuncList[i].DispAll();
		cout << endl;
	}
	cout << "\n";


	cout << "******* Q4 Demonstrating the overloaded operators: *******" << endl;
	cout << "The class also has two operators. Two separate objects can be added together \nusing + to give the sum of the two functions. \nAn object can also be multiplied by an integer, the integer must proceed the \nfunction and the operator * is used to multiply the object by the integer.\n\n";
	QuadraticF Quadly;
	for (auto i = 0; i < FuncList.size(); i++) {
		Quadly = Quadly + FuncList[i];
	}
	cout << "For example the sum of all of the functions in the FunctionList.txt file is:\n";
	Quadly.DispAll();
	Quadly = 4 * Quadly;
	cout << "\n\nAnd the multiplication of these functions by the integer 4 gives:\n";
	Quadly.DispAll();
	cout << "\n\n";
	return 0;
	
}