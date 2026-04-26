struct Solution;

impl Solution {
    pub fn remove_duplicates(s: String) -> String {
        let mut stack = "".to_string();

        for c in s.as_bytes() {
            if stack.as_bytes().last().is_none_or(|l| l != c) {
                stack.push(char::from(*c));
            } else {
                stack.pop();
            }
        }

        stack
    }
}

#[cfg(test)]
mod test {
    use super::Solution;
    use rstest::rstest;

    #[rstest]
    #[case(String::from("abbaca"), String::from("ca"))]
    #[case(String::from("azxxzy"), String::from("ay"))]
    #[case(String::from("a"), String::from("a"))]
    #[case(String::from("aa"), String::from(""))]
    #[case(String::from("abba"), String::from(""))]
    fn remove_duplicates_test(#[case] s: String, #[case] expected: String) {
        assert_eq!(Solution::remove_duplicates(s), expected);
    }
}
