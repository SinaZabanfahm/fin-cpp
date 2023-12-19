/*
 * NonLinearSolver.cpp
 *
 *  Created on: Dec. 18, 2023
 *      Author: sinazabanfahm
 */

#include<iostream>
#include<cassert>
#include "NonLinearSolver.hpp"
#include<cmath>
using namespace std;


//constructor:


//deconstructor::
NonLinearSolver::~NonLinearSolver(){

}

/**
 * BisectSolver Class
 */

//Constructor
BisectSolver::BisectSolver( double lleft, double rright, long nn, double (*func)(double x), double ttol){
	init( lleft, rright, nn, func,ttol);
}
//Destructor
BisectSolver::~BisectSolver(){}
//Kernel Functions:
double BisectSolver::solve(){
	long index = 0;
	double mid = 0;
	if (left  > right || (myFunc(left) * myFunc(right)>=0)){
		return -INFINITY;
	}
	while (index>0 && right - left > tol){
		mid = (right + left)/2;
		if (checkSigns(left,mid)){
			right = mid;
		}
		else{
			left = mid;
		}
		index++;
	}
	return mid;
}
//Helper Functions:
void BisectSolver::init(double lleft, double rright, long nn, double (*func)(double x), double ttol){
	assert(left<=right);
	left = lleft;
	right = rright;
	n = nn;
	myFunc = func;
	ttol = tol;

}

bool BisectSolver::checkSigns(double l , double r) const{
	return (myFunc(l)*myFunc(r) <= 0);
}


/*
 * SecantSolver Class
 */

//Constructor
SecantSolver::SecantSolver(double xxprev, double xxcur, long nn, double(*func)(double x), double ttol){
	init( xxprev, xxcur, nn, func, ttol);
}


//Destructor

SecantSolver::~SecantSolver(){}

//Kernek functions:
double SecantSolver::solve(){
	long index = 1;
	double inc;
	double tmp;
	double x1 = xcur;
	double x0 = xprev;
	while(abs(x1 - x0)>tol and index <=n){
		inc = nextInc(x1,x0);
		tmp = x1;
		x1 = x1 - inc;
		x0 =tmp;
		index++;
	}

	return x1;
}

//Helper Function

void SecantSolver::init(double xxprev, double xxcur, long nn, double(*func)(double x), double ttol){
	xprev = xxprev;
	xcur = xxcur;
	n = nn;
	myFunc = func;
	tol = ttol;
}

double SecantSolver::nextInc(double x1, double x0) const{
	if ((myFunc(x1) - myFunc(x0))== 0 ){
		return 0;
	}
	return myFunc(x1)*(x1 - x0)/(myFunc(x1) - myFunc(x0));
}



/**
 * SteffensesnSolver Class:
 */

//Constructor
SteffensenSolver::SteffensenSolver(double xxcur, long nn, double(*func)(double x), double ttol ){
	init(xxcur, nn, func, ttol);
}

//Destructor
SteffensenSolver::~SteffensenSolver(){}

//Kernel Functions
double SteffensenSolver::solve(){
	double x = xcur;
	double inc = INFINITY;
	long index = 1;
	while (index < n && abs(inc)>tol){
		inc = nextInc(x);
		x = x - inc;
		index++;
	}
	return x;
}
//Helper Functions
void SteffensenSolver::init(double xxcur, long nn, double(*func)(double x), double ttol ){
	xcur = xxcur;
	n = nn;
	myFunc = func;
	tol = ttol;
}

double SteffensenSolver::nextInc(double x) const{
	if (myFunc(x) == 0){
		return 0;
	}
	double g = (myFunc(x + myFunc(x)) - myFunc(x))/myFunc(x);
	if (g == 0){
		return 0;
	}
	return myFunc(x)/g;
}

