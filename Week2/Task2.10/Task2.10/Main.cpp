////////////////////////////////////
////		  Task2.10	    	////
////////////////////////////////////

#include<iostream>
#include<cmath>
#include<iomanip>

#define PI 3.14159

/*
	Calculates current using the given parameters:
	R = Resistance in Ohms
	F = Frequency in Hertz
	C = Capacitance in Farads
	L = Inducatance in Henrys
	E = Electromotive Force in Volts
*/
double CalCurrent(double R, double F, double C, double L, double E)
{
	double result, rSQ, twoPFL, twoPFC;

	rSQ = pow(R, 2); // R^2
	twoPFL = 2 * PI * F * L; // 2 * Pi * Frequency * Inductance
	twoPFC = 1 / (2 * PI * F * C); // 1 / (2 * Pi * Frequency * Cappacitance)
	result = E / sqrt(rSQ + pow((twoPFL - twoPFC), 2));
	// result is current(I)
	// result = EMF / SquareRoot(Resistance^2 + ((2 * Pi * Frequency * Inductance) - (1 / 2 * Pi * Frequency * Capacitance))^2)
	return result;
}


/*
	Calculates Resonant Frequency from given parameters:
	L = Inductance
	C = Capacitance
*/
double CalcResFreq(double L, double C)
{
	double result, sqrtLC, twoPI;
	sqrtLC = sqrt(L * C);
	twoPI = 2 * PI;
	result = 1/(twoPI * sqrtLC);
	return result;
}

int main()
{
	double current, emf, resistance, frequency, inductance, capacitance, resFreq;

	std::cout << "Enter the Resistance, Frequency, Capacitance, Inductance and EMF." << std::endl;
	std::cout << "Resistance(Ohms): ";
	std::cin >> resistance;
	std::cout << "Frequency(Hertz): ";
	std::cin >> frequency;
	std::cout << "Capacitance(Farads): ";
	std::cin >> capacitance;
	std::cout << "Inductance(Henrys): ";
	std::cin >> inductance;
	std::cout << "Electromotive Force(Volts): ";
	std::cin >> emf;

	current = CalCurrent(resistance, frequency, capacitance, inductance, emf);// Calculates current from given parameters

	std::cout << "I(Current) = " << current << "A" << std::endl;			  // Displays calculated current/result

	resFreq = CalcResFreq(inductance, capacitance);							  //Caculates resonant frequency

	std::cout << "The resonant frequency is: " << resFreq << std::endl;		  //Displays Resonant Frequency.

	std::cin.get();
	std::cin.get();															  //Keeps console open till enter is pressed

	return 0;
}


////////////////////////////////////
////Name: Franz Jordaneal Tamani////
////StuID: 102114822			////
////////////////////////////////////