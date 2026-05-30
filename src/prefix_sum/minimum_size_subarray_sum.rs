struct Solution;

impl Solution {
    pub fn min_sub_array_len(target: i32, nums: Vec<i32>) -> i32 {
        let mut left = 0;
        let mut sum = 0;
        let mut min_len = i32::MAX;

        for right in 0..nums.len() {
            sum += nums[right];
            while sum >= target {
                min_len = min_len.min((right - left + 1) as i32);
                sum -= nums[left];
                left += 1;
            }
        }

        if min_len == i32::MAX { 0 } else { min_len }
    }
}

#[cfg(test)]
mod tests {
    use super::*;
    use rstest::rstest;

    #[rstest]
    #[case(7, vec![2,3,1,2,4,3], 2)]
    #[case(4, vec![1,4,4], 1)]
    #[case(11, vec![1,1,1,1,1,1,1,1], 0)]
    fn test_min_sub_array_len(#[case] target: i32, #[case] nums: Vec<i32>, #[case] expected: i32) {
        assert_eq!(Solution::min_sub_array_len(target, nums), expected);
    }
}
