struct Solution;

impl Solution {
    pub fn search_range(nums: Vec<i32>, target: i32) -> Vec<i32> {
        let left = Self::lower_bound(&nums, target);
        let right = Self::lower_bound(&nums, target + 1) as i32 - 1;

        if left == nums.len() || nums[left] != target {
            vec![-1, -1]
        } else {
            vec![left as i32, right]
        }
    }

    fn lower_bound(nums: &[i32], target: i32) -> usize {
        let mut left = 0;
        let mut right = nums.len();
        while left < right {
            let mid = left + (right - left) / 2;
            if nums[mid] < target {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        left
    }
}

#[cfg(test)]
mod tests {
    use super::Solution;
    use rstest::rstest;

    #[rstest]
    #[case(vec![5, 7, 7, 8, 8, 10], 8, vec![3, 4])]
    #[case(vec![5, 7, 7, 8, 8, 10], 6, vec![-1, -1])]
    #[case(vec![], 0, vec![-1, -1])]
    fn test_search_range(#[case] nums: Vec<i32>, #[case] target: i32, #[case] expected: Vec<i32>) {
        assert_eq!(Solution::search_range(nums, target), expected);
    }
}
