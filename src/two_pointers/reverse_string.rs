struct Solution;

impl Solution {
    pub fn reverse_string(s: &mut Vec<char>) {
        let (mut left, mut right) = (0, s.len() - 1);

        while left < right {
            s.swap(left, right);
            left += 1;
            right -= 1;
        }
    }
}

#[cfg(test)]
mod tests {
    use super::Solution;
    use rstest::rstest;

    #[rstest]
    #[case(vec!['h', 'e', 'l', 'l', 'o'], vec!['o', 'l', 'l', 'e', 'h'])]
    #[case(vec!['H', 'a', 'n', 'n', 'a', 'H'], vec!['H', 'a', 'n', 'n', 'a', 'H'])]
    fn test_reverse_string(#[case] mut input: Vec<char>, #[case] expected: Vec<char>) {
        Solution::reverse_string(&mut input);
        assert_eq!(input, expected);
    }
}
