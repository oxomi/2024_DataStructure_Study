#include <bits/stdc++.h>
using namespace std;
int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  string word;
  cin >> word;
  list<char> L;
  
  for(auto c : L){
    L.push_back(c);
  }
  list<char>::iterator cursor = L.end();
   
  int M;
  cin >> M;


  //STL에서는 더미노드가 맨뒤에 있으므로 커서는 커서 뒤의 노드를 가리킨다고 생각하면 쉬움
  for(int i = 0; i < M; i++){
    char op, add;
    cin >>op;
    if (op == 'L'){
      if(cursor != L.begin()) cursor--; //이미 연결리스트 알아서 구현돼있어서 --만해줘도 됨. 이터레이터니까
    }
    else if (op == 'D') {
      if (cursor != L.end()) cursor++;
    }
    else if (op == 'B'){
      if (cursor != L.begin()) {
        //STL연결리스트의 erase함수에서는 삭제된 요소 다음의 요소를 가리키는 iterator를 반환하기 때문에 
        //현재 커서 위치의 요소를 삭제하려면 먼저 커서를 그 이전 위치로 이동시켜야 한다.
        cursor--; 
        cursor = L.erase(cursor);
      }
    }
    else{
      char add;
      cin >> add;
      L.insert(cursor, add);
    }
  }
  for(auto c: L) cout << c;
}






//답
#include <bits/stdc++.h>
using namespace std;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  string init;
  cin >> init;
  list<char> L;
  for (auto c : init) L.push_back(c);
  auto cursor = L.end();
  int q;
  cin >> q;
  while (q--) {
    char op;
    cin >> op;
    if (op == 'P') {
      char add;
      cin >> add;
      L.insert(cursor, add);
    }
    else if (op == 'L') {
      if (cursor != L.begin()) cursor--;
    }
    else if (op == 'D') {
      if (cursor != L.end()) cursor++;
    }
    else { // 'B'
      if (cursor != L.begin()) {
        cursor--;
        cursor = L.erase(cursor);
      }
    }
  }
  for (auto c : L) cout << c;
}