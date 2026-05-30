struct Solution;

impl Solution {
    pub fn can_jump(nums: Vec<i32>) -> bool {
        let mut max_reach = 0;
        for (i, &step) in nums.iter().enumerate() {
            if i > max_reach {
                return false;
            }
            max_reach = max_reach.max(i + step as usize);
        }
        true
    }
}

#[cfg(test)]
mod tests {
    use super::*;
    use rstest::rstest;

    #[rstest]
    #[case(vec![2, 3, 1, 1, 4], true)]
    #[case(vec![3, 2, 1, 0, 4], false)]
    fn test_can_jump(#[case] nums: Vec<i32>, #[case] expected: bool) {
        assert_eq!(Solution::can_jump(nums), expected);
    }
}
