struct Solution;

impl Solution {
    pub fn calculate(s: String) -> i32 {
        let mut num = 0;
        let mut last = 0;
        let mut result = 0;
        let mut op = b'+';
        let bytes = s.as_bytes();

        for i in 0..=bytes.len() {
            let c = if i < bytes.len() { bytes[i] } else { b'+' };
            if c.is_ascii_digit() {
                num = num * 10 + (c - b'0') as i32;
            } else if c != b' ' {
                match op {
                    b'+' => {
                        result += last;
                        last = num;
                    }
                    b'-' => {
                        result += last;
                        last = -num;
                    }
                    b'*' => {
                        last *= num;
                    }
                    b'/' => {
                        last /= num;
                    }
                    _ => {}
                }
                op = c;
                num = 0;
            }
        }

        result + last
    }
}

#[cfg(test)]
mod tests {
    use super::Solution;
    use rstest::rstest;

    #[rstest]
    #[case(String::from("3+2*2"), 7)]
    #[case(String::from(" 3/2 "), 1)]
    #[case(String::from(" 3+5 / 2 "), 5)]
    fn test_calculate(#[case] s: String, #[case] expected: i32) {
        assert_eq!(Solution::calculate(s), expected);
    }
}
