#ifndef EMPLOYEE_H
#define EMPLOYEE_H

class Employee {
	public:
		virtual void PrintCheck() = 0;
	protected:
		float netPay;
		Employee();
		Employee(char *n, char *a, char *sn);
		char name[30];
		char address[80];
		char socSecNumber[10];
};

class Temporary: public Employee {
	public:
		Temporary(char *n, char *a, char *ssn, float hw, float hr);
		Temporary();
		void PrintCheck();
	private:
		float hoursWorked;
		float hourlyRate;
};

class Permanent: public Employee {
	public:
		static float benefitDeduction;
	protected:
		Permanent(char *n, char *a, char *ssn);
		Permanent();
		void PrintCheck() = 0;
};

class Hourly : public Permanent {
	public:
		Hourly(char *n, char *a, char *ssn, float hw, float hr);
		Hourly();
		void PrintCheck();
	private:
		float hoursWorked;
		float hourlyRate;
};

class Salaried: public Permanent {
	public:
		Salaried(char *n, char *a, char *ssn, float wp);
		Salaried();
		void PrintCheck();
	private:
		float weeklyPay;
};

#endif //EMPLOYEE_H
