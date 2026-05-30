use std::collections::HashMap;

struct Solution;

impl Solution {
    pub fn contains_nearby_duplicate(nums: Vec<i32>, k: i32) -> bool {
        let mut last_index: HashMap<i32, i32> = HashMap::new();

        for (i, num) in nums.iter().enumerate() {
            let i = i as i32;
            if let Some(prev) = last_index.get(num)
                && i - prev <= k
            {
                return true;
            }
            last_index.insert(*num, i);
        }

        false
    }
}

#[cfg(test)]
mod tests {
    use super::Solution;
    use rstest::rstest;

    #[rstest]
    #[case(vec![1, 2, 3, 1], 3, true)]
    #[case(vec![1, 0, 1, 1], 1, true)]
    #[case(vec![1, 2, 3, 1, 2, 3], 2, false)]
    fn test_contains_nearby_duplicate(
        #[case] nums: Vec<i32>,
        #[case] k: i32,
        #[case] expected: bool,
    ) {
        assert_eq!(Solution::contains_nearby_duplicate(nums, k), expected);
    }
}
