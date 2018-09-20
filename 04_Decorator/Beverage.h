#pragma once
#include <string>
using namespace std;

class Beverage
{
	string des;
public:

	Beverage() : des( "Unknown" ) { }
	Beverage( string s ) : des( s ) { }

	virtual string getDescription() { return this->des; };
	virtual float cost() = 0;
};