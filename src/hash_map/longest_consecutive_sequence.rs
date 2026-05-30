use std::collections::HashSet;

struct Solution;

impl Solution {
    pub fn longest_consecutive(nums: Vec<i32>) -> i32 {
        let set: HashSet<i32> = nums.into_iter().collect();
        let mut best = 0;

        for &num in &set {
            if !set.contains(&(num - 1)) {
                let mut current = num;
                let mut length = 1;
                while set.contains(&(current + 1)) {
                    current += 1;
                    length += 1;
                }
                best = best.max(length);
            }
        }

        best
    }
}

#[cfg(test)]
mod tests {
    use super::Solution;
    use rstest::rstest;

    #[rstest]
    #[case(vec![100, 4, 200, 1, 3, 2], 4)]
    #[case(vec![0, 3, 7, 2, 5, 8, 4, 6, 0, 1], 9)]
    #[case(vec![], 0)]
    fn test_longest_consecutive(#[case] nums: Vec<i32>, #[case] expected: i32) {
        assert_eq!(Solution::longest_consecutive(nums), expected);
    }
}
