#include <iostream>
#include <vector>

//This algorithm shows the process of solving (and solves) a system of congruencies

int gcd_print(int a, int b){
    if(b != 0){
        std::cout << a << " = " << b << " * " << a / b << " + " << a % b << "\n";
        return gcd_print(b, a % b);
    }
    else{
        return a;
    }
}

int gcd_extend(int a, int b, int &x, int &y){ 
    if(b == 0){ 
        x = 1; 
        y = 0; 
        return a; 
    } 

    else{ 
        int g = gcd_extend(b, a % b, x, y); 
        int x1 = x, y1 = y; 
        x = y1; 
        y = x1 - (a / b) * y1; 

        std::cout << g << " = " << x << " * " << a << " + " << y << " * " << b << "\n";
        return g; 
    } 
} 

//Modular inverse x of a mod m
int modular_inverse(int a, int m, int &x, int &y){
    int g;
    g = gcd_print(a, m);
    std::cout << "\n";
    g = gcd_extend(a, m, x, y);
    if(g != 1){
        std::cout << "No solution!";
    }
    else{
        //x = (x % m + m) % m;
    }
    return x;
}

int main(){
    int i, j, temp, temp2, queries, m_solution = 1, a_solution = 0;
    std::vector<int> M;
    std::vector<int> m;
    std::vector<int> a;
    std::vector<int> y;
    
    std::cout << "Enter how many congruencies your system has: ";
    std::cin >> queries;

    for(i = 0; i < queries; i++){
        std::cout << "Enter congruency " << i + 1 << " (a and m" << i+1 << "): ";
        std::cin >> temp >> temp2;
        a.push_back(temp);
        m.push_back(temp2);
        m_solution *= m[i];
    }

    std::cout << "\nBy the Chinese Remainder Theorem, we have a single solution x mod " << m_solution << ". From this: \n";

    for(i = 0; i < queries; i++){
        M.push_back(m_solution/m[i]);
        std::cout << "M" << i+1 << " = " << m_solution << "/" << m[i] << "  =>  M" << i+1 << " = " << M[i] << "\n";
    }
    std::cout << "\n";

    std::cout << "Finding yi (modular inverse of Mi mod mi) through the extended euclidean algorithm:\n";
    for(i = 0; i < queries; i++){
        std::cout << M[i] << " mod " << m[i] << "\n";
        y.push_back(modular_inverse(M[i], m[i], temp, temp2));
        std::cout << "Thus, y" << i+1 << " is " << y[i] << ". Since this value is congruent with m[i], the smallest positive value it can achieve is " << (y[i] % m[i] + m[i]) % m[i] << ".\n\n";
        y[i] = (y[i] % m[i] + m[i]) % m[i];
    }

    std::cout << "\nx = ";
    for(i = 0; i < queries; i++){
        a_solution += M[i] * a[i] * y[i];
        std::cout << M[i] << " * " << a[i] << " * " << y[i];
        if(i < (queries - 1)) std::cout << " + ";
    }
    std::cout << " mod " << m_solution << "\n";
    std::cout << "x = " << a_solution << " mod " << m_solution << "\n";
    a_solution %= m_solution;
    std::cout << "x = " << a_solution << " mod " << m_solution << "\n";
}