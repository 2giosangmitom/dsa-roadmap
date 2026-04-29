struct Solution;

impl Solution {
    pub fn hamming_weight(n: i32) -> i32 {
        let mut count = 0;

        for i in 0..32 {
            if n & (1 << i) != 0 {
                count += 1;
            }
        }

        count
    }
}

#[cfg(test)]
mod tests {
    use super::*;
    use rstest::rstest;

    #[rstest]
    #[case(11, 3)]
    #[case(128, 1)]
    #[case(-3, 31)]
    fn test_hamming_weight(#[case] n: i32, #[case] expected: i32) {
        assert_eq!(Solution::hamming_weight(n), expected);
    }
}
