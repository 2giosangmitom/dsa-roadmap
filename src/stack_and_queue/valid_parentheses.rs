struct Solution;

impl Solution {
    pub fn is_valid(s: String) -> bool {
        let mut stack: Vec<char> = Vec::new();
        for c in s.chars() {
            match c {
                '(' => stack.push(')'),
                '[' => stack.push(']'),
                '{' => stack.push('}'),
                _ => {
                    if stack.pop() != Some(c) {
                        return false;
                    }
                }
            }
        }
        stack.is_empty()
    }
}

#[cfg(test)]
mod tests {
    use super::*;
    use rstest::rstest;

    #[rstest]
    #[case(String::from("()"), true)]
    #[case(String::from("()[]{}"), true)]
    #[case(String::from("(]"), false)]
    #[case(String::from("([])"), true)]
    fn test_is_valid(#[case] s: String, #[case] expected: bool) {
        assert_eq!(Solution::is_valid(s), expected);
    }
}
