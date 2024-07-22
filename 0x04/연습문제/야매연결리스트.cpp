//야매 연결리스트에서는 제일 앞의 0번지를 더미 노드로 이용한다
#include <bits/stdc++.h>
using namespace std;

const int MX = 1000005;
int dat[MX];
int pre[MX];
int nxt[MX];
int unused = 1;

//주의: 삽입할 위치로서의 addr은 실질적으로 삽입할 위치 양옆중 앞의 원소의 위치라고 보면 된다
void insert(int addr, int num){
  dat[unused] = num;

  //삽입할 원소 입장에서 생각하는 부분
  pre[unused] = addr;
  nxt[unused] = nxt[addr];
  //삽입할 위치의 양옆 원소 입장에서 생각하는 부분
  if(nxt[addr] != -1) pre[nxt[addr]] = unused; //삽입할 위치의 다음 원소가 존재할때만 다음 원소의 이전 원소를 지정할 수 있게 함
  nxt[addr] = unused;
  

}

void erase(int addr){
  //pre[addr]이 -1인지는 체크 안해도 됨. 왜냐면 맨 앞에 더미노드 떄문에 어떤 원소를 지우도라도 pre[addr]은 -1이 아님이 보장됨.
  nxt[pre[addr]] = nxt[addr]; 
  if(nxt[addr] != -1) pre[nxt[addr]] = pre[addr];
}

//출력함수
void traverse(){
  int cur = nxt[0]; //0번지 더미노드의 다음값
  while(cur != -1){
    cout << dat[cur] << ' ';
    cur = nxt[cur];
  }
  cout << "\n\n";
}

void insert_test(){
  cout << "****** insert_test *****\n";
  insert(0, 10); // 10(address=1)  // 0번지는 더미 값이 있다고 가정
  traverse();
  insert(0, 30); // 30(address=2) 10
  traverse();
  insert(2, 40); // 30 40(address=3) 10
  traverse();
  insert(1, 20); // 30 40 10 20(address=4)
  traverse();
  insert(4, 70); // 30 40 10 20 70(address=5)
  traverse();
}

void erase_test(){
  cout << "****** erase_test *****\n";
  erase(1); // 30 40 20 70
  traverse();
  erase(2); // 40 20 70
  traverse();
  erase(4); // 40 70
  traverse();
  erase(5); // 40
  traverse();
}

int main(void) {
  //초기엔 pre, nxt를 전부 -1로 채워주기
  fill(pre, pre+MX, -1);
  fill(nxt, nxt+MX, -1);
  insert_test();
  erase_test();
}





//답
#include <bits/stdc++.h>
using namespace std;

const int MX = 1000005;
int dat[MX], pre[MX], nxt[MX];
int unused = 1;

void insert(int addr, int num){
  dat[unused] = num;
  pre[unused] = addr;
  nxt[unused] = nxt[addr];
  if(nxt[addr] != -1) pre[nxt[addr]] = unused;
  nxt[addr] = unused;
  unused++;
}

void erase(int addr){
  nxt[pre[addr]] = nxt[addr];
  if(nxt[addr] != -1) pre[nxt[addr]] = pre[addr];
}

void traverse(){
  int cur = nxt[0];
  while(cur != -1){
    cout << dat[cur] << ' ';
    cur = nxt[cur];
  }
  cout << "\n\n";
}

void insert_test(){
  cout << "****** insert_test *****\n";
  insert(0, 10); // 10(address=1)
  traverse();
  insert(0, 30); // 30(address=2) 10
  traverse();
  insert(2, 40); // 30 40(address=3) 10
  traverse();
  insert(1, 20); // 30 40 10 20(address=4)
  traverse();
  insert(4, 70); // 30 40 10 20 70(address=5)
  traverse();
}

void erase_test(){
  cout << "****** erase_test *****\n";
  erase(1); // 30 40 20 70
  traverse();
  erase(2); // 40 20 70
  traverse();
  erase(4); // 40 70
  traverse();
  erase(5); // 40
  traverse();
}

int main(void) {
  fill(pre, pre+MX, -1);
  fill(nxt, nxt+MX, -1);
  insert_test();
  erase_test();
}