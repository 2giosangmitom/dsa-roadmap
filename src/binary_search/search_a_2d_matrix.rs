struct Solution;

impl Solution {
    pub fn search_matrix(matrix: Vec<Vec<i32>>, target: i32) -> bool {
        let rows = matrix.len();
        if rows == 0 {
            return false;
        }
        let cols = matrix[0].len();

        let mut left = 0;
        let mut right = rows * cols;

        while left < right {
            let mid = left + (right - left) / 2;
            let r = mid / cols;
            let c = mid % cols;
            let value = matrix[r][c];

            if value == target {
                return true;
            } else if value < target {
                left = mid + 1;
            } else {
                right = mid;
            }
        }

        false
    }
}

#[cfg(test)]
mod tests {
    use super::Solution;
    use rstest::rstest;

    #[rstest]
    #[case(vec![vec![1, 3, 5, 7], vec![10, 11, 16, 20], vec![23, 30, 34, 60]], 3, true)]
    #[case(vec![vec![1, 3, 5, 7], vec![10, 11, 16, 20], vec![23, 30, 34, 60]], 13, false)]
    #[case(vec![vec![1]], 1, true)]
    fn test_search_matrix(
        #[case] matrix: Vec<Vec<i32>>,
        #[case] target: i32,
        #[case] expected: bool,
    ) {
        assert_eq!(Solution::search_matrix(matrix, target), expected);
    }
}
