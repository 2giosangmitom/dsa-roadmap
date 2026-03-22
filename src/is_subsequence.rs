struct Solution;

impl Solution {
    pub fn is_subsequence(s: String, t: String) -> bool {
        let (mut i, mut j) = (0, 0);

        while i < s.len() && j < t.len() {
            if s.as_bytes()[i] == t.as_bytes()[j] {
                i += 1;
            }
            j += 1;
        }

        i == s.len()
    }
}

#[cfg(test)]
mod tests {
    use super::Solution;
    use rstest::rstest;

    #[rstest]
    #[case("abc", "ahbgdc", true)]
    #[case("axc", "ahbgdc", false)]
    fn test_is_subsequence(#[case] s: String, #[case] t: String, #[case] expected: bool) {
        assert_eq!(Solution::is_subsequence(s, t), expected);
    }
}
