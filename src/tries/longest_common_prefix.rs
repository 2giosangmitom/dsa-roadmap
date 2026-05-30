struct Solution;

impl Solution {
    pub fn longest_common_prefix(strs: Vec<String>) -> String {
        if strs.is_empty() {
            return String::new();
        }
        let first = strs[0].as_bytes();
        for i in 0..first.len() {
            for s in &strs[1..] {
                if i >= s.len() || s.as_bytes()[i] != first[i] {
                    return first[..i].iter().map(|&b| b as char).collect();
                }
            }
        }
        strs[0].clone()
    }
}

#[cfg(test)]
mod tests {
    use super::Solution;
    use rstest::rstest;

    #[rstest]
    #[case(
        vec!["flower".to_string(), "flow".to_string(), "flight".to_string()],
        "fl".to_string(),
    )]
    #[case(
        vec!["dog".to_string(), "racecar".to_string(), "car".to_string()],
        "".to_string(),
    )]
    fn test_longest_common_prefix(#[case] strs: Vec<String>, #[case] expected: String) {
        assert_eq!(Solution::longest_common_prefix(strs), expected);
    }
}
