struct Solution;

impl Solution {
    pub fn fib(n: i32) -> i32 {
        if n <= 1 {
            return n;
        }
        let (mut a, mut b) = (0, 1);
        for _ in 2..=n {
            let c = a + b;
            a = b;
            b = c;
        }
        b
    }
}

#[cfg(test)]
mod tests {
    use super::*;
    use rstest::rstest;

    #[rstest]
    #[case(2, 1)]
    #[case(3, 2)]
    #[case(4, 3)]
    fn test_fib(#[case] n: i32, #[case] expected: i32) {
        assert_eq!(Solution::fib(n), expected);
    }
}
