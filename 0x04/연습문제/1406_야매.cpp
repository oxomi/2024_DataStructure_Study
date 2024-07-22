//insert, erase, traverse는 자료형의 변동을 제외하고 형식 동일하게 짜면 됨
#include <bits/stdc++.h>
using namespace std;

const int MX = 1000005; //입력할 문자열의 최대 길이가 100000이므로 여유롭게 이렇게 설정
char dat[MX];
int pre[MX];
int nxt[MX];
int unused = 1;


void insert(int addr, char num){
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
  int cur = nxt[0]; //0번지-더미노드
  while(cur != -1){
    cout << dat[cur];
    cur = nxt[cur];
  }
}


int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  fill(pre,pre+MX,-1);
  fill(nxt,nxt+MX,-1);

  string word;
  cin >> word;
  
  int M;
  cin >> M;


  //처음에는 커서가 더미노드 뒤에 위치해야 함
  //즉, 야매에서는 더미노드가 맨앞에 있으므로 커서는 커서 앞의 노드를 가리킨다고 생각하면 쉬움
  int cursor = 0;
  for(auto c : word){
    insert(cursor, c); 
    cursor++;
  }

  for(int i = 0; i < M; i++){
    char op, add;
    cin >> op;
    if(op == 'L'){
      if(pre[cursor] != -1) cursor = pre[cursor];
    }
    else if(op =='D'){
      if(nxt[cursor] != -1) cursor = nxt[cursor];
    }
    else if(op == 'B'){
      if(pre[cursor] != -1){
        erase(cursor);
        cursor = pre[cursor];
      }
    }
    else{ // op == 'P'
      cin >> add;
      insert(cursor, add);
      cursor = nxt[cursor];
    }

  }
  traverse();
}












// //답

// #include <bits/stdc++.h>
// using namespace std;

// const int MX = 1000005;
// char dat[MX];
// int pre[MX]; 
// int nxt[MX];
// int unused = 1;

// void insert(int addr, char num){
//   dat[unused] = num;
//   pre[unused] = addr;
//   nxt[unused] = nxt[addr];
//   if(nxt[addr] != -1) pre[nxt[addr]] = unused;
//   nxt[addr] = unused;
//   unused++;
// }

// void erase(int addr){
//   nxt[pre[addr]] = nxt[addr];
//   if(nxt[addr] != -1) pre[nxt[addr]] = pre[addr];
// }

// void traversal(){
//   int cur = nxt[0];
//   while(cur != -1){
//     cout << dat[cur];
//     cur = nxt[cur];
//   }
// }

// int main(void) {
//   ios::sync_with_stdio(0);
//   cin.tie(0);
//   fill(pre,pre+MX,-1);
//   fill(nxt,nxt+MX,-1);
//   string init;
//   cin >> init;
//   int cursor = 0;
//   for(auto c : init){
//     insert(cursor, c);
//     cursor++;
//   }  
//   int q;
//   cin >> q;
//   while (q--) {
//     char op;
//     cin >> op;
//     if (op == 'P') {
//       char add;
//       cin >> add;
//       insert(cursor, add);
//       cursor = nxt[cursor];
//     }
//     else if (op == 'L') {
//       if (pre[cursor] != -1) cursor = pre[cursor];
//     }
//     else if (op == 'D') {
//       if (nxt[cursor] != -1) cursor = nxt[cursor];
//     }
//     else { // 'B'
//       if (pre[cursor] != -1) {
//         erase(cursor);
//         cursor = pre[cursor];
//       }
//     }
//   }
//   traversal();
// }


