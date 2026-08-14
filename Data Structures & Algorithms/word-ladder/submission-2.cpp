class Solution {
   public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> words(wordList.begin(), wordList.end());
        if (!words.count(endWord)) return 0;
        queue<string> q;
        q.push(beginWord);
        int distance = 0;

        while (!q.empty()) {
            int n = q.size();
            while (n--) {
                string word = q.front();
                q.pop();

                if (word == endWord) return distance+1;

                for (int i = 0; i < word.size(); i++) {
                    string original = word;
                    for (char c = 'a'; c <= 'z'; c++) {
                        word[i] = c;

                        if (words.count(word)) {
                            q.push(word);
                            words.erase(word);
                        }
                    }
                    word = original;
                }
            }

            distance++;
        }
        return 0;
    }
};
