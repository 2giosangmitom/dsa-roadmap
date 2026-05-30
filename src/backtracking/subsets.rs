struct Solution;

impl Solution {
    pub fn subsets(nums: Vec<i32>) -> Vec<Vec<i32>> {
        let n = nums.len();
        let mut result = Vec::with_capacity(1 << n);
        for mask in 0..(1 << n) {
            let mut subset = Vec::new();
            for (i, &val) in nums.iter().enumerate().take(n) {
                if mask & (1 << i) != 0 {
                    subset.push(val);
                }
            }
            result.push(subset);
        }
        result
    }
}

#[cfg(test)]
mod tests {
    use super::Solution;
    use rstest::rstest;

    #[rstest]
    #[case(vec![1, 2, 3], vec![
        vec![], vec![1], vec![2], vec![1, 2],
        vec![3], vec![1, 3], vec![2, 3], vec![1, 2, 3],
    ])]
    #[case(vec![0], vec![vec![], vec![0]])]
    fn test_subsets(#[case] nums: Vec<i32>, #[case] expected: Vec<Vec<i32>>) {
        assert_eq!(Solution::subsets(nums), expected);
    }
}
