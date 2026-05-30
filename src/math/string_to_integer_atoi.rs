struct Solution;

impl Solution {
    pub fn my_atoi(s: String) -> i32 {
        let bytes = s.as_bytes();
        let mut i = 0;

        while i < bytes.len() && bytes[i] == b' ' {
            i += 1;
        }

        let mut sign = 1;
        if i < bytes.len() && (bytes[i] == b'+' || bytes[i] == b'-') {
            if bytes[i] == b'-' {
                sign = -1;
            }
            i += 1;
        }

        let mut result: i32 = 0;
        while i < bytes.len() && bytes[i].is_ascii_digit() {
            let digit = (bytes[i] - b'0') as i32;
            if result > i32::MAX / 10 || (result == i32::MAX / 10 && digit > 7) {
                return if sign == 1 { i32::MAX } else { i32::MIN };
            }
            result = result * 10 + digit;
            i += 1;
        }

        result * sign
    }
}

#[cfg(test)]
mod tests {
    use super::Solution;
    use rstest::rstest;

    #[rstest]
    #[case(String::from("42"), 42)]
    #[case(String::from("   -42"), -42)]
    #[case(String::from("4193 with words"), 4193)]
    #[case(String::from("words and 987"), 0)]
    #[case(String::from("-91283472332"), i32::MIN)]
    fn test_my_atoi(#[case] s: String, #[case] expected: i32) {
        assert_eq!(Solution::my_atoi(s), expected);
    }
}
