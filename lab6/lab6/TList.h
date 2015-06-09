#pragma once
#include <vector>
#include "Atom.h"
#include "Operation.h"
#include "stdafx.h"
using namespace std;
typedef double(*functionPtr)(const vector<CAtom*>);

class CTList
{
public:
	CTList(string);
	~CTList(void);
	string Run();
	void Show();
	void ParseExpressionList(string expression);
	double Method();

private:
	bool is_number(const string& s);
	void SetOperation(string& expression);
	void SetAtoms(string& expression);
	int CTList::GetIndex(string& expression, int startIndex);

	functionPtr executeMethod;
	CAtom* operation;
	string expressionList;
	vector<CAtom*> atomsArg;
	vector<CTList*> lists;
};

