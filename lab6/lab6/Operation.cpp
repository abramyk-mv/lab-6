#include "StdAfx.h"
#include "Operation.h"
#include <vector>
#include "Atom.h"
using namespace std;

COperation::COperation(void){}
COperation::~COperation(void){}

double COperation::Plus(const vector<CAtom*> args) // операція +
{
	double result = 0;
	for (int i = 0; i < args.size(); i++)
	{
		result += atof(args[i]->GetAtom().c_str());
	}
	return result;
}

double COperation::Minus(const vector<CAtom*> args) // операція -
{
	double result = 0;
	for (int i = 0; i < args.size(); i++)
	{
		result -= atof(args[i]->GetAtom().c_str());
	}
	return result;
}

double COperation::Multiplication(const vector<CAtom*> args) // операція *
{
	double result = 0;
	for (int i = 0; i < args.size(); i++)
	{
		result *= atof(args[i]->GetAtom().c_str());
	}
	return result;
}

double COperation::Division(const vector<CAtom*> args) //  операція /
{
	double result = 0;
	for (int i = 0; i < args.size(); i++)
	{
		result /= atof(args[i]->GetAtom().c_str());
	}
	return result;
}