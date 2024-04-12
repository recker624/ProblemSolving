class Solution:
  def numSubseq(self, nums, target):
      nums.sort()
      mod = 1000000007
      sum_val = 0
      left = 0
      right = len(nums) - 1

      for i in range(len(nums)):
          left = i
          right_target = target - nums[left]

          if right_target < nums[left]:
              break

          right = self.findRightElement(nums, right_target, left)
          sum_val += (pow(2, right - left) - 1) 
          if nums[left] * 2 <= target:
              sum_val += 1

      return sum_val % mod

  def findRightElement(self, nums, new_target, first):
      last = len(nums) - 1
      middle = first

      while first <= last:
          middle = first + ((last - first) // 2)
          if nums[middle] < new_target:
              first = middle + 1
          elif nums[middle] > new_target:
              last = middle - 1
          elif middle + 1 < len(nums) and nums[middle + 1] == new_target:
              first = middle + 1
          else:
              return middle

      if nums[middle] > new_target:
          return middle - 1
      return middle
  
solution = Solution()
nums = [14,4,6,6,20,8,5,6,8,12,6,10,14,9,17,16,9,7,14,11,14,15,13,11,10,18,13,17,17,14,17,7,9,5,10,13,8,5,18,20,7,5,5,15,19,14]
target = 22
result = solution.numSubseq(nums, target)
print(result)