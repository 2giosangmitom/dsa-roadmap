struct Solution;

impl Solution {
    pub fn find_missing_and_repeated_values(grid: Vec<Vec<i32>>) -> Vec<i32> {
        let n = grid.len() as i32;
        let mut seen = vec![false; (n * n + 1) as usize]; // Use vector instead of HashSet for better performance
        let mut repeated = -1;
        let expected_sum = n * n * (n * n + 1) / 2;
        let mut actual_sum = 0;

        for row in grid {
            for num in row {
                actual_sum += num;
                if seen[num as usize] {
                    repeated = num;
                } else {
                    seen[num as usize] = true;
                }
            }
        }

        let missing = expected_sum - actual_sum + repeated;
        vec![repeated, missing]
    }
}

#[cfg(test)]
mod tests {
    use super::*;
    use rstest::rstest;

    #[rstest]
    #[case(vec![vec![1, 2], vec![2, 4]], vec![2, 3])]
    #[case(vec![vec![1, 1], vec![3, 4]], vec![1, 2])]
    #[case(vec![vec![1, 2, 3], vec![4, 5, 6], vec![7, 8, 8]], vec![8, 9])]
    fn test_find_missing_and_repeated_values(
        #[case] grid: Vec<Vec<i32>>,
        #[case] expected: Vec<i32>,
    ) {
        assert_eq!(Solution::find_missing_and_repeated_values(grid), expected);
    }
}
