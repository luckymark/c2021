#include <iostream>
#include <string.h>
#include <time.h>
using namespace std;
int main() { // Use"ShaiFa"
    int begintime,endtime;
    begintime = clock();
    int f[1005]; // identify whether the number is a prime
    memset(f,1,sizeof f);
    for(int i = 2;i < 1000;i++){
        if(f[i])
            for(int j = 2; j * i <= 1000; j++) f[i*j] = 0;
    }
    for(int i = 2;i < 1000;i++) if (f[i]) cout << i << ' ';
    endtime = clock();
    cout << "Runtime is " << endtime - begintime << "ms" << endl;
    return 0;
}
