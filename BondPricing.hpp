/*
 * BondPricing.hpp
 *
 *  Created on: Dec. 18, 2023
 *      Author: sinazabanfahm
 */

#ifndef BONDPRICING_HPP_
#define BONDPRICING_HPP_
#include<string>
#include<cmath>
#include<vector>
using namespace std;

namespace BondPricing
{

	//Future Value - Compounding interest for n - periods
	double futureValue(double V, long n, double r);

	//Future Value - Compounding interest for n - periods, times per periods is denoted by m
	double futureValue(double V, long n, double r, long m);
	//Future Value - Continuous Compounding
	double futureValueCont(double V, long t, double r);

	//Future Value - Ordinary annuity:
	double fvOrdinaryAnnuity(double pmt, long n, double r);

	//Present Value - Single payment
	double presentValue(double V, long n, double r);
	//Present Value - Ordinary annuity
	double pvOrdinaryAnnuity(double pmt, long n, double r);
	//Present Value - Series of Payments

	double pvSeriesPayments(const vector<double>& pmts, long n, double r);
}
#endif /* BONDPRICING_HPP_ */
