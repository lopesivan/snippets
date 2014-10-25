#include <algorithm>
#include <cmath>
#include <limits>
#include <vector>
using namespace std;
int solution(vector<int> &A) {
    int ans = std::numeric_limits<int>::max();
    
    int total = 0;
    for (unsigned i = 0; i < A.size(); ++i)
        total += A[i];
    
    int cum = 0;
    for (unsigned p = 1; p < A.size(); ++p) {
        cum += A[p - 1];
        ans = min(ans, abs(cum - (total - cum)));
    }
    return ans;
}
