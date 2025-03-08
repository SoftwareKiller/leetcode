class Solution {
public:
    string simplifyPath(string path) {
        vector<string> dirs;
        stringstream ss(path);
        string dir;

        while(getline(ss, dir, '/')) {
            if (dir.empty() || dir == ".") {
                continue;
            } else if (dir == "..") {
                if (!dirs.empty()) {
                    dirs.pop_back();
                }
            } else {
                dirs.push_back(dir);
            }
        }

        string ans;
        for(const string& d : dirs) {
            ans += "/" + d;
        }

        return ans.empty() ? "/" : ans;
    }
};