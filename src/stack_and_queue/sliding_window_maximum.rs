use std::collections::VecDeque;

struct Solution;

impl Solution {
    pub fn max_sliding_window(nums: Vec<i32>, k: i32) -> Vec<i32> {
        let k = k as usize;
        let mut deque: VecDeque<usize> = VecDeque::new();
        let mut result = Vec::new();

        for i in 0..nums.len() {
            while let Some(&front) = deque.front() {
                if front + k <= i {
                    deque.pop_front();
                } else {
                    break;
                }
            }

            while let Some(&back) = deque.back() {
                if nums[back] <= nums[i] {
                    deque.pop_back();
                } else {
                    break;
                }
            }

            deque.push_back(i);

            if i >= k - 1 {
                result.push(nums[*deque.front().unwrap()]);
            }
        }

        result
    }
}

#[cfg(test)]
mod tests {
    use super::*;
    use rstest::rstest;

    #[rstest]
    #[case(vec![1,3,-1,-3,5,3,6,7], 3, vec![3,3,5,5,6,7])]
    #[case(vec![1], 1, vec![1])]
    fn test_max_sliding_window(#[case] nums: Vec<i32>, #[case] k: i32, #[case] expected: Vec<i32>) {
        assert_eq!(Solution::max_sliding_window(nums, k), expected);
    }
}
