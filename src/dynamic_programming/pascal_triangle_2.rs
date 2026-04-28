struct Solution;

impl Solution {
    pub fn get_row(row_index: i32) -> Vec<i32> {
        let mut result = vec![vec![]; row_index as usize + 1];

        for i in 0..=row_index {
            result[i as usize].resize(i as usize + 1, 1);
            for j in 0..i + 1 {
                if i == j || j == 0 {
                    continue;
                }
                result[i as usize][j as usize] =
                    result[i as usize - 1][j as usize] + result[i as usize - 1][j as usize - 1];
            }
        }

        result[row_index as usize].clone()
    }
}

#[cfg(test)]
mod tests {
    use super::*;
    use rstest::rstest;

    #[rstest]
    #[case(3, vec![1, 3, 3, 1])]
    #[case(0, vec![1])]
    #[case(1, vec![1, 1])]
    fn test(#[case] row_index: i32, #[case] expected: Vec<i32>) {
        assert_eq!(Solution::get_row(row_index), expected);
    }
}
