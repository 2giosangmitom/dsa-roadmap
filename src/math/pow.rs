struct Solution;

impl Solution {
    pub fn my_pow(x: f64, n: i32) -> f64 {
        if n == 0 {
            return 1.0;
        }
        if n == 1 {
            return x;
        }
        let sign = if n < 0 { -1 } else { 1 };
        let mut half_pow = Self::my_pow(x, n / 2 * sign);
        half_pow *= half_pow;
        if sign * n % 2 == 1 {
            half_pow *= x;
        }
        if sign == -1 { 1.0 / half_pow } else { half_pow }
    }
}

#[cfg(test)]
mod tests {
    use super::Solution;
    use rstest::rstest;

    #[rstest]
    #[case(2.0, 10, 1024.0)]
    #[case(2.1, 3, 9.261)]
    #[case(2.0, -2, 0.25)]
    #[case(3.0, -3, 1.0 / 27.0)]
    fn test_my_pow(#[case] x: f64, #[case] n: i32, #[case] expected: f64) {
        assert!(
            (Solution::my_pow(x, n) - expected).abs() < 1e-9,
            "Expected {}, got {}",
            expected,
            Solution::my_pow(x, n)
        );
    }
}
