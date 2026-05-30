struct Solution;

impl Solution {
    pub fn product_except_self(nums: Vec<i32>) -> Vec<i32> {
        let n = nums.len();
        let mut result = vec![1; n];

        let mut prefix = 1;
        for i in 0..n {
            result[i] = prefix;
            prefix *= nums[i];
        }

        let mut suffix = 1;
        for i in (0..n).rev() {
            result[i] *= suffix;
            suffix *= nums[i];
        }

        result
    }
}

#[cfg(test)]
mod tests {
    use super::*;
    use rstest::rstest;

    #[rstest]
    #[case(vec![1,2,3,4], vec![24,12,8,6])]
    #[case(vec![-1,1,0,-3,3], vec![0,0,9,0,0])]
    fn test_product_except_self(#[case] nums: Vec<i32>, #[case] expected: Vec<i32>) {
        assert_eq!(Solution::product_except_self(nums), expected);
    }
}
