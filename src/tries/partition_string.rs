struct Solution;

impl Solution {
    pub fn partition_labels(s: String) -> Vec<i32> {
        let s = s.as_bytes();
        let mut last = [0i32; 26];
        for (i, &ch) in s.iter().enumerate() {
            last[(ch - b'a') as usize] = i as i32;
        }
        let mut result = Vec::new();
        let mut start = 0i32;
        let mut end = 0i32;
        for (i, &ch) in s.iter().enumerate() {
            end = end.max(last[(ch - b'a') as usize]);
            if i as i32 == end {
                result.push(end - start + 1);
                start = end + 1;
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
    #[case(
        "ababcbacadefegdehijhklij".to_string(),
        vec![9, 7, 8],
    )]
    #[case(
        "eccbbbbdec".to_string(),
        vec![10],
    )]
    fn test_partition_labels(#[case] s: String, #[case] expected: Vec<i32>) {
        assert_eq!(Solution::partition_labels(s), expected);
    }
}
