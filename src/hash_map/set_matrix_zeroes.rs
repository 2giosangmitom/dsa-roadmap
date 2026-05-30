struct Solution;

impl Solution {
    pub fn set_zeroes(matrix: &mut [Vec<i32>]) {
        let rows = matrix.len();
        if rows == 0 {
            return;
        }
        let cols = matrix[0].len();
        let mut row_zero = vec![false; rows];
        let mut col_zero = vec![false; cols];

        for i in 0..rows {
            for j in 0..cols {
                if matrix[i][j] == 0 {
                    row_zero[i] = true;
                    col_zero[j] = true;
                }
            }
        }

        for i in 0..rows {
            for j in 0..cols {
                if row_zero[i] || col_zero[j] {
                    matrix[i][j] = 0;
                }
            }
        }
    }
}

#[cfg(test)]
mod tests {
    use super::Solution;
    use rstest::rstest;

    #[rstest]
    #[case(vec![vec![1, 1, 1], vec![1, 0, 1], vec![1, 1, 1]], vec![vec![1, 0, 1], vec![0, 0, 0], vec![1, 0, 1]])]
    #[case(vec![vec![0, 1, 2, 0], vec![3, 4, 5, 2], vec![1, 3, 1, 5]], vec![vec![0, 0, 0, 0], vec![0, 4, 5, 0], vec![0, 3, 1, 0]])]
    fn test_set_zeroes(#[case] mut matrix: Vec<Vec<i32>>, #[case] expected: Vec<Vec<i32>>) {
        Solution::set_zeroes(&mut matrix);
        assert_eq!(matrix, expected);
    }
}
