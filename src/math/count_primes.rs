struct Solution;

impl Solution {
    pub fn count_primes(n: i32) -> i32 {
        let n = n as usize;
        if n < 2 {
            return 0;
        }

        let mut is_prime = vec![true; n];
        is_prime[0] = false;
        if n > 1 {
            is_prime[1] = false;
        }

        let mut i = 2;
        while i * i < n {
            if is_prime[i] {
                let mut j = i * i;
                while j < n {
                    is_prime[j] = false;
                    j += i;
                }
            }
            i += 1;
        }

        is_prime.iter().filter(|&&v| v).count() as i32
    }
}

#[cfg(test)]
mod tests {
    use super::Solution;
    use rstest::rstest;

    #[rstest]
    #[case(10, 4)]
    #[case(0, 0)]
    #[case(1, 0)]
    fn test_count_primes(#[case] n: i32, #[case] expected: i32) {
        assert_eq!(Solution::count_primes(n), expected);
    }
}
