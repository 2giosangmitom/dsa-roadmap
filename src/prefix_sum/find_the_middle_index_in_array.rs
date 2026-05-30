struct Solution;

impl Solution {
    pub fn find_middle_index(nums: Vec<i32>) -> i32 {
        let total: i32 = nums.iter().sum();
        let mut left_sum = 0;
        for (i, &num) in nums.iter().enumerate() {
            if left_sum == total - left_sum - num {
                return i as i32;
            }
            left_sum += num;
        }
        -1
    }
}

#[cfg(test)]
mod tests {
    use super::*;
    use rstest::rstest;

    #[rstest]
    #[case(vec![2,3,-1,8,4], 3)]
    #[case(vec![1,-1,4], 2)]
    #[case(vec![2,5], -1)]
    fn test_find_middle_index(#[case] nums: Vec<i32>, #[case] expected: i32) {
        assert_eq!(Solution::find_middle_index(nums), expected);
    }
}
