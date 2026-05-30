struct Solution;

impl Solution {
    pub fn max_sub_array(nums: Vec<i32>) -> i32 {
        let mut max_ending = nums[0];
        let mut max_sofar = nums[0];
        for &num in nums.iter().skip(1) {
            max_ending = num.max(max_ending + num);
            max_sofar = max_sofar.max(max_ending);
        }
        max_sofar
    }
}

#[cfg(test)]
mod tests {
    use super::*;
    use rstest::rstest;

    #[rstest]
    #[case(vec![-2, 1, -3, 4, -1, 2, 1, -5, 4], 6)]
    #[case(vec![1], 1)]
    #[case(vec![5, 4, -1, 7, 8], 23)]
    fn test_max_sub_array(#[case] nums: Vec<i32>, #[case] expected: i32) {
        assert_eq!(Solution::max_sub_array(nums), expected);
    }
}
