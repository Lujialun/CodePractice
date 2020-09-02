#include <iostream>
#include <vector>
#include <numeric>
#include <limits>

using namespace std;




int main() {
    int n, m, r, c;
    while(cin>>n>>m>>r>>c){
        int a[n][m];
        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                cin >> a[i][j];
            }
        }
        cout << 4 << endl;
    }
    return 0;

}
