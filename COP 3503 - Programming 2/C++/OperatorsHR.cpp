#include <iostream>

using namespace std;

int main() {
    double meal_cost;
    cin >> meal_cost;
    int tip_percent;
    cin >> tip_percent;
    int tax_percent;
    cin >> tax_percent;
    double tip;
    double tax;
    double totalCost;

    tip = meal_cost*(tip_percent/100);
    tax = meal_cost*(tax_percent/100);
    totalCost = meal_cost + tip + tax;
   //

    cout << "The total meal cost is " << totalCost;
    return 0;
}
