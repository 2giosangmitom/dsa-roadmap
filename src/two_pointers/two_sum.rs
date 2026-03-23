struct Solution;

impl Solution {
    pub fn two_sum(numbers: Vec<i32>, target: i32) -> Vec<i32> {
        let (mut left, mut right) = (0, numbers.len() - 1);

        while left < right {
            let sum = numbers[left] + numbers[right];

            if sum == target {
                return vec![left as i32 + 1, right as i32 + 1];
            } else if sum < target {
                left += 1;
            } else {
                right -= 1;
            }
        }

        vec![]
    }
}

#[cfg(test)]
mod tests {
    use super::Solution;
    use rstest::rstest;

    #[rstest]
    #[case(vec![2, 7, 11, 15], 9, vec![1, 2])]
    #[case(vec![2, 3, 4], 6, vec![1, 3])]
    #[case(vec![-1, 0], -1, vec![1, 2])]
    fn test(#[case] numbers: Vec<i32>, #[case] target: i32, #[case] expected: Vec<i32>) {
        assert_eq!(Solution::two_sum(numbers, target), expected);
    }
}
