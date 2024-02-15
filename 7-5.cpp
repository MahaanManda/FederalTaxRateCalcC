/* Write a program that can be used to calculate the federal tax. The tax is calculated as follows: For single people, the standard exemption is $4,000; for married people, the 
standard exemption is $7,000.   A person can also put up to 6% of his or her gross income in a pension plan.   The tax rates are as follows: 

If the taxable income is: 
Between $0 and $15,000, the tax rate is 15%.

Between $15,001 and $40,000, the tax is $2,250 plus 25% of the taxable income over $15,000.

Over $40,000, the tax is $8,460 plus 35% of the taxable income over $40,000.



Prompt the user to enter the following information:

Marital status

If the marital status is “married,” ask for the number of children under the age of 14

Gross salary (If the marital status is “married” and both spouses have income, enter the combined salary.)

Percentage of gross income contributed to a pension fund




Your program must consist of at least the following functions:

Function getData: This function asks the user to enter the relevant data.

Function taxAmount: This function computes and returns the tax owed.



To calculate the taxable income, subtract the sum of the standard exemption, the amount contributed to a pension plan, and the personal exemption, which is $1,500 per person. (Note that if a married couple has two children under the age of 14, then the personal exemption is .)
*/

#include <iostream>
#include <string>

using namespace std;

//function prototypes
void getData(string& marital_status, int& gross_income, double& pension, int& underFourteen, string& spouses_income_check);
double taxAmount(const int gross_income, string marital_status, double pension, int underFourteen);



int main()
{
    string marital_status;
    string spouses_income_check;
    int gross_income;
    double pension;
    int underFourteen;
    double federalTax;

    getData(marital_status, gross_income, pension, underFourteen, spouses_income_check);
    federalTax = taxAmount(gross_income, marital_status, pension, underFourteen);

    cout << "You will pay $" << federalTax << " in federal taxes";
    
}






//functions
void getData(string& marital_status, int& gross_income, double& pension, int& underFourteen, string& spouses_income_check)
{
    cout << "Are you married or single?: ";
    cin >> marital_status;
    // Convert marital_status to lowercase
    for (int i = 0; i < marital_status.length(); ++i) {
        marital_status[i] = tolower(marital_status[i]);
    }


    //If the marital status is “married,” ask for the number of children under the age of 14 and check if both spouses have income
    if (marital_status == "married") {
        cout << "Do both spouses have income? (yes or no): ";
        cin >> spouses_income_check;
        // Convert spouses_income_check to lowercase
        for (int i = 0; i < spouses_income_check.length(); ++i) {
        spouses_income_check[i] = tolower(spouses_income_check[i]);
        }
        //check children
        cout << "Enter number of children under the age of 14: ";
        cin >> underFourteen;
    }
    //gross income
    if ((marital_status == "married") && (spouses_income_check == "yes")) {
        cout << "Enter your combined salary: ";
        cin >> gross_income;
    }
    else{
        cout << "Enter your salary: ";
        cin >> gross_income;
    }
    //Percentage of gross income contributed to a pension fund
    cout << "What percentage of your gross income do you want to contribute to your pension plan(up to 6%)(ommit the percentage symbol): ";
    cin >> pension;
    //convert percentage to decimal for calculations
    pension = pension/100;
}



double taxAmount(const int gross_income, string marital_status, double pension, int underFourteen)
{
    double taxRate = 0;
    int difference = 0;
    int exemption = 0;
    double taxableIncome = 0;
   

    //exemptions
    //For single people, the standard exemption is $4,000; for married people, the standard exemption is $7,000
    //For single people
    if ((marital_status == "single") && (gross_income > 4000)){
        //the standard exemption is $4,000
        cout << "You will save 4000" << endl;
        exemption = 4000;
    }
    //for married people
    else if ((marital_status == "married") && (gross_income > 7000)){
        //the standard exemption is $7,000
        cout << "You will save 7000" << endl;
        exemption = 7000;
    }


    //To calculate the taxable income, subtract the sum of the standard exemption, the amount contributed to a pension plan, and the personal exemption, which is $1,500 per person. 
    if (marital_status == "married"){
        taxableIncome = (exemption + (gross_income + (pension * gross_income)) + (1500 * (2 + underFourteen))) - gross_income;
    }
    else if (marital_status == "single"){
        taxableIncome = (exemption + (gross_income + (pension * gross_income)) + 1500) - gross_income;
    }

    
     /* If the taxable income is: 
    Between $0 and $15,000, the tax rate is 15%.

    Between $15,001 and $40,000, the tax is $2,250 plus 25% of the taxable income over $15,000.

    Over $40,000, the tax is $8,460 plus 35% of the taxable income over $40,000. */

    if ((taxableIncome >= 0) && (taxableIncome <= 15000)){
        //the tax rate is 15%
        taxRate = 0.15 * taxableIncome;
    }
    //Between $15,001 and $40,000, 
    else if ((taxableIncome > 15000) && (taxableIncome <= 40,000)){
        //the tax is $2,250 plus 25% of the taxable income over $15,000.
        difference = taxableIncome - 15000;
        taxRate = 2250 + (0.25 * difference);
    }
    //Over $40,000
    else if (taxableIncome > 40,000){
        //the tax is $8,460 plus 35% of the taxable income over $40,000.
        difference = taxableIncome - 40000;
        taxRate = 8460 + (0.35 * difference);
    }

    return taxRate;
}