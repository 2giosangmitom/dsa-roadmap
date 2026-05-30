struct Solution;

impl Solution {
    pub fn letter_combinations(digits: String) -> Vec<String> {
        if digits.is_empty() {
            return Vec::new();
        }
        let mapping: [&str; 10] = [
            "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz",
        ];
        let mut result = Vec::new();
        let mut current = String::new();
        Self::backtrack(digits.as_bytes(), &mapping, 0, &mut current, &mut result);
        result
    }

    fn backtrack(
        digits: &[u8],
        mapping: &[&str; 10],
        idx: usize,
        current: &mut String,
        result: &mut Vec<String>,
    ) {
        if idx == digits.len() {
            result.push(current.clone());
            return;
        }
        let letters = mapping[(digits[idx] - b'0') as usize];
        for ch in letters.chars() {
            current.push(ch);
            Self::backtrack(digits, mapping, idx + 1, current, result);
            current.pop();
        }
    }
}

#[cfg(test)]
mod tests {
    use super::Solution;
    use rstest::rstest;

    #[rstest]
    #[case("23".to_string(), vec![
        "ad".to_string(), "ae".to_string(), "af".to_string(),
        "bd".to_string(), "be".to_string(), "bf".to_string(),
        "cd".to_string(), "ce".to_string(), "cf".to_string(),
    ])]
    #[case("".to_string(), vec![] as Vec<String>)]
    #[case("2".to_string(), vec!["a".to_string(), "b".to_string(), "c".to_string()])]
    fn test_letter_combinations(#[case] digits: String, #[case] expected: Vec<String>) {
        assert_eq!(Solution::letter_combinations(digits), expected);
    }
}
