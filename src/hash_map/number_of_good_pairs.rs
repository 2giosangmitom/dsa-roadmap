use std::collections::HashMap;

struct Solution;

impl Solution {
    pub fn num_identical_pairs(nums: Vec<i32>) -> i32 {
        let mut counts: HashMap<i32, i32> = HashMap::new();
        let mut result = 0;

        for num in nums {
            let entry = counts.entry(num).or_insert(0);
            result += *entry;
            *entry += 1;
        }

        result
    }
}

#[cfg(test)]
mod tests {
    use super::Solution;
    use rstest::rstest;

    #[rstest]
    #[case(vec![1, 2, 3, 1, 1, 3], 4)]
    #[case(vec![1, 1, 1, 1], 6)]
    #[case(vec![1, 2, 3], 0)]
    fn test_num_identical_pairs(#[case] nums: Vec<i32>, #[case] expected: i32) {
        assert_eq!(Solution::num_identical_pairs(nums), expected);
    }
}
