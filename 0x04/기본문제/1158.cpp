//헷갈린다 혼자서 못풀었음
#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, K;
    cin >> N >> K;

    list<int> L;
    list<int>::iterator it;

    // 1부터 N까지의 숫자를 리스트 L에 추가합니다.
    for(int i = 1; i <= N; i++){
        L.push_back(i);
    }
    
    it = L.begin(); // 처음 커서를 리스트의 시작으로 설정

    // 리스트가 빌 때까지 반복합니다.
    cout << "<";
    while(L.size() > 1){
        // K-1번 이동하여 K번째 요소를 찾습니다.
        for(int i = 0; i < K-1; i++){
            it++;
            // k번쨰까지 이동하는 도중에 K보다 요소의 수가 작아 이터레이터가 리스트의 끝에 도달할 경우 다시 리스트의 시작으로 이동합니다.
            if(it == L.end()){
                it = L.begin();
            }
        }
        // K번째 요소를 출력합니다.
        cout << *it << ", ";
        it = L.erase(it); // K번째 요소를 지우고 그 다음 요소를 가리키는 이터레이터를 반환합니다.
        // 요소를 삭제했더니 이터레이터가 리스트의 끝에 도달할 경우(ex. K개의 요소가 남았는데 K번째 요소를 삭제할 경우) 다시 리스트의 시작으로 이동합니다.
        if(it == L.end()){
            it = L.begin();
        }
    }
    // 마지막 요소 출력
    cout << *it << ">";

    return 0;
}
