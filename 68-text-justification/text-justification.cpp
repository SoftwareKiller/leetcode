class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> ans;
        vector<string> currentLine;
        int currentLength = 0;
        for(const string& word : words) {
            if (currentLength + word.length() + currentLine.size() > maxWidth) {
                // 处理当前行的对齐
                int totalSpaces = maxWidth - currentLength;
                int gaps = currentLine.size() - 1;

                string line;
                if (gaps == 0) {
                    line = currentLine[0] + string(totalSpaces, ' ');
                } else {
                    int spacePerGap = totalSpaces / gaps;
                    int extraSpaces = totalSpaces % gaps;
                    line = currentLine[0];
                    for (int i = 1; i < currentLine.size(); i++) {
                        int spaces = spacePerGap + (i <= extraSpaces ? 1 : 0);
                        line += string(spaces, ' ') + currentLine[i];
                    }
                }

                ans.push_back(line);
                currentLine.clear();
                currentLength = 0;
            }

            currentLine.push_back(word);
            currentLength += word.length();
        }

        string lastline;
        for(int i = 0; i < currentLine.size(); i++) {
            if (i > 0) lastline += " ";
            lastline += currentLine[i];
        }
        lastline += string(maxWidth - lastline.length(), ' ');
        ans.push_back(lastline);

        return ans;
    }
};