#ifndef FRACTION_H
#define FRACTION_H
class Fraction {
	friend Fraction operator+ (Fraction f1, Fraction f2);
	public:
		Fraction(int n, int d = 1);
		Fraction();

		void Get();
		void Show();

		double Evaluate();
	private:
		int numerator,
		    denonminator;
};
#endif //FRACTION_H
