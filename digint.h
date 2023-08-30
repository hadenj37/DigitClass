#ifndef DIGINT
#define DIGINT

/*
A numerical class for accessing specific digits of a number
*/

#include <iostream>
#include <cmath>
#include <stdexcept>

using std::cout;
using std::cerr;
using std::endl;
using std::string;

//symbols for digits
//handles up to base-62
string symbols = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";

class Digint{
    private:
    /*attributes*/
    string digits; //visual representation
    int value; //base-10 value
    char base = 10; //number base

    /*methods*/
    void resetDigitString(int base10value, char numberBase){
        int remainingValue = base10value;

        //find how many places the number has
        //log2(a)/log2(b) = logb(a)
        int places = floor(log2(abs(base10value))/log2(base))+1;
        if(places==0){places = 1;}

        string digitString = "";
        int digit;
        //find digit for each place, starting at the highest (string[0])
        for(size_t index = 0; index < places; index++){

        }

        //check if value was not exausted
        if(remainingValue != 0){
            cerr << "remainingValue was" << remainingValue << endl;
            throw(std::logic_error("resetDigitString does not use all value from input"));
        }
    }

    public:
    /*getters & setters*/
    int getValue(){return value;}
    string getDigits(){return digits;}
    char getnumberBase(){return base;}

    void setNumberBase(char numberBase){
        base = numberBase;
        resetDigitString(this->value, numberBase);
    }

    //NOTE: since numbers typically grow from right to left, this class numbers digits by the exponent the digit is raised to in value calculation
    int at(size_t numberPlace){
        try{
            return digits.at(digits.size()-1-numberPlace);
        }catch(const std::out_of_range&){
            cerr << "Checked for digit at invalid number place";
            exit(1);
        }
    }

    size_t places(){
        if(value < 0){ //account for negative sign
            return digits.size()-1;
        }else{
            return digits.size();
        }
    };

    /*structors*/
    Digint(){
        digits = "0";
        value = 0;
        base = 10;
    }

    ~Digint(){}

    //digits provided
    Digint(string digitString, char numberBase = 10){
        //set string and base as provided
        digits = digitString;
        base = numberBase;
        
        //start at zero
        value = 0;

        //loop through symbols
        int place;
        size_t digit;
        for(size_t index = 0; index < digitString.size(); index++){
            place = digitString.size()-1-index;
            digit = symbols.find(digitString.at(place));
            value += digit*pow(numberBase, place);
        }
    }

    //value provided
    Digint(int base10value, char numberBase = 10){
        //set value as given
        value = base10value;
        base = numberBase;

        //build digits string
        resetDigitString(base10value,base);
    }

};

#endif