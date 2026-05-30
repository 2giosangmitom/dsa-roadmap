struct Solution;

impl Solution {
    pub fn rotate(nums: &mut [i32], k: i32) {
        if nums.is_empty() {
            return;
        }

        let n = nums.len();
        let k = (k as usize) % n;

        if k == 0 {
            return;
        }

        Self::reverse(nums, 0, n - 1);
        Self::reverse(nums, 0, k - 1);
        Self::reverse(nums, k, n - 1);
    }

    fn reverse(nums: &mut [i32], mut left: usize, mut right: usize) {
        while left < right {
            nums.swap(left, right);
            left += 1;
            right = right.saturating_sub(1);
        }
    }
}

#[cfg(test)]
mod tests {
    use super::Solution;
    use rstest::rstest;

    #[rstest]
    #[case(vec![1, 2, 3, 4, 5, 6, 7], 3, vec![5, 6, 7, 1, 2, 3, 4])]
    #[case(vec![-1, -100, 3, 99], 2, vec![3, 99, -1, -100])]
    #[case(vec![1], 10, vec![1])]
    fn test_rotate(#[case] mut nums: Vec<i32>, #[case] k: i32, #[case] expected: Vec<i32>) {
        Solution::rotate(&mut nums, k);
        assert_eq!(nums, expected);
    }
}
