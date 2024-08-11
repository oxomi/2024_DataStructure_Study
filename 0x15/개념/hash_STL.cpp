#include <bits/stdc++.h>
using namespace std;

// 원소의 중복이 허용되지 않는 set
void unordered_set_example(){
  unordered_set<int> s;
  s.insert(-10); s.insert(100); s.insert(15); // {-10, 100, 15}
  s.insert(-10); // {-10, 100, 15}    
  cout << s.erase(100) << '\n'; // {-10, 15}, 1  // 인자가 셋 안에 들어있으면 1을 반환
  cout << s.erase(20) << '\n'; // {-10, 15}, 0  // 없으면 0 반환
  if(s.find(15) != s.end()) cout << "15 in s\n";  // find() 함수 - 값이 있다면 iterator를 반환, 없으면 s.end()를 반환
  else cout << "15 not in s\n";
  cout << s.size() << '\n'; // 2
  cout << s.count(50) << '\n'; // 0
  for(auto e : s) cout << e << ' '; // 해시의 특성상 원소들이 크기 혹은 삽입한 순서대로 위치하지 않아 값이 뒤죽박죽 출력된다
  cout << '\n';
}

// 원소의 중복이 허용되는 set
void unordered_multiset_example(){
  unordered_multiset<int> ms;
  ms.insert(-10); ms.insert(100); ms.insert(15); // {-10, 100, 15}
  ms.insert(-10); ms.insert(15); // {-10, -10, 100, 15, 15}
  cout << ms.size() << '\n'; // 5
  for(auto e : ms) cout << e << ' ';
  cout << '\n';
  cout << ms.erase(15) << '\n'; // {-10, -10, 100}, 2  // 주의 - multiset에서는 인자에 해당하는 모든 값이 지워짐
  ms.erase(ms.find(-10)); // {-10, 100}  // 이렇게 해야 하나만 딱 지운다
  ms.insert(100); // {-10, 100, 100}
  cout << ms.count(100) << '\n'; // 2
}

// 키에 대응되는 값을 찾아주는 STL
void unordered_map_example(){
  unordered_map<string, int> m; //<키의 자료형, 값의 자료형>
  m["hi"] = 123;
  m["bkd"] = 1000;
  m["gogo"] = 165; // ("hi", 123), ("bkd", 1000), ("gogo", 165)
  cout << m.size() << '\n'; // 3
  m["hi"] = -7;  // ("hi", -7), ("bkd", 1000), ("gogo", 165)
  if(m.find("hi") != m.end()) cout << "hi in m\n";
  else cout << "hi not in m\n";
  m.erase("bkd"); // ("hi", 123), ("gogo", 165)
  for(auto e : m)
    cout << e.first << ' ' << e.second << '\n';
}

int main(void){ 
  unordered_set_example();  
  unordered_multiset_example();
  unordered_map_example();
}