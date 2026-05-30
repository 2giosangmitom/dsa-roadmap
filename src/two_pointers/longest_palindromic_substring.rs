struct Solution;

impl Solution {
    pub fn longest_palindrome(s: String) -> String {
        if s.is_empty() {
            return s;
        }

        let bytes = s.as_bytes();
        let mut start = 0;
        let mut end = 0;

        for i in 0..bytes.len() {
            let (l1, r1) = Self::expand(bytes, i as i32, i as i32);
            let (l2, r2) = Self::expand(bytes, i as i32, i as i32 + 1);

            if r1 - l1 > end as i32 - start as i32 {
                start = l1 as usize;
                end = r1 as usize;
            }
            if r2 - l2 > end as i32 - start as i32 {
                start = l2 as usize;
                end = r2 as usize;
            }
        }

        s[start..=end].to_string()
    }

    fn expand(bytes: &[u8], mut left: i32, mut right: i32) -> (i32, i32) {
        while left >= 0
            && (right as usize) < bytes.len()
            && bytes[left as usize] == bytes[right as usize]
        {
            left -= 1;
            right += 1;
        }

        (left + 1, right - 1)
    }
}

#[cfg(test)]
mod tests {
    use super::Solution;
    use rstest::rstest;

    fn is_palindrome(s: &str) -> bool {
        s.bytes().eq(s.bytes().rev())
    }

    #[rstest]
    #[case(String::from("babad"), 3)]
    #[case(String::from("cbbd"), 2)]
    #[case(String::from("a"), 1)]
    #[case(String::from("ac"), 1)]
    fn test_longest_palindrome(#[case] input: String, #[case] expected_len: usize) {
        let result = Solution::longest_palindrome(input);
        assert!(is_palindrome(&result));
        assert_eq!(result.len(), expected_len);
    }
}
