/*
 * First.cpp
 *
 *  Created on: Dec. 14, 2023
 *      Author: sinazabanfahm
 */

#include <iostream>
using namespace std;
#include "EuropeanOption.hpp"
#include<string>
#include "BondPricing.hpp"
int main() {
	EuropeanOption opt;
	opt.set_optType("P");
	opt.set_U(100.0);
	opt.set_K(95.0);
	opt.set_T(0.5);
	opt.set_r(0.10);
	opt.set_sig(0.20);
	opt.set_b(opt.get_r()-0.05);
	cout<<"Put option price is:"<<opt.Price()<<endl;
	EuropeanOption opt2;
	cout<<"Call option price is:"<<opt2.Price()<<endl;
	vector<double> pmts = {1.0,1.0};

	cout<<"PV of thise series of payments is:"<<BondPricing::pvSeriesPayments(pmts, 2, 0.1)<<endl;
}
