#include <iostream>

using namespace std;

class Calculator
{
protected:
	static double result_calcu;
	double a, b;

public:
	virtual void calcu() = 0;
	static double getResult()
	{
		return result_calcu;
	}
	
	static void resetResult()
	{
		result_calcu = 0;
	}
};

class Plus : public Calculator
{
public:
	Plus(double a, double b) : Calculator()
	{
		this->a = a;
		this->b = b;
	}

	void calcu() override
	{
		result_calcu = a + b;
		cout << " -------------------------------- " << endl;
		cout << " ��� : " << this->result_calcu << endl;
		cout << " -------------------------------- " << endl;

	}
};

class Minus : public Calculator
{
public:
	Minus(double a, double b) : Calculator()
	{
		this->a = a;
		this->b = b;
	}

	void calcu() override
	{
		result_calcu = a - b;
		cout << " -------------------------------- " << endl;
		cout << " ��� : " << this->result_calcu << endl;
		cout << " -------------------------------- " << endl;

	}
};

class Multi : public Calculator
{
public:
	Multi(double a, double b) : Calculator()
	{
		this->a = a;
		this->b = b;
	}

	void calcu() override
	{
		result_calcu = a * b;
		cout << " -------------------------------- " << endl;
		cout << " ��� : " << this->result_calcu << endl;
		cout << " -------------------------------- " << endl;

	}
};

class Divide : public Calculator
{
public:
	Divide(double a, double b) : Calculator()
	{
		this->a = a;
		this->b = b;
	}

	void calcu() override
	{
		if (b != 0)
		{
			result_calcu = a / b;
			cout << " -------------------------------- " << endl;
			cout << " ��� : " << this->result_calcu << endl;
			cout << " -------------------------------- " << endl;
		}
		else
		{
			cout << " -------------------------------- " << endl;
			cout << " 0���δ� ���� �� �����ϴ�. " << this->result_calcu << endl;
			cout << " -------------------------------- " << endl;
		}
		

	}
};

double Calculator::result_calcu = 0;

void calculator_main(double a, char op, double b)
{
	Calculator* cal = 0;

	switch (op)
	{
	case '+':
	{
		cal = new Plus(a, b);
		break;
	}

	case '-':
	{
		cal = new Minus(a, b);
		break;
	}

	case '*':
	{
		cal = new Multi(a, b);
		break;
	}

	case '/':
	{
		cal = new Divide(a, b);
		break;
	}

	default:
	{
		cout << " �߸� �Է��߽��ϴ�. �ٽ� �Է��ϼ��� " << endl;
		return;
	}
	}

	cal->calcu();
	delete cal;
}

void calculator_menu()
{
	while (1)
	{
		double a = 0;
		double b = 0;

		cout << " ���ڸ� �Է��ϼ��� : ";
		cin >> a;

		while (1)
		{
			char op;

			cout << " �����ڸ� �Է��ϼ��� : ";
			cin >> op;
			cout << " ���ڸ� �Է��ϼ��� : ";
			cin >> b;

			calculator_main(a, op, b);

			string andOp;
			cout << " �̾ ����Ͻðڽ��ϱ� ? (Y:�̾���, AC: �ʱ�ȭ, EXIT:����) ";
			cin >> andOp;

			if (andOp == "Y")
			{
				a = Calculator::getResult();
			}
			else if (andOp == "AC")
			{
				Calculator::resetResult();
				break;
			}
			else if (andOp == "EXIT")
			{
				return;
			}
		

		}
	}
	
}

int main()
{
	calculator_menu();

	return 0;
}
