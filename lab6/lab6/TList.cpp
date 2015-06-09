#include "StdAfx.h"
#include "TList.h"
#include "Operation.h"
#include "Atom.h"
#include "Atom_Number.h"
#include "Atom_Operation.h"
#include "Atom_String.h"
#include "sstream"
#include "iostream"
using namespace std;

double Plus(const vector<CAtom*> args)
{
	double result = 0;
	for (int i = 0; i < args.size(); i++)
	{
		result += atof(args[i]->GetAtom().c_str());
	}
	return result;
}
//- 
double Minus(const vector<CAtom*> args)
{
	double result = atof(args[0]->GetAtom().c_str());;
	for (int i = 1; i < args.size(); i++)
	{
		result -= atof(args[i]->GetAtom().c_str());
	}
	return result;
}
//*
double Multiplication(const vector<CAtom*> args)
{
	double result = atof(args[0]->GetAtom().c_str());
	for (int i = 1; i < args.size(); i++)
	{
		result *= atof(args[i]->GetAtom().c_str());
	}
	return result;
}
// /
double Division(const vector<CAtom*> args)
{
	double result = atof(args[0]->GetAtom().c_str());;
	for (int i = 1; i < args.size(); i++)
	{
		result /= atof(args[i]->GetAtom().c_str());
	}
	return result;
}

void Eg(const vector<CAtom*> args)
{
	double leftArg = atof(args[0]->GetAtom().c_str());
	double rightArg = atof(args[1]->GetAtom().c_str());
	if (leftArg == rightArg)
	{
		cout << " " << "T";
	}
	else
	{
		cout << " " << "NIL";
	}
}

void NotEg(const vector<CAtom*> args)
{
	double leftArg = atof(args[0]->GetAtom().c_str());
	double rightArg = atof(args[1]->GetAtom().c_str());
	if (leftArg != rightArg)
	{
		cout << " " << "T";
	}
	else
	{
		cout << " " << "NIL";
	}
}

void Less(const vector<CAtom*> args)
{
	double leftArg = atof(args[0]->GetAtom().c_str());
	double rightArg = atof(args[1]->GetAtom().c_str());
	if (leftArg < rightArg)
	{
		cout << " " << "T";
	}
	else
	{
		cout << " " << "NIL";
	}
}

void Over(const vector<CAtom*> args)
{
	double leftArg = atof(args[0]->GetAtom().c_str());
	double rightArg = atof(args[1]->GetAtom().c_str());
	if (leftArg > rightArg)
	{
		cout << " " << "T";
	}
	else
	{
		cout << " " << "NIL";
	}
}

CTList::CTList(string code)
{
	expressionList = code;
};

CTList::~CTList(void)
{
};

string CTList::Run()
{
	string result;
	if (expressionList != "")
	{
		CTList::ParseExpressionList(expressionList);
		ostringstream buff;
		buff << Method();
		result = buff.str();
	}
	else
	{
		cout << " " << "NIL";
		result = "NIL";
	}
	return result;
}

void CTList::Show()
{
	CTList::ParseExpressionList(expressionList);
	if (expressionList == "")
	{
		cout << "List - " << "NIL" << endl;
	}
	else
	{
		cout << "List - " << expressionList << endl;
		operation->ShowAtom();
		for (int i = 0; i < atomsArg.size(); i++)
		{
			atomsArg[i]->ShowAtom();
		}

		for (int i = 0; i < lists.size(); i++)
		{
			lists[i]->Show();
		}
	}
}

void CTList::ParseExpressionList(string expression)
{
	if (expression != "")
	{
		string* temp = new string(expression);
		CTList::SetOperation(*temp);
		CTList::SetAtoms(*temp);
	}
}

int CTList::GetIndex(string& expression, int startIndex)
{
	bool flag = true;
	int result = 0;
	int index = startIndex;
	int countOpen = 1;
	int countClose = 0;
	while (flag)
	{
		index += 1;
		if (expression[index] == '(')
		{
			countOpen += 1;
		}
		if (expression[index] == ')')
		{
			countClose += 1;
		}

		if (countOpen == countClose)
		{
			flag = false;
			result = index;
		}
	}
	return result;
}

void CTList::SetAtoms(string& expression)
{
	int index = -1;
	string temp;
	bool flag = true;

	while (flag){
		index += 1;
		if (expression[index] == '(')
		{
			int tempIndex = CTList::GetIndex(expression, index);
			temp = expression.substr(index, tempIndex - index + 1);
			index = tempIndex;
			if (temp == "()")
			{
				temp = "";
			}
			lists.push_back(new CTList(temp));
			temp = "";
		}
		else
		{
			if (index == expression.length() - 1 || expression[index] != ' ')
			{
				temp += expression[index];
			}
			if ((expression[index] == ' ' || index == expression.length() - 1) && temp != "")
			{
				CAtom* atom;
				if (CTList::is_number(temp))
				{
					atom = new CAtom_Number();
				}
				else
				{
					atom = new CAtom_String();
				}
				atom->SetAtom(temp);
				atomsArg.push_back(atom);
				temp = "";
			}
		}
		if (index >= expression.length() - 1)
		{
			flag = false;
		}
	}
}

bool CTList::is_number(const string& line)
{
	return (atoi(line.c_str()));
}

double CTList::Method()
{
	for (int i = 0; i < lists.size(); i++)
	{
		string tempResult = lists[i]->Run();
		if (tempResult != "NIL")
		{
			CAtom* temp = new CAtom_Number();
			temp->SetAtom(tempResult);
			atomsArg.push_back(temp);
		}
	}
	double result = executeMethod(atomsArg);
	return result;
}

void CTList::SetOperation(string& expression)
{
	bool flag = true;
	int i = -1;
	while (flag)
	{
		i += 1;
		switch (expression[i])
		{
		case '+':
			//method = &COperation::Plus;
			operation = new CAtom_Operation();
			operation->SetAtom("+");
			executeMethod = Plus;
			flag = false;
			break;

		case '-':
			//method = &COperation::Minus;
			operation = new CAtom_Operation();
			operation->SetAtom("-");
			executeMethod = Minus;
			flag = false;
			break;

		case '*':
			//method = &COperation::Multiplication;
			operation = new CAtom_Operation();
			operation->SetAtom("*");
			executeMethod = Multiplication;
			flag = false;
			break;

		case '/':
			//method = &COperation::Division;
			operation = new CAtom_Operation();
			operation->SetAtom("/");
			executeMethod = Division;
			flag = false;
			break;
		}
	}
	expression = expression.replace(0, i + 2, "");
	expression = expression.substr(0, expression.length() - 1);
}