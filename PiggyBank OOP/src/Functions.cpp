#include <iostream>
#include "Header.h"
#include <iomanip> 
#include <vector>
#include <sstream>


using namespace std;


//default constructor
PiggyBank::PiggyBank() {}

//constructor for coins
PiggyBank::PiggyBank(string uName, int penny, int nickel, int dime, int quarter, int week, int year) {
    name = uName;
    pennies += penny;
    nickels += nickel;
    dimes += dime;
    quarters += quarter;
    weeksSaved += week;
    years += year;
    totalValue();
}

//constructor for weeks
PiggyBank::PiggyBank(int wks) {
    weeksSaved = wks;
    addWeeks(weeksSaved);
}

//constructor for name
PiggyBank::PiggyBank(string nm) {
    name = nm;
}

//error trap name input
void PiggyBank::checkingInput(string name) {
    do {
        flag = false;
        cout << "\nHow many " << name << " do you have?  ";
        cin >> holder;

        for (char i : holder) {
            if (!isdigit(i)) {
                flag = true;
                cout << "Please enter another number.\n" << endl;
                break;
            }
        }
    } while (flag);

    if (name == "pennies") {
        addPenny(stoi(holder));
    }
    else if (name == "nickels") {
        addNickel(stoi(holder));
    }
    else if (name == "dimes") {
        addDime(stoi(holder));
    }
    else if (name == "quarters") {
        addQuarter(stoi(holder));
    }

}

//error trap the num of weeks
void PiggyBank::checkingWeeks(string holder) {
    do {
        flag = false;
        cout << "How many weeks have you been saving for?  ";
        cin >> holder;

        for (char i : holder) {
            if (!isdigit(i)) {
                flag = true;
                cout << "Please enter another number.\n" << endl;
                break;
            }
        }
    } while (flag);
    weeksSaved = stoi(holder);
}

//validate that the name isn't a number
string PiggyBank::checkName(string uName) {
    do {
        flag = false;
        while (true) {
            cout << "What is your name?    ";
            getline(cin, holder);
            try {
                stoi(holder);
                cout << "Please enter a name, not a number!\n" << endl;
            }
            catch (exception& e) {
                break;
            }
        }
    } while (flag);
    name = holder;
    return name;
}

//extra functions
string PiggyBank::forYears(string holder) {
    do {
        flag = false;
        std::cout << "For how many years would you like to see your projected total?    ";
        std::cin >> holder;

        for (char i : holder) {
            if (!isdigit(i)) {
                flag = true;
                std::cout << "Please enter a number.\n" << std::endl;
                break;
            }
        }
    } while (flag);

    std::cout << " " << std::endl;
    years = stoi(holder);
    return holder;
}

//add values from parameters into coin variables
void PiggyBank::addPenny(int penny) {
    pennies += penny;
    totalValue();
}
void PiggyBank::addNickel(int nickel) {
    nickels += nickel;
    totalValue();
}
void PiggyBank::addDime(int dime) {
    dimes += dime;
    totalValue();
}
void PiggyBank::addQuarter(int quarter) {
    quarters += quarter;
    totalValue();
}
void PiggyBank::addWeeks(int w) {
    weeksSaved += w;
}


//calculation functions
void PiggyBank::inYears(int xYears) {
    saveXYears = savePYear * xYears;
    saveXYears = (int)(saveXYears * 100 + 0.5);
    saveXYears /= 100;
}

void PiggyBank::totalValue() {
    total = (pennies * 0.01) + (nickels * 0.05) + (dimes * 0.10) + (quarters * 0.25);
}

void PiggyBank::calculateSavingsRate() {
    avgSaveRate = total / weeksSaved;
    avgSaveRate = (int)(avgSaveRate * 100 + 0.5);
    avgSaveRate /= 100;
}

void PiggyBank::perYear() {
    savePYear = avgSaveRate * 52;
    
}

//print coin statement
void PiggyBank::printSavingsStatement() {
    cout << "\n\n" << name << ", here is your savings statement over this " << weeksSaved << " week period.\n" <<  endl;

    printf("%-25s %-15i\n\n", "Weeks Saved:", weeksSaved);
    printf("%-25s %-15i\n", "Pennies:", pennies);
    printf("%-25s %-15i\n", "Nickels:", nickels);
    printf("%-25s %-15i\n", "Dimes:", dimes);
    printf("%-25s %-15i\n", "Quarters:", quarters);
    cout << "------------------------------\n";
    printf("%-25s $%-10.2f\n\n", "Total:", total);

    calculateSavingsRate();
    perYear();
    inYears(years);
}

//toString override
std::string PiggyBank::toString()
{
    std::ostringstream output;
    output << "On average, you save about " << fixed << setprecision(2) << "$" << avgSaveRate << " per week." << endl << "At this rate, you will save $" << fixed << setprecision(2) << savePYear << " in 1 year!" << endl;
    return output.str();
}


string PiggyBank::printYears() {
    std::ostringstream output;
    output << "Great job, " << name << "! In " << years << " years, you are projected to save $" << fixed << setprecision(2) << saveXYears << "!" << endl;
    return output.str();
}
