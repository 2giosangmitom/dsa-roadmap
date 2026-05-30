struct Solution;

impl Solution {
    pub fn length_of_lis(nums: Vec<i32>) -> i32 {
        let mut tails: Vec<i32> = Vec::new();

        for num in nums {
            let idx = match tails.binary_search(&num) {
                Ok(i) => i,
                Err(i) => i,
            };
            if idx == tails.len() {
                tails.push(num);
            } else {
                tails[idx] = num;
            }
        }

        tails.len() as i32
    }
}

#[cfg(test)]
mod tests {
    use super::Solution;
    use rstest::rstest;

    #[rstest]
    #[case(vec![10, 9, 2, 5, 3, 7, 101, 18], 4)]
    #[case(vec![0, 1, 0, 3, 2, 3], 4)]
    #[case(vec![7, 7, 7, 7], 1)]
    fn test_length_of_lis(#[case] nums: Vec<i32>, #[case] expected: i32) {
        assert_eq!(Solution::length_of_lis(nums), expected);
    }
}
