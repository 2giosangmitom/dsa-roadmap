struct Solution;

impl Solution {
    pub fn subsets_with_dup(nums: Vec<i32>) -> Vec<Vec<i32>> {
        let mut nums = nums;
        nums.sort_unstable();
        let mut result = Vec::new();
        let mut current = Vec::new();
        Self::backtrack(&nums, 0, &mut current, &mut result);
        result
    }

    fn backtrack(nums: &[i32], start: usize, current: &mut Vec<i32>, result: &mut Vec<Vec<i32>>) {
        result.push(current.clone());
        for i in start..nums.len() {
            if i > start && nums[i] == nums[i - 1] {
                continue;
            }
            current.push(nums[i]);
            Self::backtrack(nums, i + 1, current, result);
            current.pop();
        }
    }
}

#[cfg(test)]
mod tests {
    use super::Solution;
    use rstest::rstest;

    #[rstest]
    #[case(vec![1, 2, 2], vec![
        vec![], vec![1], vec![1, 2], vec![1, 2, 2],
        vec![2], vec![2, 2],
    ])]
    #[case(vec![0], vec![vec![], vec![0]])]
    fn test_subsets_with_dup(#[case] nums: Vec<i32>, #[case] expected: Vec<Vec<i32>>) {
        assert_eq!(Solution::subsets_with_dup(nums), expected);
    }
}
