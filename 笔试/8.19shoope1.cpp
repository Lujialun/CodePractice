#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
#include<queue>
#include<map>
#include<set>

using namespace std;

int main()
{
    string s;
    while(cin>>s){
        cout << "\"";
        for (int i = 0; i < s.size() - 3; i++){
            if(s[i]!='['&&s[i]!=']'&&s[i]!=','&&s[i]!='"')
            {
                cout << s[i] << "\\"<< "n";
            }

        }
        cout << s[s.size() - 3] << "\"" << endl;
    }

    system("pause");
    return 0;
}