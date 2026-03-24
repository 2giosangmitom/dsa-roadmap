struct Solution;

impl Solution {
    fn helper(
        nums: &[i32],
        result: &mut Vec<Vec<i32>>,
        used: &mut [bool],
        current_permutation: &mut Vec<i32>,
        n: usize,
        current_permutation_len: usize,
    ) {
        if current_permutation_len == n {
            result.push(current_permutation.clone());
            return;
        }

        for i in 0..n {
            if !used[i] {
                used[i] = true;
                current_permutation[current_permutation_len] = nums[i];
                Self::helper(
                    nums,
                    result,
                    used,
                    current_permutation,
                    n,
                    current_permutation_len + 1,
                );
                used[i] = false;
            }
        }
    }

    pub fn permute(nums: Vec<i32>) -> Vec<Vec<i32>> {
        let n = nums.len();
        let mut current_permutation = vec![0; n];
        let mut result: Vec<Vec<i32>> = Vec::new();
        let mut used = vec![false; n];

        Self::helper(
            &nums,
            &mut result,
            &mut used,
            &mut current_permutation,
            n,
            0,
        );

        result
    }
}

#[cfg(test)]
mod tests {
    use super::Solution;
    use rstest::rstest;

    #[rstest]
    #[case(vec![1, 2, 3], vec![vec![1, 2, 3], vec![1, 3, 2], vec![2, 1, 3], vec![2, 3, 1], vec![3, 1, 2], vec![3, 2, 1]])]
    #[case(vec![0, 1], vec![vec![0, 1], vec![1, 0]])]
    #[case(vec![1], vec![vec![1]])]
    fn test_permute(#[case] nums: Vec<i32>, #[case] expected: Vec<Vec<i32>>) {
        assert_eq!(Solution::permute(nums), expected);
    }
}
