// CTankStelle.cpp : Defines the entry point for the console application.
//
#include <iostream>
#include "stdafx.h"
#include "stdio.h"
using namespace std;

class CTank {
public:
	CTank(void) {};
	CTank(double hilfsFoerderMaenge){
		foerderMaenge = hilfsFoerderMaenge;
}; //Konstruktor

	void LeseFoerderMaenge(void) {};
	void SetzeFoerderMaenge(void) {};

	virtual double BerechneVolumen(void) { // double und nicht void da ruekgabe
		//tankVolumen = laenge *breite * hoehe;
		return tankVolumen;
	};
	void BerechneMaxEntleerungszeit() {
		double entleerungsZeit = 0;
		tankVolumen /= foerderMaenge;
	};

protected:
	double foerderMaenge=0;
	double tankVolumen=0;
};

class CQuaderTank :CTank {
public:
	CQuaderTank(double hLaenge, double hBreite, double hHoehe) {
		laenge = hLaenge;
		breite = hBreite;
		hoehe = hHoehe;
		//foerderMaenge = hFoerderMaenge;

	};
	virtual double BerechneVolumen(void) {
		tankVolumen = laenge * breite * hoehe;
		return tankVolumen / 1000; //in Liter 
	};
protected:
	double laenge, breite, hoehe;
};

int main()
{
	double a, b, c;
	cout << "Please enter the wanted length: " << endl;
	cin >> a ;
	cout << "Please enter the wanted width:  " << endl;
	cin >> b;
	cout << "Please enter the wanted higth:  " << endl;
	cin >> c;
	CQuaderTank tank1(a,b,c);
	//CQuaderTank tank2();

	
	cout << "The volume of the tank in liters (L): " << tank1.BerechneVolumen() << " Liter\n\n";

    return 0;
}

