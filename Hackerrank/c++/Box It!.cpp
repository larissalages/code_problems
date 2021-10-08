/**
 * @file Inheritance Introduction.cpp
 * @author Vipul Kumar Singh
 * @brief  (https://www.hackerrank.com/domains/cpp?filters%5Bsubdomains%5D%5B%5D=inheritance)
 * @version 0.1
 * @date 2021-10-02
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


class Triangle{
    public:
    	void triangle(){
     		cout<<"I am a triangle\n";
    	}
};

class Isosceles : public Triangle{
    public:
    	void isosceles()
        {
    		cout<<"I am an isosceles triangle\n";
    	}
  		//Write your code here.
          
        void description()
        {
            cout<<"In an isosceles triangle two sides are equal \n";
        }
};

int main(){
    Isosceles isc;
    isc.isosceles();
  	isc.description();
    isc.triangle();
    return 0;
}


