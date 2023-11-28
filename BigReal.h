
#ifndef BIGREAL_H
#define BIGREAL_H

#include <bits/stdc++.h>
using namespace std;

class BigReal {
private:
    bool isNegative;
    string INPUT;

public:
    BigReal (double realNumber = 0.0); // Default constructor
    BigReal (string realNumber); // Initialize from string
    BigReal (const BigReal& other); // Copy constructor
    BigReal& operator=(const BigReal& other); // Assignment operator
    bool isValidReal (string realNumber); // Function to check valid numbers
    BigReal operator+ (BigReal& other);   // Addition operator
    BigReal operator- (BigReal& other);   // Subtraction operator
    bool operator< (BigReal anotherReal); // Less than comparison
    bool operator> (BigReal anotherReal);  // More than comparison
    bool operator== (BigReal anotherReal); // Is Equal comparison
    friend ostream& operator << (ostream& OUT, BigReal num); // Printing Function

};


#endif //BIGREAL_H
