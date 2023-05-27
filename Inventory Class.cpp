/* Programmer Name: Connor Hathaway
* 
* Description: The purpose of this program is to help the user calculate the total cost of a bulk item order. It will ask them for
* the item number, how many of the item they're ordering, and how much one of the item costs. It will then return the three inputs
* back as outputs, along with the total cost of the order. This program makes use of classes and member functions to do everything
* it needs to calculate and return the total costs.
* 
* Date: 3/9/23
*/

#include <iostream>
#include <iomanip>
using namespace std;

class Inventory {
private:
    int itemNumber;
    int quantity;
    double cost;
public:
    void defaultConstructor(void) { // Sets all the variables above to 0
        itemNumber = 0;
        quantity = 0;
        cost = 0;
    }
    void constructor2(int num, int quan, double co) { // Called upon to call all the other functions inside to calculate the total costs
        setItemNumber(num);
        setQuantity(quan);
        setCost(co);
        cout << "\nItem #" << getItemNumber() << endl;
        cout << "Quantity: " << getQuantity() << endl;
        cout << "Cost: $" << fixed << setprecision(2) << getCost() << endl;
        cout << "\nTotal Cost: $" << fixed << setprecision(2) << getTotalCost() << endl;
    }
    void setItemNumber(int num) { // Assigns user input to the itemNumber variable
        itemNumber = num;
    }
    void setQuantity(int quan) { // Assigns user input to the quantity variable
        quantity = quan;
    }
    void setCost(double co) { // Assigns user input to the cost variable     
        cost = co;
    }
    int getItemNumber() { // Returns the itemNumber to output
        return itemNumber;
    }
    int getQuantity() { // Returns the quantity to output
        return quantity;
    }
    double getCost() { // Returns the cost to output
        return cost;
    }
    double getTotalCost() { // Calculates the total cost of the bulk order, then returns it to output
        double totalCost;

        totalCost = quantity * cost;

        return totalCost;
    }
};

int main()
{   
    Inventory Item;
    int num = 0;
    int quan = 0;
    double co = 0;

    Item.defaultConstructor(); // This defaults all the variables in the Inventory class to zero

    do { // All the input validations are done here, one at a time. If the user has inputted a negative number for any category, it will prompt them to enter a number for that category again until it recieves a positive number
        cout << "Enter the item number: #";
        cin >> num;
        if (num < 0) {
            cout << "\nThe item number must be a positive number. Please try again.\n";
        }
    } while (num < 0);

    do {
        cout << "How many of this item are you ordering? ";
        cin >> quan;
        if (quan < 0) {
            cout << "\nThe quantity must be a positive number. Please try again.\n";
        }
    } while (quan < 0);

    do {
        cout << "What is the cost of the item? $";
        cin >> co;
        if (co < 0) {
            cout << "\nThe cost must be a positive number. Please try again.\n";
        }
    } while (co < 0);

    Item.constructor2(num, quan, co); // This calls the function inside the Inventory class that leads to using all the other functions to calculate the total cost
 
    return 0;
}