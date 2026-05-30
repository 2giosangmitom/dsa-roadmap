struct Solution;

impl Solution {
    pub fn combine(n: i32, k: i32) -> Vec<Vec<i32>> {
        let mut result = Vec::new();
        let mut current = Vec::new();
        Self::backtrack(1, n as usize, k as usize, &mut current, &mut result);
        result
    }

    fn backtrack(
        start: usize,
        n: usize,
        k: usize,
        current: &mut Vec<i32>,
        result: &mut Vec<Vec<i32>>,
    ) {
        if current.len() == k {
            result.push(current.clone());
            return;
        }
        for i in start..=n {
            current.push(i as i32);
            Self::backtrack(i + 1, n, k, current, result);
            current.pop();
        }
    }
}

#[cfg(test)]
mod tests {
    use super::Solution;
    use rstest::rstest;

    #[rstest]
    #[case(4, 2, vec![
        vec![1, 2], vec![1, 3], vec![1, 4],
        vec![2, 3], vec![2, 4], vec![3, 4],
    ])]
    #[case(1, 1, vec![vec![1]])]
    fn test_combine(#[case] n: i32, #[case] k: i32, #[case] expected: Vec<Vec<i32>>) {
        assert_eq!(Solution::combine(n, k), expected);
    }
}
