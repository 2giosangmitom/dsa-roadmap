use std::collections::BinaryHeap;

struct Solution;

impl Solution {
    pub fn find_kth_largest(nums: Vec<i32>, k: i32) -> i32 {
        let mut heap = BinaryHeap::from(nums);
        for _ in 1..k {
            heap.pop();
        }
        heap.pop().unwrap()
    }
}

#[cfg(test)]
mod tests {
    use super::*;
    use rstest::rstest;

    #[rstest]
    #[case(vec![3, 2, 1, 5, 6, 4], 2, 5)]
    #[case(vec![3, 2, 3, 1, 2, 4, 5, 5, 6], 4, 4)]
    fn test_find_kth_largest(#[case] nums: Vec<i32>, #[case] k: i32, #[case] expected: i32) {
        assert_eq!(Solution::find_kth_largest(nums, k), expected);
    }
}
