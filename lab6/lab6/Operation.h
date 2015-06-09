#pragma once
#include <vector>
#include "Atom.h"
using namespace std;

class COperation
{
public:
	COperation(void);
	~COperation(void);
	//+ 
	double Plus(const vector<CAtom*>);
	//- 
	double Minus(const vector<CAtom*>);
	//*
	double Multiplication(const vector<CAtom*>);
	// /
	double Division(const vector<CAtom*>);
};

