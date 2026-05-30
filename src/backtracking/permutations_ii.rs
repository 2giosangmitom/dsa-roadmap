struct Solution;

impl Solution {
    pub fn permute_unique(nums: Vec<i32>) -> Vec<Vec<i32>> {
        let mut nums = nums;
        nums.sort_unstable();
        let n = nums.len();
        let mut result = Vec::new();
        let mut current = vec![0; n];
        let mut used = vec![false; n];
        Self::backtrack(&nums, &mut result, &mut used, &mut current, 0, n);
        result
    }

    fn backtrack(
        nums: &[i32],
        result: &mut Vec<Vec<i32>>,
        used: &mut [bool],
        current: &mut Vec<i32>,
        len: usize,
        n: usize,
    ) {
        if len == n {
            result.push(current.clone());
            return;
        }
        for i in 0..n {
            if used[i] {
                continue;
            }
            if i > 0 && nums[i] == nums[i - 1] && !used[i - 1] {
                continue;
            }
            used[i] = true;
            current[len] = nums[i];
            Self::backtrack(nums, result, used, current, len + 1, n);
            used[i] = false;
        }
    }
}

#[cfg(test)]
mod tests {
    use super::Solution;
    use rstest::rstest;

    #[rstest]
    #[case(vec![1, 1, 2], vec![vec![1, 1, 2], vec![1, 2, 1], vec![2, 1, 1]])]
    #[case(vec![1, 2, 3], vec![
        vec![1, 2, 3], vec![1, 3, 2], vec![2, 1, 3],
        vec![2, 3, 1], vec![3, 1, 2], vec![3, 2, 1],
    ])]
    #[case(vec![1], vec![vec![1]])]
    fn test_permute_unique(#[case] nums: Vec<i32>, #[case] expected: Vec<Vec<i32>>) {
        assert_eq!(Solution::permute_unique(nums), expected);
    }
}
