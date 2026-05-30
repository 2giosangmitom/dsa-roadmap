struct Solution;

impl Solution {
    pub fn largest_sum_after_k_negations(nums: Vec<i32>, k: i32) -> i32 {
        let mut nums = nums;
        nums.sort_unstable();
        let mut k = k;

        for n in &mut nums {
            if *n < 0 && k > 0 {
                *n = -*n;
                k -= 1;
            }
        }

        if k % 2 == 1 {
            let min_idx = nums
                .iter()
                .enumerate()
                .min_by_key(|&(_, v)| v)
                .map(|(i, _)| i)
                .unwrap();
            nums[min_idx] = -nums[min_idx];
        }

        nums.iter().sum()
    }
}

#[cfg(test)]
mod tests {
    use super::*;
    use rstest::rstest;

    #[rstest]
    #[case(vec![4, 2, 3], 1, 5)]
    #[case(vec![3, -1, 0, 2], 3, 6)]
    #[case(vec![2, -3, -1, 5, -4], 2, 13)]
    fn test_largest_sum_after_k_negations(
        #[case] nums: Vec<i32>,
        #[case] k: i32,
        #[case] expected: i32,
    ) {
        assert_eq!(Solution::largest_sum_after_k_negations(nums, k), expected);
    }
}
