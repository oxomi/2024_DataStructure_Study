#include <iostream>
#include <string>

using namespace std;


int main(){
    ios::sync_with_stdio(false); //c stream 인 scanf/printf를 사용하지 않아 동기화가 필요 없을 떄 시간단축을 위해 사용
    cin.tie(nullptr); //온라인저지에서는 출력값만 판단하므로 버퍼를 굳이 비워줄 필요 없기 때문에 시간단축을 위해 사용.
    int a = 0, b = 0;
    cin >> a >> b ;
    
    int * temp = new int[a];
    for(int i=0; i < a; i++){
        cin >> temp[i];
    }

    for(int i=0; i< a; i++){
        if(temp[i] < b){
            cout << temp[i] << " " ;
        }
    }

    delete [] temp; 

}