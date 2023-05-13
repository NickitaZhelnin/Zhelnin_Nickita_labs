#include <iostream>
using namespace std;

class Pair {
public:
	int first;
	double second;
	Pair() { first = 0;	second = 0; };
	Pair(int F, double S) { first = F; second = S; };
	Pair(const Pair& t) { first = t.first;second = t.second; };
	~Pair() {};
	Pair operator =(const Pair&);
	bool operator <(const Pair&) const;
	bool operator >(const Pair&) const;
	Pair& operator /(const int X);
};

Pair& Pair::operator /(const int X) {
	first = first / X;
	second = second / X;
	return *this;
}

Pair Pair::operator =(const Pair& p) {
	if (&p == this) return *this;
	first = p.first;
	second = p.second;
	return*this;
}

bool Pair::operator <(const Pair& p) const {
	double sthis = this->first + this->second;
	double sother = p.first + p.second;
	if (sthis < sother) return true;
	return false;
}

bool Pair::operator >(const Pair& p) const {
	double sthis = this->first + this->second;
	double sother = p.first + p.second;
	if (sthis > sother) return true;
	return false;
}
