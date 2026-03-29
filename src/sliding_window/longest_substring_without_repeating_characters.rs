use std::collections::HashMap;

struct Solution;

impl Solution {
    pub fn length_of_longest_substring(s: String) -> i32 {
        let n = s.len();
        let mut max_len = 0;
        let (mut left, mut right) = (0, 0);
        let bytes = s.as_bytes();
        let mut map: HashMap<u8, usize> = HashMap::new();

        while right < n {
            let current_char = bytes[right];
            let prev_index = map.get(&current_char);
            if let Some(v) = prev_index
                && left <= *v
            {
                left = *v + 1;
            }
            map.insert(current_char, right);
            max_len = max_len.max(right - left + 1);
            right += 1;
        }

        max_len as i32
    }
}

#[cfg(test)]
mod tests {
    use super::*;
    use rstest::rstest;

    #[rstest]
    #[case("abcabcbb", 3)]
    #[case("bbbbb", 1)]
    #[case("pwwkew", 3)]
    #[case("", 0)]
    #[case(" ", 1)]
    fn test_length_of_longest_substring(#[case] s: String, #[case] expected: i32) {
        assert_eq!(Solution::length_of_longest_substring(s), expected);
    }
}
