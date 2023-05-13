#include "pair.h"

Pair& Pair::operator *(const int a) {
	first *= a;
	second *= a;
	return *this;
}

Pair& Pair::operator -(const int a) {
	first -= a;
	return *this;
}

Pair& Pair::operator -(const double a) {
	second -= a;
	return *this;
}

Pair Pair::operator ==(const Pair& p) {
	if(this->first == p.first && this->second == p.second) return p;
	else return p;
}

Pair Pair::operator !=(const Pair& p) {
	if(this->first != p.first || this->second != p.second) return p;
	else return p;
}

istream& operator >>(istream& in, Pair& t) {
	cout << "int first = "; in >> t.first;
	cout << "double second = "; in >> t.second;
	return in;
}

ostream& operator <<(ostream& out, const Pair& t) {
	return (out << t.first << " : " << t.second << endl);
}



fstream& operator>>(fstream& fin, Pair& p) {
	fin >> p.first;
	fin >> p.second;
	return fin;
}

fstream& operator<<(fstream& fout, const Pair& p) {
	fout << p.first << "\n" << p.second << "\n";
	return fout;
}

bool Pair::operator <(int p) {
	double th = (*this).first + (*this).second;
	if (th < p) return true;
	return false;
}
bool Pair::operator >(int p) {
	double th = (*this).first + (*this).second;
	if (th > p) return true;
	return false;
}