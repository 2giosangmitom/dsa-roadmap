struct Solution;

impl Solution {
    pub fn maximum_count(nums: Vec<i32>) -> i32 {
        let first_non_negative = Self::lower_bound(&nums, 0);
        let first_positive = Self::lower_bound(&nums, 1);
        let negative = first_non_negative as i32;
        let positive = (nums.len() - first_positive) as i32;
        negative.max(positive)
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
    #[case(vec![-2, -1, -1, 1, 2, 3], 3)]
    #[case(vec![-3, -2, -1, 0, 0, 1, 2], 3)]
    #[case(vec![5, 20, 66, 1314], 4)]
    fn test_maximum_count(#[case] nums: Vec<i32>, #[case] expected: i32) {
        assert_eq!(Solution::maximum_count(nums), expected);
    }
}
