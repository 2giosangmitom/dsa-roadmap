struct Solution;

impl Solution {
    pub fn generate(num_rows: i32) -> Vec<Vec<i32>> {
        let mut result = vec![vec![]; num_rows as usize];

        for i in 0..num_rows {
            result[i as usize].resize(i as usize + 1, 1);
            for j in 0..i + 1 {
                if i == j || j == 0 {
                    continue;
                }
                result[i as usize][j as usize] =
                    result[i as usize - 1][j as usize] + result[i as usize - 1][j as usize - 1];
            }
        }

        result
    }
}

#[cfg(test)]
mod tests {
    use super::*;
    use rstest::rstest;

    #[rstest]
    #[case(5, vec![vec![1], vec![1, 1], vec![1, 2, 1], vec![1, 3, 3, 1], vec![1, 4, 6, 4, 1]])]
    #[case(1, vec![vec![1]])]
    #[case(2, vec![vec![1], vec![1, 1]])]
    fn test(#[case] num_rows: i32, #[case] expected: Vec<Vec<i32>>) {
        assert_eq!(Solution::generate(num_rows), expected);
    }
}
