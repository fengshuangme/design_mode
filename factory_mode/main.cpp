#include <iostream>
using namespace std;
//base
class COperation
{
public:
	int m_nFirst;
	int m_nSecond;
	virtual double GetResult()
	{
		double dResult = 0;
		return dResult;
	}
};

//factory class
class CCalculatorFactory
{
public:
	static COperation* Create (char cOperator);
};
class AddOperation :public COperation
{
public:
	virtual double GetResult()
	{
		return m_nFirst + m_nSecond;
	}
};

class SubOperation :public COperation
{
public:
	virtual double GetResult()
	{
		return m_nFirst - m_nSecond;
	}
};

class MulOperation :public COperation
{
public:
	virtual double GetResult()
	{
		return m_nFirst * m_nSecond;
	}
};


COperation* CCalculatorFactory::Create(char cOperator)
{
	COperation* oper=NULL;
	switch (cOperator)
	{
	case '+':
		oper = new AddOperation();
		break;
	case '-':
		oper = new SubOperation();
		break;
	case '*':
		oper = new MulOperation();
		break;
	default:
		break;
	}
	return oper;
}
int main()
{
	int a, b;
	cin >> a >> b;
	COperation* op = CCalculatorFactory::Create('-');
	op->m_nFirst = a;
	op->m_nSecond = b;
	cout << op->GetResult() << endl;
	return 0;

}
