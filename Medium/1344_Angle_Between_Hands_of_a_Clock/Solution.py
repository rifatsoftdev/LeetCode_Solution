from typing import List, Optional


class Solution:
    def angleClock(self, hour: int, minutes: int) -> float:
        # Degree per minute: 360 / 60 = 6
        # Degree per hour: 360 / 12 = 30
        # Additional degree per hour hand per minute: 30 / 60 = 0.5
        
        minute_angle = minutes * 6
        hour_angle = (hour % 12) * 30 + minutes * 0.5
        
        angle = abs(hour_angle - minute_angle)
        return min(angle, 360 - angle)
        


if __name__ == "__main__":
    solution = Solution()

    # test cases 1
    hour1, minutes1 = 12, 30
    print(solution.angleClock(hour1, minutes1))
    
    # test cases 2
    hour2, minutes2 = 3, 30
    print(solution.angleClock(hour2, minutes2))

    # test cases 3
    hour3, minutes3 = 3, 15
    print(solution.angleClock(hour3, minutes3))
    
    