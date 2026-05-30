use std::collections::HashMap;

struct Solution;

impl Solution {
    pub fn subarray_sum(nums: Vec<i32>, k: i32) -> i32 {
        let mut map = HashMap::new();
        map.insert(0, 1);
        let mut prefix = 0;
        let mut count = 0;

        for num in nums {
            prefix += num;
            count += map.get(&(prefix - k)).unwrap_or(&0);
            *map.entry(prefix).or_insert(0) += 1;
        }

        count
    }
}

#[cfg(test)]
mod tests {
    use super::*;
    use rstest::rstest;

    #[rstest]
    #[case(vec![1,1,1], 2, 2)]
    #[case(vec![1,2,3], 3, 2)]
    fn test_subarray_sum(#[case] nums: Vec<i32>, #[case] k: i32, #[case] expected: i32) {
        assert_eq!(Solution::subarray_sum(nums, k), expected);
    }
}
