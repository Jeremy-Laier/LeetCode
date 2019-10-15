from typing import List
import simplejson as json

class Solution:
    def containsNearbyDuplicate(self, nums: List[int], k: int) -> bool:
        for i in range(len(nums)):
            for j in range(len(nums)):
                if nums[i] == nums[j] and (i != j) and (abs(i-j) <= k):
                    return True
        return False

def stringToIntegerList(input):
    return json.loads(input)

def main():
    import sys
    import io
    def readlines():
        for line in io.TextIOWrapper(sys.stdin.buffer, encoding='utf-8'):
            yield line.strip('\n')

    lines = readlines()
    while True:
        try:
            line = next(lines)
            nums = stringToIntegerList(line);
            line = next(lines)
            k = int(line);

            ret = Solution().containsNearbyDuplicate(nums, k)

            out = (ret);
            print(out)
        except StopIteration:
            break

if __name__ == '__main__':
    main()
