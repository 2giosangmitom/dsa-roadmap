struct Solution;

impl Solution {
    pub fn is_palindrome(s: String) -> bool {
        let (mut i, mut j) = (0, s.len() - 1);

        while i < j {
            let (c1, c2) = (s.as_bytes()[i], s.as_bytes()[j]);

            if !c1.is_ascii_alphanumeric() {
                i += 1;
            } else if !c2.is_ascii_alphanumeric() {
                j -= 1;
            } else if c1.to_ascii_lowercase() != c2.to_ascii_lowercase() {
                return false;
            } else {
                i += 1;
                j -= 1;
            }
        }

        true
    }
}

#[cfg(test)]
mod test {
    use super::Solution;
    use rstest::rstest;

    #[rstest]
    #[case(String::from("A man, a plan, a canal: Panama"), true)]
    #[case(String::from("race a car"), false)]
    #[case(String::from(" "), true)]
    fn is_palindrome_test(#[case] s: String, #[case] expected: bool) {
        assert_eq!(Solution::is_palindrome(s), expected);
    }
}
