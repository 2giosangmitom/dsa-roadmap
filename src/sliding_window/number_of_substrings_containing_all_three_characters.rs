struct Solution;

impl Solution {
    pub fn number_of_substrings(s: String) -> i32 {
        let bytes = s.as_bytes();
        let mut count = [0; 3];
        let mut left = 0usize;
        let mut result = 0i32;

        for right in 0..bytes.len() {
            count[(bytes[right] - b'a') as usize] += 1;

            while count[0] > 0 && count[1] > 0 && count[2] > 0 {
                result += (bytes.len() - right) as i32;
                count[(bytes[left] - b'a') as usize] -= 1;
                left += 1;
            }
        }

        result
    }
}

#[cfg(test)]
mod tests {
    use super::Solution;
    use rstest::rstest;

    #[rstest]
    #[case(String::from("abcabc"), 10)]
    #[case(String::from("aaacb"), 3)]
    #[case(String::from("abc"), 1)]
    fn test_number_of_substrings(#[case] s: String, #[case] expected: i32) {
        assert_eq!(Solution::number_of_substrings(s), expected);
    }
}
