struct Solution;

impl Solution {
    pub fn closest_primes(left: i32, right: i32) -> Vec<i32> {
        let right = right as usize;
        if right < 2 {
            return vec![-1, -1];
        }

        let mut is_prime = vec![true; right + 1];
        is_prime[0] = false;
        if right >= 1 {
            is_prime[1] = false;
        }

        let mut i = 2;
        while i * i <= right {
            if is_prime[i] {
                let mut j = i * i;
                while j <= right {
                    is_prime[j] = false;
                    j += i;
                }
            }
            i += 1;
        }

        let mut prev = -1;
        let mut best = (i32::MAX, -1, -1);
        for num in left.max(2)..=right as i32 {
            if is_prime[num as usize] {
                if prev != -1 {
                    let diff = num - prev;
                    if diff < best.0 {
                        best = (diff, prev, num);
                    }
                }
                prev = num;
            }
        }

        if best.1 == -1 {
            vec![-1, -1]
        } else {
            vec![best.1, best.2]
        }
    }
}

#[cfg(test)]
mod tests {
    use super::Solution;
    use rstest::rstest;

    #[rstest]
    #[case(10, 19, vec![11, 13])]
    #[case(4, 6, vec![-1, -1])]
    #[case(2, 3, vec![2, 3])]
    fn test_closest_primes(#[case] left: i32, #[case] right: i32, #[case] expected: Vec<i32>) {
        assert_eq!(Solution::closest_primes(left, right), expected);
    }
}
