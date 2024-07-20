//정확한 코드 아니니까 이런 방법이 잇다는 것만 활용하기
int func2(int arr[], int N){
  int occur[101] = {};
  for(int i = 0; i < N; i++){
    if(occur[100-arr[i]] == 1)
      return 1;
    occur[arr[i]] = 1;
  }
  return 0;
}