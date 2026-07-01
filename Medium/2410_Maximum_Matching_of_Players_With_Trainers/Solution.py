from typing import List, Optional


class Solution:
    def matchPlayersAndTrainers(self, players: List[int], trainers: List[int]) -> int:
        players.sort()
        trainers.sort()

        child = 0
        cookie = 0

        while (child < len(players) and cookie < len(trainers)):
            if (trainers[cookie] >= players[child]):
                child += 1
            
            cookie += 1
        
        return child


if __name__ == "__main__":
    solution = Solution()

    # test cases 1
    players1 = [4, 7, 9]
    trainers1 = [8, 2, 5, 8]
    print(solution.matchPlayersAndTrainers(players1, trainers1))  # Expected output: 2
    
    # test cases 2
    players2 = [1, 1, 1]
    trainers2 = [10]
    print(solution.matchPlayersAndTrainers(players2, trainers2))  # Expected output: 1
        
    