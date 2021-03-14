#include <iostream>
#include <time.h>
using namespace std;
int isPrime(int n){ // ordinary algorithm
    if(n == 1) return 0;
    for (int i = 2;i * i <= n;i++){
        if (n % i == 0) return 0;
    }
    return 1;
}
int main() {
    int begintime,endtime;
    begintime = clock();
    for(int i = 2;i <= 1000;i++){
        if(isPrime(i)) cout << i << ' ';
    }
    endtime = clock();
    cout << "Runtime is " << endtime - begintime << "ms" << endl;
    return 0;
}
