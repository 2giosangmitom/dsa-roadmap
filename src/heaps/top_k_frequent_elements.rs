use std::collections::{BinaryHeap, HashMap};

struct Solution;

impl Solution {
    pub fn top_k_frequent(nums: Vec<i32>, k: i32) -> Vec<i32> {
        let mut freq = HashMap::new();
        for num in nums {
            *freq.entry(num).or_insert(0) += 1;
        }

        let mut heap = BinaryHeap::with_capacity(freq.len());
        for (num, count) in freq {
            heap.push((count, num));
        }

        let mut res = Vec::with_capacity(k as usize);
        for _ in 0..k {
            res.push(heap.pop().unwrap().1);
        }
        res
    }
}

#[cfg(test)]
mod tests {
    use super::*;
    use rstest::rstest;

    #[rstest]
    #[case(vec![1, 1, 1, 2, 2, 3], 2, vec![1, 2])]
    #[case(vec![1], 1, vec![1])]
    fn test_top_k_frequent(#[case] nums: Vec<i32>, #[case] k: i32, #[case] mut expected: Vec<i32>) {
        let mut result = Solution::top_k_frequent(nums, k);
        result.sort();
        expected.sort();
        assert_eq!(result, expected);
    }
}
