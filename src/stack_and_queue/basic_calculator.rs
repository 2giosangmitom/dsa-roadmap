struct Solution;

impl Solution {
    pub fn calculate(s: String) -> i32 {
        let bytes = s.as_bytes();
        let mut stack: Vec<(i32, i32)> = Vec::new();

        let mut result = 0;
        let mut sign = 1;
        let mut i = 0;

        while i < bytes.len() {
            match bytes[i] {
                b'0'..=b'9' => {
                    let mut num = 0;

                    while i < bytes.len() && bytes[i].is_ascii_digit() {
                        num = num * 10 + (bytes[i] - b'0') as i32;
                        i += 1;
                    }

                    result += sign * num;
                    continue;
                }

                b'+' => sign = 1,

                b'-' => sign = -1,

                b'(' => {
                    stack.push((result, sign));

                    result = 0;
                    sign = 1;
                }

                b')' => {
                    let (prev_result, prev_sign) = stack.pop().unwrap();

                    result = prev_result + prev_sign * result;
                }

                _ => {}
            }

            i += 1;
        }

        result
    }
}

#[cfg(test)]
mod tests {
    use super::Solution;
    use rstest::rstest;

    #[rstest]
    #[case("1 + 1".to_string(), 2)]
    #[case(" 2-1 + 2 ".to_string(), 3)]
    #[case("(1+(4+5+2)-3)+(6+8)".to_string(), 23)]
    fn test_calculate(#[case] s: String, #[case] expected: i32) {
        assert_eq!(Solution::calculate(s), expected);
    }
}
