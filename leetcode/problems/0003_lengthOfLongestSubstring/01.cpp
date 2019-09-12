#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.empty()) {
            return 0;
        }
        int visited[256];
        int max_length = 1;
        for (int i = 0; i < s.size(); ++i) {
            memset(visited, 0, sizeof(visited));
            int j = i;
            for (; j < s.size(); ++j) {
                if (visited[s[j]] == 1) {
                    // std::cout << "meet" << endl;
                    break;
                } else {
                    // std::cout << "nomeet" << endl;
                    visited[s[j]] = 1;
                }
            }
            max_length = (j - i) > max_length ? (j - i) : max_length;
            // cout << max_length << ":" << i << ":" << j << endl;
        }
        return max_length;
    }
    int lengthOfLongestSubstring1(string s) {
        if (s.empty()) {
            return 0;
        }
        int max_length = 1;
        for (int i = 0; i + 1 < s.size(); ++i) {
            for (int j = i + 1; j < s.size(); ++j) {
                if (!has_repeated1(s, i, j) && j - i + 1 > max_length) {
                    max_length = j - i + 1;
                }
            }
        }
        return max_length;
    }
    bool has_repeated1(const string& str, int s, int e) {
        for (int i = s; i + 1 <= e; ++i) {
            for (int j = i + 1; j <= e; ++j) {
                if (str[i] == str[j]) {
                    return true;
                }
            }
        }
        return false;
    }
};

int main() {
    Solution solution;
    string str = "abcabcbb";
    cout << solution.lengthOfLongestSubstring(str) << endl;
    return 0;
}
