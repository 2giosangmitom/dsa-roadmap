struct Solution;

impl Solution {
    pub fn hamming_distance(x: i32, y: i32) -> i32 {
        (x ^ y).count_ones() as i32
    }
}

#[cfg(test)]
mod tests {
    use super::*;
    use rstest::rstest;

    #[rstest]
    #[case(1, 4, 2)]
    #[case(3, 1, 1)]
    fn test_hamming_distance(#[case] x: i32, #[case] y: i32, #[case] expected: i32) {
        assert_eq!(Solution::hamming_distance(x, y), expected);
    }
}
