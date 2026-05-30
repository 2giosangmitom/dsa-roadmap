struct Solution;

impl Solution {
    pub fn find_target_sum_ways(nums: Vec<i32>, target: i32) -> i32 {
        use std::collections::HashMap;
        let mut dp = HashMap::new();
        dp.insert(0, 1);
        for num in nums {
            let mut next = HashMap::new();
            for (sum, count) in &dp {
                *next.entry(sum + num).or_insert(0) += count;
                *next.entry(sum - num).or_insert(0) += count;
            }
            dp = next;
        }
        dp.get(&target).copied().unwrap_or(0)
    }
}

#[cfg(test)]
mod tests {
    use super::*;
    use rstest::rstest;

    #[rstest]
    #[case(vec![1, 1, 1, 1, 1], 3, 5)]
    #[case(vec![1], 1, 1)]
    fn test_find_target_sum_ways(
        #[case] nums: Vec<i32>,
        #[case] target: i32,
        #[case] expected: i32,
    ) {
        assert_eq!(Solution::find_target_sum_ways(nums, target), expected);
    }
}
