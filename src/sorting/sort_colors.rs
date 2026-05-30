struct Solution;

impl Solution {
    pub fn sort_colors(nums: &mut [i32]) {
        let (mut left, mut right) = (0, nums.len() as i32 - 1);
        let mut i = 0;

        while i as i32 <= right {
            match nums[i] {
                0 => {
                    nums.swap(i, left as usize);
                    left += 1;
                    i += 1;
                }
                2 => {
                    nums.swap(i, right as usize);
                    right -= 1;
                }
                _ => i += 1,
            }
        }
    }
}

#[cfg(test)]
mod tests {
    use super::*;
    use rstest::rstest;

    #[rstest]
    #[case(vec![2, 0, 2, 1, 1, 0], vec![0, 0, 1, 1, 2, 2])]
    #[case(vec![2, 0, 1], vec![0, 1, 2])]
    fn test_sort_colors(#[case] mut nums: Vec<i32>, #[case] expected: Vec<i32>) {
        Solution::sort_colors(&mut nums);
        assert_eq!(nums, expected);
    }
}
