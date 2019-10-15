#include <vector>

using namespace std;

vector<vector<int>> generate(int numRows) {

  vector<vector<int>> answer;

  if( numRows < 1 )
    return answer;

  int i=0;
  int j=0;
  while(i < numRows){
    vector<int> vi;

    if( i == 0) {
      vi.push_back(1);
    }
    else if( i == 1) {
      vi.push_back(i);
      vi.push_back(i);
    }
    else {
      while(j < answer[i-1].size()) {
        if( j == 0) {
          vi.push_back(1);
        }
        else {
          int l = answer[i-1][j-1];
          int r = answer[i-1][j];
          vi.push_back(l+r);
        }
        j++;
      }
      vi.push_back(1);
      j=0;
    }
    answer.push_back(vi);
    i++;
  }
  return answer;
}

int main(){

  vector<vector<int>> an = generate(5);
  return 0;
}

