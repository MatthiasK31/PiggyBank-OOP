#pragma once
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>

class PiggyBank
{
	private:
		int pennies = 0, nickels = 0, dimes = 0, quarters = 0, weeksSaved = 0, years = 0;
		double avgSaveRate = 0, savePYear = 0, saveXYears = 0, lastTotal = 0;
		double total = 1;
		std::string name, holder = "", theCoin = " ";
		std::string choice = " ";
		bool flag = false;
		std::vector <std::string> coinType{ "penny", "nickel", "dime", "quarter" };

	public:
		
		//default
		PiggyBank();
		PiggyBank(std::string, int, int, int, int, int, int);
		PiggyBank(int);
		PiggyBank(std::string);


		//input validation
		void checkingInput(std::string);
		void checkingWeeks(std::string);
		std::string forYears(std::string);
		std::string checkName(std::string);

		//change amount of coins and add coins to total
		void addPenny(int);
		void addNickel(int);
		void addDime(int);
		void addQuarter(int);
		void addWeeks(int);

		void inYears(int);
		void totalValue();
		void calculateSavingsRate();
		void perYear();

		//print
		void printSavingsStatement();
		std::string toString();
		std::string printYears();

};

