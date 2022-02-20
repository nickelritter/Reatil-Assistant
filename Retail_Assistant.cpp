//  Retail_Assistant.cpp
//  Retail Sales Assistant Program
//  Programmer: Steven Heid
//  Date: 22Septemeber2019
//  Description:  This program calculates sales tax for a series of products.


//  Included Libraries
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	double cashDrawer = 100.00;
	int productID = 0;
	int quantity = 0;
	double price = 0.0;
	double subtotal = 0.0;
	double salesTax = 0.0;
	double totalSale = 0.0;
	double taxRate = 0.0;
	int anotherSale = 1;
	int saleCounter = 1;

	// Loop for repeat sales
	while (anotherSale == 1)
	{
		// Enter the first Product ID for the first sale (-1 to exit)
		cout << "Enter the first product ID: ";
		cin >> productID;

		// Main loop for each sale
		while (productID != -1)
		{
			cout << "Enter the product quantity: ";
			cin >> quantity;

			// Switch statement to determine the price, and calculate sales tax,
			// if any, for the item
			switch (productID)
			{
			case 101:
				price = 3.95;
				taxRate = 0.0;
				break;
			case 102:
				price = 1.85;
				taxRate = 0.075;
				break;
			case 103:
				price = 2.49;
				taxRate = 0.075;
				break;
			case 104:
				price = 5.19;
				taxRate = 0.075;
				break;
			case 105:
				price = 4.99;
				taxRate = 0.0;
				break;
			case 106:
				price = 3.25;
				taxRate = 0.075;
				break;
			case 107:
				price = 4.85;
				taxRate = 0.0;
				break;
			case 108:
				price = 3.99;
				taxRate = 0.075;
				break;
			case 109:
				price = 1.99;
				taxRate = 0.0;
				break;
			case 110:
				price = 5.25;
				taxRate = 0.075;
				break;
			default:
				cout << "\nERROR: Product ID must be between 101 and 110." << endl;

			} // End switch() statement

			// Calc. subtotal/salesTax and adds to running total
			subtotal += price * quantity;
			salesTax += taxRate * quantity * price;

			// Get next product ID
			cout << "\nEnter the next product ID (-1 to EXIT): ";
			cin >> productID;

		} // End main loop for this sale

		// Calc. totalSale after productID loop. Adds to running total.
		totalSale += subtotal + salesTax;

		// Print properly formatted receipt (Subtotal, Tax, Total Sale) for
		// each sale
		cout << "\n\tSale #" << saleCounter << "\nSubtotal-\t\t " << subtotal << "\nTax-\t\t\t " << salesTax << "\nTotal Sale-\t\t " << totalSale << endl;

		// Add total sale to the cashdrawer
		cashDrawer += totalSale;

		// Reset for next sale
		price = 0.0;
		subtotal = 0.0;
		salesTax = 0.0;
		totalSale = 0.0;
		taxRate = 0.0;

		// Another sale?
		cout << "\nWould you like to do another sale? \n(1-Continue, 0-End program)\n";
		cin >> anotherSale;
		saleCounter++;

	} // End loop for repeat sale

	// Display how much is in the cash drawer at the end
	cout << "\nAmount left in cash drawer after all sales: " << cashDrawer << endl;

	return 0;
}
