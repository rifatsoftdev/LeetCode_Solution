from typing import List, Optional


class Solution:
    def convertTemperature(self, celsius: float) -> List[float]:
        kelvin = celsius + 273.15;
        fahrenheit = celsius * 1.80 + 32.00;

        return [kelvin, fahrenheit];


if __name__ == "__main__":
    solution = Solution()

    # test cases 1
    celsius1 = 36.50;
    result1 = solution.convertTemperature(celsius1);
    print(result1);

    # test cases 2
    celsius2 = 122.11;
    result2 = solution.convertTemperature(celsius2);
    print(result2);
    