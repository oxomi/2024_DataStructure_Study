#include <iostream>
using namespace std;

int func1(int N){
    int temp = 0;
    for(int i = 1; i <= N; i++){
        if(i % 3 == 0 || i % 5 == 0){
            temp = temp + i;
        }
    }
    return temp;
}