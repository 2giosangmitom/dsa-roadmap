struct Solution;

impl Solution {
    pub fn character_replacement(s: String, k: i32) -> i32 {
        let bytes = s.as_bytes();
        let mut counts = [0; 26];
        let mut left = 0usize;
        let mut max_count = 0;
        let mut best = 0;

        for right in 0..bytes.len() {
            let idx = (bytes[right] - b'A') as usize;
            counts[idx] += 1;
            max_count = max_count.max(counts[idx]);

            while (right - left + 1) as i32 - max_count > k {
                let left_idx = (bytes[left] - b'A') as usize;
                counts[left_idx] -= 1;
                left += 1;
            }

            best = best.max(right - left + 1);
        }

        best as i32
    }
}

#[cfg(test)]
mod tests {
    use super::Solution;
    use rstest::rstest;

    #[rstest]
    #[case(String::from("ABAB"), 2, 4)]
    #[case(String::from("AABABBA"), 1, 4)]
    #[case(String::from("AAAA"), 2, 4)]
    fn test_character_replacement(#[case] s: String, #[case] k: i32, #[case] expected: i32) {
        assert_eq!(Solution::character_replacement(s, k), expected);
    }
}
