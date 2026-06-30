#include <iostream>
#include <vector>
#include <string>

using namespace std;
//leetcode sol starts from here
class Solution {
public:
    vector<string> ans;

    void dfs(string &num, int target, int pos,
             long long eval, long long prev,
             string path) {

        if (pos == num.size()) {
            if (eval == target)
                ans.push_back(path);
            return;
        }

        for (int i = pos; i < num.size(); i++) {

            if (i != pos && num[pos] == '0')
                break;

            string curStr = num.substr(pos, i - pos + 1);
            long long cur = stoll(curStr);

            if (pos == 0) {
                dfs(num, target, i + 1, cur, cur, curStr);
            } else {

                dfs(num, target, i + 1,
                    eval + cur,
                    cur,
                    path + "+" + curStr);

                dfs(num, target, i + 1,
                    eval - cur,
                    -cur,
                    path + "-" + curStr);

                dfs(num, target, i + 1,
                    eval - prev + prev * cur,
                    prev * cur,
                    path + "*" + curStr);
            }
        }
    }

    vector<string> addOperators(string num, int target) {
        dfs(num, target, 0, 0, 0, "");
        return ans;
    }
};

int main() {
    Solution obj;

    string num = "123";
    int target = 6;

    vector<string> ans = obj.addOperators(num, target);

    for (string s : ans)
        cout << s << endl;

    return 0;
}