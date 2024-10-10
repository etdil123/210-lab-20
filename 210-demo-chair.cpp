#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

using namespace std;
const int SIZE = 3;
const int MIN_PRICE = 10000;
const int MAX_PRICE = 99999;
const int MIN_LEGS = 300;
const int MAX_LEGS = 400;

class Chair {
private:
    int legs;
    double * prices;
public:
    // constructors
    Chair() {
        prices = new double[SIZE];
        int randL = (rand() % (MAX_LEGS - MIN_LEGS + 1) + MIN_LEGS) / (int) 100;
        legs = randL;
        for (int i = 0; i < SIZE; i++){
            // randomizing double between 100.00 and 999.99
            double price = (rand() % (MAX_PRICE - MIN_PRICE + 1) + MIN_PRICE) / (double) 100;
            // storing random double into Chair prices array
            prices[i] = price;
        }
    }
    Chair(int l, double * p) {
        prices = new double[SIZE];
        legs = l;
        for (int i = 0; i < SIZE; i++)
            prices[i] = p[i];
    }

    // setters and getters
    void setLegs(int l)      { legs = l; }
    int getLegs()            { return legs; }

    void setPrices(double p1, double p2, double p3) { 
        prices[0] = p1; prices[1] = p2; prices[2] = p3; 
    }

    double getAveragePrices() {
        double sum = 0;
        for (int i = 0; i < SIZE; i++)
            sum += prices[i];
        return sum / SIZE;
    }

    void print() {
        cout << "CHAIR DATA - legs: " << legs << endl;
        cout << "Price history: " ;
        for (int i = 0; i < SIZE; i++)
            cout << prices[i] << " ";
        cout << endl << "Historical avg price: " << getAveragePrices();
        cout << endl << endl;
    }
};

int main() {
    srand(time(0));
    cout << fixed << setprecision(2);

    //creating pointer to first chair object
    // uses default constructor - changes initial values with setters
    Chair *chairPtr = new Chair;
    chairPtr->setLegs(4);
    chairPtr->setPrices(121.21, 232.32, 414.14);
    cout << "\nChair created by Default Constructor - Changed with Setters" << endl;
    chairPtr->print();
    cout << endl;

    //creating dynamic chair object with constructor
    // Uses updated parameter constructor - feeds in from parameter int AND array of prices  
    double chairPricesExample[SIZE] = {312.42, 299.99, 499.99};
    Chair *livingChair = new Chair(3, chairPricesExample);
    cout << "Chair created by Updated Parameter Constructor" << endl;
    livingChair->print();
    delete livingChair;
    livingChair = nullptr;

    //creating dynamic array of chair objects
    Chair *collection = new Chair[SIZE];
    for (int i = 0; i < SIZE; i++)
        collection[i].print();

    // collection[0].setLegs(4);
    // collection[0].setPrices(441.41, 552.52, 663.63);
    // collection[1].setLegs(4);
    // collection[1].setPrices(484.84, 959.59, 868.68);
    // collection[2].setLegs(4);
    // collection[2].setPrices(626.26, 515.15, 757.57);
    // for (int i = 0; i < SIZE; i++)
    //     collection[i].print();
    
    return 0;
}