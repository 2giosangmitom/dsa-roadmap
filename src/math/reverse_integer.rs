struct Solution;

impl Solution {
    pub fn reverse(x: i32) -> i32 {
        let mut x = x;
        let mut result: i32 = 0;

        while x != 0 {
            let digit = x % 10;
            x /= 10;
            if result > i32::MAX / 10 || (result == i32::MAX / 10 && digit > 7) {
                return 0;
            }
            if result < i32::MIN / 10 || (result == i32::MIN / 10 && digit < -8) {
                return 0;
            }
            result = result * 10 + digit;
        }

        result
    }
}

#[cfg(test)]
mod tests {
    use super::Solution;
    use rstest::rstest;

    #[rstest]
    #[case(123, 321)]
    #[case(-123, -321)]
    #[case(120, 21)]
    #[case(1534236469, 0)]
    fn test_reverse(#[case] x: i32, #[case] expected: i32) {
        assert_eq!(Solution::reverse(x), expected);
    }
}
