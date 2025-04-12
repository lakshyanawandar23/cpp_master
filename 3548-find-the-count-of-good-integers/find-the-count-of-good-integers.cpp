class Solution {
public:
    long long countGoodIntegers(int n, int k) {
        unordered_set<string> seen; // to avoid duplicate permutations
        int count = 0;

        vector<string> palindromes = generatePalindromes(n);

        for (const string& p : palindromes) {
          //  cout<<p<<endl;
            if (stoll(p) % k != 0) continue;
            cout<<p<<endl;
            string sortedDigits = p;
            sort(sortedDigits.begin(), sortedDigits.end());

            if (seen.count(sortedDigits)) continue;

            seen.insert(sortedDigits);
            count += countValidPermutations(sortedDigits);
        }

        return count;
    }

private:
    // Generate all palindromic numbers with exactly n digits
    vector<string> generatePalindromes(int n) {
        vector<string> res;
        int half = (n + 1) / 2;
        int start = pow(10, half - 1);
        int end = pow(10, half);

        for (int i = start; i < end; ++i) {
            string left = to_string(i);
            string right = left;
            if (n % 2 == 1) right.pop_back();
            reverse(right.begin(), right.end());
            res.push_back(left + right);
        }

        return res;
    }

    // Count valid permutations of the digits that don't start with 0
    int countValidPermutations(const string& digits) {
        int n = digits.size();
        map<char, int> freq;
        for (char c : digits) freq[c]++;

        int total = factorial(n);

        for (auto& [ch, f] : freq) {
            total /= factorial(f);
        }

        // Subtract permutations that start with 0
        if (freq.count('0')) {
            freq['0']--;
            int sub = factorial(n - 1);
            for (auto& [ch, f] : freq) {
                sub /= factorial(f);
            }
            total -= sub;
            freq['0']++; // restore
        }

        return total;
    }

    int factorial(int x) {
        static vector<int> cache(11, -1);
        if (x == 0 || x == 1) return 1;
        if (cache[x] != -1) return cache[x];
        return cache[x] = x * factorial(x - 1);
    }
};