struct Solution;

impl Solution {
    pub fn decode_string(s: String) -> String {
        let mut count_stack: Vec<i32> = Vec::new();
        let mut string_stack: Vec<String> = Vec::new();
        let mut current_string = String::new();
        let mut k = 0;

        for c in s.chars() {
            if c.is_ascii_digit() {
                k = k * 10 + (c as i32 - '0' as i32);
            } else if c == '[' {
                count_stack.push(k);
                string_stack.push(current_string.clone());
                current_string.clear();
                k = 0;
            } else if c == ']' {
                let repeat_count = count_stack.pop().unwrap();
                let prev_string = string_stack.pop().unwrap();
                current_string = prev_string + &current_string.repeat(repeat_count as usize);
            } else {
                current_string.push(c);
            }
        }

        current_string
    }
}

#[cfg(test)]
mod tests {
    use super::*;
    use rstest::rstest;

    #[rstest]
    #[case(String::from("3[a]2[bc]"), String::from("aaabcbc"))]
    #[case(String::from("3[a2[c]]"), String::from("accaccacc"))]
    #[case(String::from("2[abc]3[cd]ef"), String::from("abcabccdcdcdef"))]
    fn test_decode_string(#[case] s: String, #[case] expected: String) {
        assert_eq!(Solution::decode_string(s), expected);
    }
}
