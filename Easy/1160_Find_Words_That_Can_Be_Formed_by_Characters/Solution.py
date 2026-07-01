from typing import List, Optional


class Solution:
    def countCharacters(self, words: List[str], chars: str) -> int:
        freq = [0] * 26

        for i in chars:
            freq[ord(i) - ord('a')] += 1

        ans = 0

        for word in words:
            temp = freq.copy()
            good = True

            for ch in word:
                if temp[ord(ch) - ord('a')] > 0:
                    temp[ord(ch) - ord('a')] -= 1
                else:
                    good = False
                    break
                
            if (good):
                ans += len(word)

        return ans


if __name__ == "__main__":
    solution = Solution()

    # test cases 1
    words1 = ["cat", "bt", "hat", "tree"]
    chars1 = "atach"
    print(solution.countCharacters(words1, chars1))  # Output: 6
    
    # test cases 2
    words2 = ["hello", "world", "leetcode"]
    chars2 = "welldonehoneyr"
    print(solution.countCharacters(words2, chars2))  # Output: 10
    
    