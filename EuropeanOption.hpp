/*
 * EuropeanOption.hpp
 *
 *  Created on: Dec. 14, 2023
 *      Author: sinazabanfahm
 */

#include <string>
class EuropeanOption
{
private:
	// "Kernel" functions
	/*
	 * Computes the CallPrice, const gaurantees that the non-static
	 * data will not be changed.
	 */
private:
	//private member_data
	double r;				//Interest rate
	double sig;				//Volatility
	double K;				//Strike price
	double T;				// Expire date
	double U;				//current underlying price
	double b;				//cost of carry (mode detail)
	std::string optType; 	//"C" for Call, "P" for put

public:
	//modifier and accessors

	double get_r();
	double get_sig();
	double get_K();
	double get_T();
	double get_U();
	double get_b();
	std::string get_optType();

	void set_r(double rr);
	void set_sig(double ssig);
	void set_K(double KK);
	void set_T(double TT);
	void set_U(double UU);
	void set_b(double bb);
	void set_optType(std::string OOptType);

private:
	//Helper_functions
	void init();
	void copy(EuropeanOption& option2);
	double get_d1() const;
	double get_d2() const;
	double N(double z) const;

private:
	//Kernel Functions:
	double CallPrice() const;
	double PutPrice() const;
	double CallDelta() const;
	double PutDelta() const;

	void toggle();

public:
	//Constructors
	EuropeanOption();
	EuropeanOption(EuropeanOption& option2);
	EuropeanOption(const std::string& optionType);
	//Destructors
	virtual ~EuropeanOption();

public:
	//Operators
	EuropeanOption& operator = ( EuropeanOption& option2);

public:
	double Price() const;
	double Delta() const;
};


