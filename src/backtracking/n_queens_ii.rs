struct Solution;

impl Solution {
    pub fn total_n_queens(n: i32) -> i32 {
        let mut count = 0;
        let mut cols = 0i32;
        let mut diag1 = 0i32;
        let mut diag2 = 0i32;
        Self::backtrack(n, 0, &mut cols, &mut diag1, &mut diag2, &mut count);
        count
    }

    fn backtrack(
        n: i32,
        row: i32,
        cols: &mut i32,
        diag1: &mut i32,
        diag2: &mut i32,
        count: &mut i32,
    ) {
        if row == n {
            *count += 1;
            return;
        }
        for col in 0..n {
            let c_bit = 1 << col;
            let d1_bit = 1 << (row - col + n - 1);
            let d2_bit = 1 << (row + col);
            if *cols & c_bit == 0 && *diag1 & d1_bit == 0 && *diag2 & d2_bit == 0 {
                *cols |= c_bit;
                *diag1 |= d1_bit;
                *diag2 |= d2_bit;
                Self::backtrack(n, row + 1, cols, diag1, diag2, count);
                *cols ^= c_bit;
                *diag1 ^= d1_bit;
                *diag2 ^= d2_bit;
            }
        }
    }
}

#[cfg(test)]
mod tests {
    use super::Solution;
    use rstest::rstest;

    #[rstest]
    #[case(4, 2)]
    #[case(1, 1)]
    fn test_total_n_queens(#[case] n: i32, #[case] expected: i32) {
        assert_eq!(Solution::total_n_queens(n), expected);
    }
}
