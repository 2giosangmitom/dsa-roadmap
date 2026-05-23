use std::collections::HashSet;

struct Solution;

impl Solution {
    fn backtrack(
        result: &mut Vec<Vec<String>>,
        n: i32,
        i: i32,
        vertical_set: &mut HashSet<i32>,
        left_diagonal_set: &mut HashSet<i32>,
        right_diagonal_set: &mut HashSet<i32>,
        current: &mut [String],
    ) {
        if i >= n {
            if current.len() == n as usize {
                let mut sol = vec![".".to_string(); n as usize];
                sol.clone_from_slice(current);
                result.push(sol);
            }
            return;
        }

        for k in 0..n {
            if !vertical_set.contains(&k)
                && !left_diagonal_set.contains(&(i - k))
                && !right_diagonal_set.contains(&(i + k))
            {
                vertical_set.insert(k);
                left_diagonal_set.insert(i - k);
                right_diagonal_set.insert(i + k);
                current[i as usize].replace_range(k as usize..k as usize + 1, "Q");

                Self::backtrack(
                    result,
                    n,
                    i + 1,
                    vertical_set,
                    left_diagonal_set,
                    right_diagonal_set,
                    current,
                );

                vertical_set.remove(&k);
                left_diagonal_set.remove(&(i - k));
                right_diagonal_set.remove(&(i + k));
                current[i as usize].replace_range(k as usize..k as usize + 1, ".");
            }
        }
    }

    pub fn solve_n_queens(n: i32) -> Vec<Vec<String>> {
        let mut vertical_set = HashSet::<i32>::new();
        let mut left_diagonal_set = HashSet::<i32>::new();
        let mut right_diagonal_set = HashSet::<i32>::new();
        let mut current = vec![".".repeat(n as usize); n as usize];

        let mut result = Vec::<Vec<String>>::new();

        Self::backtrack(
            &mut result,
            n,
            0,
            &mut vertical_set,
            &mut left_diagonal_set,
            &mut right_diagonal_set,
            &mut current,
        );

        result
    }
}

#[cfg(test)]
mod tests {
    use super::*;
    use rstest::rstest;

    #[rstest]
    #[case(4, vec![
        vec![".Q..".to_string(), "...Q".to_string(), "Q...".to_string(), "..Q.".to_string()],
        vec!["..Q.".to_string(), "Q...".to_string(), "...Q".to_string(), ".Q..".to_string()],
    ])]
    #[case(1, vec![
        vec!["Q".to_string()],
    ])]
    #[case(2, vec![])]
    #[case(3, vec![])]
    fn test_solve_n_queens(#[case] n: i32, #[case] expected: Vec<Vec<String>>) {
        assert_eq!(Solution::solve_n_queens(n), expected);
    }
}
