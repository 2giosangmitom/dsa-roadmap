struct Solution;

impl Solution {
    pub fn combination_sum(candidates: Vec<i32>, target: i32) -> Vec<Vec<i32>> {
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
            current.push(candidates[i]);
            Self::backtrack(candidates, remaining - candidates[i], i, current, result);
            current.pop();
        }
    }
}

#[cfg(test)]
mod tests {
    use super::Solution;
    use rstest::rstest;

    #[rstest]
    #[case(vec![2, 3, 6, 7], 7, vec![vec![2, 2, 3], vec![7]])]
    #[case(vec![2, 3, 5], 8, vec![
        vec![2, 2, 2, 2], vec![2, 3, 3], vec![3, 5],
    ])]
    #[case(vec![2], 1, vec![] as Vec<Vec<i32>>)]
    fn test_combination_sum(
        #[case] candidates: Vec<i32>,
        #[case] target: i32,
        #[case] expected: Vec<Vec<i32>>,
    ) {
        assert_eq!(Solution::combination_sum(candidates, target), expected);
    }
}
