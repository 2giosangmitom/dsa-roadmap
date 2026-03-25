struct Solution;

impl Solution {
    pub fn climb_stairs(n: i32) -> i32 {
        if n <= 2 {
            return n;
        }

        let (mut a, mut b) = (1, 2);

        for _ in 3..=n {
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
    #[case(2, 2)]
    #[case(3, 3)]
    #[case(4, 5)]
    #[case(1, 1)]
    #[case(2, 2)]
    fn test_climb_stairs(#[case] n: i32, #[case] expected: i32) {
        let result = Solution::climb_stairs(n);
        assert_eq!(result, expected);
    }
}
