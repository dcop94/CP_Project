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
		cout << " 결과 : " << this->result_calcu << endl;
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
		cout << " 결과 : " << this->result_calcu << endl;
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
		cout << " 결과 : " << this->result_calcu << endl;
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
			cout << " 결과 : " << this->result_calcu << endl;
			cout << " -------------------------------- " << endl;
		}
		else
		{
			cout << " -------------------------------- " << endl;
			cout << " 0으로는 나눌 수 없습니다. " << this->result_calcu << endl;
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
		cout << " 잘못 입력했습니다. 다시 입력하세요 " << endl;
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

		cout << " 숫자를 입력하세요 : ";
		cin >> a;

		while (1)
		{
			char op;

			cout << " 연산자를 입력하세요 : ";
			cin >> op;
			cout << " 숫자를 입력하세요 : ";
			cin >> b;

			calculator_main(a, op, b);

			string andOp;
			cout << " 이어서 계산하시겠습니까 ? (Y:이어계산, AC: 초기화, EXIT:종료) ";
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
