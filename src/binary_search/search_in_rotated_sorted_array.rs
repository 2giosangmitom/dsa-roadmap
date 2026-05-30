struct Solution;

impl Solution {
    pub fn search(nums: Vec<i32>, target: i32) -> i32 {
        if nums.is_empty() {
            return -1;
        }

        let mut left: i32 = 0;
        let mut right: i32 = nums.len() as i32 - 1;

        while left <= right {
            let mid = left + (right - left) / 2;
            let mid_val = nums[mid as usize];

            if mid_val == target {
                return mid;
            }

            if nums[left as usize] <= mid_val {
                if nums[left as usize] <= target && target < mid_val {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            } else if mid_val < target && target <= nums[right as usize] {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        -1
    }
}

#[cfg(test)]
mod tests {
    use super::Solution;
    use rstest::rstest;

    #[rstest]
    #[case(vec![4, 5, 6, 7, 0, 1, 2], 0, 4)]
    #[case(vec![4, 5, 6, 7, 0, 1, 2], 3, -1)]
    #[case(vec![1], 0, -1)]
    fn test_search(#[case] nums: Vec<i32>, #[case] target: i32, #[case] expected: i32) {
        assert_eq!(Solution::search(nums, target), expected);
    }
}
