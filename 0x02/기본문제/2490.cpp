#include <bits/stdc++.h>
using namespace std;

int main(){
    for(int i = 0; i < 3; i++){
        int a,b,c,d;
        cin >> a >> b >> c >> d;
        int t[4] = {a,b,c,d};

        int fcnt = 0;

        for(int j = 0; j < 4; j++){
            if(t[j] == 0) fcnt++;
        }

        if(fcnt == 1) cout << "A\n";
        else if(fcnt == 2) cout << "B\n";
        else if(fcnt == 3) cout << "C\n";
        else if(fcnt == 4) cout << "D\n";
        else if(fcnt == 0) cout << "E\n";
    }
    return 0;
}


//바킹독 답
#include <bits/stdc++.h>
using namespace std;

int result, input;
string res = "DCBAE";

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);
    
  for(int r = 0; r < 3; r++) {
    result = 0;
    for(int c = 0; c < 4; c++) {
      cin >> input;
      result += input;
    }
    cout << res[result] << '\n';
  }
}