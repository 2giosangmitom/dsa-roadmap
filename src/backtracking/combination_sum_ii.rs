struct Solution;

impl Solution {
    pub fn combination_sum2(candidates: Vec<i32>, target: i32) -> Vec<Vec<i32>> {
        let mut candidates = candidates;
        candidates.sort_unstable();
        let mut result = Vec::new();
        let mut current = Vec::new();
        Self::backtrack(&candidates, target, 0, &mut current, &mut result);
        result
    }

    fn backtrack(
        candidates: &[i32],
        remaining: i32,
        start: usize,
        current: &mut Vec<i32>,
        result: &mut Vec<Vec<i32>>,
    ) {
        if remaining == 0 {
            result.push(current.clone());
            return;
        }
        for i in start..candidates.len() {
            if candidates[i] > remaining {
                break;
            }
            if i > start && candidates[i] == candidates[i - 1] {
                continue;
            }
            current.push(candidates[i]);
            Self::backtrack(
                candidates,
                remaining - candidates[i],
                i + 1,
                current,
                result,
            );
            current.pop();
        }
    }
}

#[cfg(test)]
mod tests {
    use super::Solution;
    use rstest::rstest;

    #[rstest]
    #[case(vec![10, 1, 2, 7, 6, 1, 5], 8, vec![
        vec![1, 1, 6], vec![1, 2, 5], vec![1, 7], vec![2, 6],
    ])]
    #[case(vec![2, 5, 2, 1, 2], 5, vec![vec![1, 2, 2], vec![5]])]
    fn test_combination_sum2(
        #[case] candidates: Vec<i32>,
        #[case] target: i32,
        #[case] expected: Vec<Vec<i32>>,
    ) {
        assert_eq!(Solution::combination_sum2(candidates, target), expected);
    }
}
