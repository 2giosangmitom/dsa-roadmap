struct Solution;

impl Solution {
    pub fn even_odd_bit(n: i32) -> Vec<i32> {
        let mut even = 0;
        let mut odd = 0;
        for i in 0..32 {
            if n & (1 << i) != 0 {
                if i % 2 == 0 {
                    even += 1;
                } else {
                    odd += 1;
                }
            }
        }
        vec![even, odd]
    }
}

#[cfg(test)]
mod tests {
    use super::*;
    use rstest::rstest;

    #[rstest]
    #[case(17, vec![2, 0])]
    #[case(2, vec![0, 1])]
    fn test_even_odd_bit(#[case] n: i32, #[case] expected: Vec<i32>) {
        assert_eq!(Solution::even_odd_bit(n), expected);
    }
}
