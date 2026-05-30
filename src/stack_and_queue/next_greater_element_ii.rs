struct Solution;

impl Solution {
    pub fn next_greater_elements(nums: Vec<i32>) -> Vec<i32> {
        let n = nums.len();
        let mut result = vec![-1; n];
        let mut stack: Vec<usize> = Vec::new();
        for i in 0..2 * n {
            let idx = i % n;
            while let Some(&top) = stack.last() {
                if nums[top] < nums[idx] {
                    result[top] = nums[idx];
                    stack.pop();
                } else {
                    break;
                }
            }
            stack.push(idx);
        }
        result
    }
}

#[cfg(test)]
mod tests {
    use super::*;
    use rstest::rstest;

    #[rstest]
    #[case(vec![1,2,1], vec![2,-1,2])]
    #[case(vec![1,2,3,4,3], vec![2,3,4,-1,4])]
    fn test_next_greater_elements(#[case] nums: Vec<i32>, #[case] expected: Vec<i32>) {
        assert_eq!(Solution::next_greater_elements(nums), expected);
    }
}
