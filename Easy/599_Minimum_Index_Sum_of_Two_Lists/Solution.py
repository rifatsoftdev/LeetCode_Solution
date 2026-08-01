from typing import List, Optional


class Solution:
    def findRestaurant(self, list1: List[str], list2: List[str]) -> List[str]:
        dct = dict()

        for i in range(len(list1)):
            dct[list1[i]] = i

        mn = len(list1) + len(list2)
        ans = []

        for i in range(len(list2)):
            if list2[i] in dct:
                index_sum = dct[list2[i]] + i

                if index_sum < mn:
                    mn = index_sum
                    ans.clear()
                    ans.append(list2[i])
                elif index_sum == mn:
                    ans.append(list2[i])
                
        return ans


if __name__ == "__main__":
    solution = Solution()

    # test cases 1
    list11 = ["Shogun","Tapioca Express","Burger King","KFC"]
    list12 = ["Piatti","The Grill at Torrey Pines","Hungry Hunter Steakhouse","Shogun"]
    ans1 = solution.findRestaurant(list11, list12)
    print(ans1)

    # test cases 2
    list21 = ["Shogun","Tapioca Express","Burger King","KFC"]
    list22 = ["KFC","Shogun","Burger King"]
    ans2 = solution.findRestaurant(list21, list22)
    print(ans2)

    # test cases 3
    list31 = ["happy","sad","good"]
    list32 = ["sad","happy","good"]
    ans3 = solution.findRestaurant(list31, list32)
    print(ans3)
    
    