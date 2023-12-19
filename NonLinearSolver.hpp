/*
 * NonLinearSolver.hpp
 *
 *  Created on: Dec. 18, 2023
 *      Author: sinazabanfahm
 */

#ifndef NONLINEARSOLVER_HPP_
#define NONLINEARSOLVER_HPP_

class NonLinearSolver{
public:
	double (*myFunc)(double x);
	double tol;

public:
	//constructor:
	NonLinearSolver(){};
	virtual ~NonLinearSolver();
public:
	//Kernel Functions
	virtual double solve() = 0;
private:
	//helper function

};


/**
 * BisectSolver derived from NonLinearSolver,
 * Finds the zeros of a continuous function using bisection.
 */
class BisectSolver : public NonLinearSolver{
private:
	double left, right;
	long n;
public:
	//Constructor
	BisectSolver(double left, double right, long n, double (*func)(double x), double ttol);
	virtual ~BisectSolver();
public:
	//kernel functions:
	virtual double solve() override;
private:
	//Helper Function:
	bool checkSigns(double l, double r) const;
	void init(double left, double right, long n, double (*func)(double x), double ttol);
};


/**
 * SecantSolver derived from NonLinearSolver
 * Finds the zeros of a continuous function using the secant method
 */

class SecantSolver: public NonLinearSolver{
private:
	double xprev, xcur;
	long n;

public:
	//Constructor
	SecantSolver(double xxprev, double xxcur, long nn, double(*func)(double x), double ttol);
	//Destructor
	virtual ~SecantSolver();
public:
	//Kernel functions
	virtual double solve() override;
private:
	//Helper Functions:
	void init(double xxprev, double xxcur, long nn, double(*func)(double x), double ttol);
	double nextInc(double x0, double x1) const;
};


class SteffensenSolver: public NonLinearSolver{
private:
	double xcur;
	long n;

public:
	//Constructor
	SteffensenSolver(double xxcur, long nn, double(*func)(double x), double ttol );
	//Destructor
	virtual ~SteffensenSolver();
public:
	//Kernel Function
	virtual double solve() override;
private:
	//Helper Functions
	void init(double xxcur, long nn, double(*func)(double x), double ttol);
	double nextInc(double x) const;
};
#endif /* NONLINEARSOLVER_HPP_ */


