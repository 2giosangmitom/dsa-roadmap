struct Solution;

impl Solution {
    pub fn move_zeroes(nums: &mut [i32]) {
        let (mut left, mut right) = (0, 0);
        let n = nums.len();

        while right < n {
            if nums[right] != 0 {
                nums[left] = nums[right];
                left += 1;
            }
            right += 1;
        }

        while left < n {
            nums[left] = 0;
            left += 1;
        }
    }
}

#[cfg(test)]
mod tests {
    use super::Solution;
    use rstest::rstest;

    #[rstest]
    #[case(vec![0, 1, 0, 3, 12], vec![1, 3, 12, 0, 0])]
    #[case(vec![0], vec![0])]
    #[case(vec![1, 2, 3], vec![1, 2, 3])]
    #[case(vec![0, 0, 0], vec![0, 0, 0])]
    fn test_move_zeroes(#[case] mut nums: Vec<i32>, #[case] expected: Vec<i32>) {
        Solution::move_zeroes(&mut nums);
        assert_eq!(nums, expected);
    }
}
