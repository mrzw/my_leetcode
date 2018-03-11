#include <iostream>
#include <string>
#include <sstream>
using namespace std;

string num2str(double i) {
	stringstream ss;
	ss << i;
	return ss.str();
}
double str2num(string s) {
	double num;
	stringstream ss(s);
	ss >> num;
	return num;
}
