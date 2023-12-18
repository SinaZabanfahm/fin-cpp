/*
 * BondPricing.cpp
 *
 *  Created on: Dec. 18, 2023
 *      Author: sinazabanfahm
 */

#include "BondPricing.hpp";
#include<vector>
#include<cmath>
#include<string>
#include<cassert>
using namespace std;

double BondPricing::futureValue(double V, long n, double r){
	return V * pow(1+r,n);
}

double BondPricing::futureValue(double V, long n, double r, long m){
	if (m==0){
		return INFINITY;
	}
	return V * pow(1+r/m,n*m);
}

double BondPricing::futureValueCont(double V, long t, double r){
	return V* exp(r*t);
}

double BondPricing::fvOrdinaryAnnuity(double pmt, long n, double r){
	return pmt *(pow(1+r, n) - 1 )/r;
}

double BondPricing::presentValue(double V,long n, double r){
	return V * pow(1+r,-n);
}

double BondPricing::pvOrdinaryAnnuity(double pmt,long n,double r){
	return pmt * (1 - 1/pow(1+r,n))/r;
}

double BondPricing::pvSeriesPayments(const vector<double>& pmts,long n,double r){
	assert(n == pmts.size());
	double pv = 0;
	for (long i=0; i < n;i++){
		pv += pmts[i]/pow(1+r,i+1);
	}
	return pv;
}


