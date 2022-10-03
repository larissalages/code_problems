#include <iostream>
#include <numeric>
#include <math.h>
#include <string>
#include <functional>
#include <vector>
#include <algorithm>

int gcd(int num1, int num2) {
	if (num2 != 0) {
		return gcd(num2,num1%num2);
	} else {
		return num1;
	}
}

int main() {
    //m^2-n^2|2mn|m^2+n^2 where m>n,gcd(m,n)=1,either m or n is even
    int maxSize = 10000;
    std::vector<int> shortIntRoutes;
    for (int i=0;i<=maxSize;i++) {
        shortIntRoutes.push_back(0);
    }
    int m,n,k;
    m = 2;
    while (2*m-1<=maxSize) {
        bool isOdd = m%2 == 1;
        n = 1;
        while (n < m) {
            if ((isOdd && n%2==1) || gcd(m,n) != 1) {
                n++;
                continue;
            }
            int a = m*m-n*n;
            int b = 2*m*n;
            int c = m*m+n*n;
            for (int k=1;std::min(a,b)*k<=maxSize;k++) {
                int h = a*k;
                int i = b*k;
                if (h <= maxSize) {
                    if (i > h + 1) {
                        shortIntRoutes[h] += std::max(0,i/2-(i-h-1));
                    } else {
                        shortIntRoutes[h] += i/2;
                    }
                }
                if (i <= maxSize) {
                    if (h > i + 1) {
                        shortIntRoutes[i] += std::max(0,h/2-(h-i-1));
                    } else {
                        shortIntRoutes[i] += h/2;
                    }
                }
            }
            n++;
        }
        m++;
    }
    int sum = 0;
    for (int i=0;i<=maxSize;i++) {
        sum += shortIntRoutes[i];
        if (sum > 1000000) {
            std::cout << i << " " << sum << std::endl;
            break;
        }
        //std::cout << i << " " << shortIntRoutes[i] << " " << sum << std::endl;
    }
}