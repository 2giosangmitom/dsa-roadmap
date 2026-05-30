struct Solution;

impl Solution {
    pub fn reverse_bits(x: u32) -> u32 {
        let mut result = 0u32;
        for i in 0..32 {
            result = (result << 1) | ((x >> i) & 1);
        }
        result
    }
}

#[cfg(test)]
mod tests {
    use super::*;
    use rstest::rstest;

    #[rstest]
    #[case(43261596, 964176192)]
    #[case(4294967293, 3221225471)]
    fn test_reverse_bits(#[case] x: u32, #[case] expected: u32) {
        assert_eq!(Solution::reverse_bits(x), expected);
    }
}
