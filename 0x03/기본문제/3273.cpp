//요렇게 하니까 둘다됨 황당띠; 
#include <bits/stdc++.h>
using namespace std;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int size;
    cin >> size;

    int arr[size];
    for(int i = 0; i< size; i++){
        cin >> arr[i];
    }

    int sum, cnt = 0;
    cin >> sum;

    //bool쓰면 int보다 메모리를 덜 차지해서 아마 실행이 된 듯함
    //2000001을 해준 이유는 sum의 범위가 2000000까지이므로 sum - arr[i]일 경우도 생각해야 하므로.
    bool occur[2000001] = {}; 
    for(int i = 0; i < size; i++){
        if(sum-arr[i] > 0 && occur[sum - arr[i]]) cnt++; //음수 확인하는 거 없으면 틀렸다고 뜸
        occur[arr[i]] = 1;
    }

    cout << cnt;

}


//이렇게 하면 백준에서는 맞는데 vscode에서는 입력커서가 안뜨고 바로 종료됨
//아무래도 메모리 초과 때문인듯?
/*
#include <bits/stdc++.h>
using namespace std;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int size;
    cin >> size;

    int arr[size];
    for(int i = 0; i< size; i++){
        cin >> arr[i];
    }

    int sum, cnt = 0;
    cin >> sum;

    int occur[2000001] = {};
    for(int i = 0; i < size; i++){
        if(sum-arr[i] > 0 && (occur[sum - arr[i]] == 1)) cnt++;
        occur[arr[i]] = 1;
    }

    cout << cnt;

}
*/