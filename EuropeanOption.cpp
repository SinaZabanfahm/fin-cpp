/*x`
 * EuropeanOption.cpp
 *
 *  Created on: Dec. 14, 2023
 *      Author: sinazabanfahm
 */
#include "EuropeanOption.hpp"
#include <string>
#include <math.h>

//Getters
double EuropeanOption::get_r(){
	return r;
}
double EuropeanOption::get_sig(){
	return sig;
}
double EuropeanOption::get_K(){
	return K;
}
double EuropeanOption::get_T(){
	return T;
}
double EuropeanOption::get_U(){
	return U;
}
double EuropeanOption::get_b(){
	return b;
}

std::string EuropeanOption::get_optType(){
	return optType;
}


//Setters
void EuropeanOption::set_r(double rr){
	r = rr;
}
void EuropeanOption::set_sig(double ssig){
	sig = ssig;
}
void EuropeanOption::set_K(double KK){
	K = KK;
}
void EuropeanOption::set_T(double TT){
	T = TT;
}
void EuropeanOption::set_U(double UU){
	U = UU;
}
void EuropeanOption::set_b(double bb){
	b = bb;
}
void EuropeanOption::set_optType(std::string OOptType){
	optType = OOptType;
}

//Helper functions:
void EuropeanOption::init()
{
	//Initializing the default values
	r = 0.08;
	sig = 0.30;
	K = 65.0;
	T = 0.25;
	U = 60.0;
	b = r;
	optType = "C";
}
void EuropeanOption::copy(EuropeanOption& option2){
	r = option2.get_r();
	sig = option2.get_sig();
	K = option2.get_K();
	T = option2.get_T();
	U = option2.get_U();
	b = option2.get_b();
	optType = option2.get_optType();
}

double EuropeanOption::get_d1() const{
	double tmp = sig * sqrt(T);
	return (log(U/K) + (b + (sig*sig)*0.5)* T)/tmp;

}
double EuropeanOption::get_d2() const{
	double tmp = sig * sqrt(T);
	return get_d1() - tmp;
}
double EuropeanOption::N(double z) const{

	return 0.5 * erfc( -z * sqrt(0.5));
}

//Kernel functions:

double EuropeanOption::CallPrice() const{
	double d1 = get_d1();
	double d2 = get_d2();

	return (U * exp((b-r)*T))*N(d1) - (K * exp(-r * T)*N(d2));
}


double EuropeanOption::PutPrice() const{
	double d1 = get_d1();
	double d2 = get_d2();

	return (K* exp(-r * T)*N(-d2)) - (U*exp((b-r)*T)*N(-d1));
}

double EuropeanOption::CallDelta() const{
	double d1 = get_d1();
	return exp((b-r)*T) * N(d1);
}

double EuropeanOption::PutDelta() const{
	double d1 = get_d1();
	return exp((b-r)*T) * (N(d1) - 1.0);
}
void EuropeanOption::toggle(){
	if (optType == "C"){
		optType ="P";
	}
	else{
		optType = "C";
	}
}
//Constructors

EuropeanOption::EuropeanOption(){
	init();
}

EuropeanOption::EuropeanOption(EuropeanOption& option2){
	copy(option2);
}

EuropeanOption::EuropeanOption(const std::string &optionType){
	init();
	optType = optionType;
}

//Destructors
EuropeanOption::~EuropeanOption(){

}
//Operators
EuropeanOption& EuropeanOption::operator = ( EuropeanOption& option2){
	if (this == &option2){
		return *this;
	}
	copy(option2);
	return *this;
}
//Price functions:
double EuropeanOption::Price() const{
	if (optType == "C")
		return CallPrice();
	return PutPrice();
}

double EuropeanOption::Delta() const{
	if (optType == "C"){
		return CallDelta();
	}
	return PutDelta();
}


