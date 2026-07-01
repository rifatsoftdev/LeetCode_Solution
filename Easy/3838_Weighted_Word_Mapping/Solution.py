from typing import List, Optional


class Solution:
    def mapWordWeights(self, words: List[str], weights: List[int]) -> str:
        result = ""

        for word in words:
            num = 0

            for ch in word:
                num += weights[ord(ch) - ord('a')]

            result += chr(ord('z') - (num % 26))

        return result


if __name__ == "__main__":
    solution = Solution()

    # test cases 1
    words1 = ["abcd","def","xyz"]
    weights1 = [5,3,12,14,1,2,3,2,10,6,6,9,7,8,7,10,8,9,6,9,9,8,3,7,7,2]
    print(solution.mapWordWeights(words1, weights1))    # Expected output: "rij"
    
    # test cases 2
    words2 = ["a","b","c"]
    weights2 = [1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1]
    print(solution.mapWordWeights(words2, weights2))    # Expected output: "yyy"
    
    # test cases 3
    words3 = ["abcd"]
    weights3 = [7,5,3,4,3,5,4,9,4,2,2,7,10,2,5,10,6,1,2,2,4,1,3,4,4,5]
    print(solution.mapWordWeights(words3, weights3))    # Expected output: "g"
        
    
    