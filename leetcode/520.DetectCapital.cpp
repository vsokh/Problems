class Solution {
public:
    bool detectCapitalUse(string word) {
        auto isCapital = [](char ch) {
            return 65 <= ch && ch <= 90;
        };

        auto capitalsNum = count_if(word.begin(), word.end(),
                                    [isCapital](char ch) {
                                        return isCapital(ch);
                                    });
        auto n = word.size();
        if (capitalsNum == 1 && isCapital(word[0])) {
            return true;
        }
        return n == capitalsNum || capitalsNum == 0;
    }
};

int main()
{
    return 0;
}

