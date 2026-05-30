struct Solution;

impl Solution {
    pub fn lexicographically_smallest_negated_permutation(n: i32, target: i32) -> Vec<i32> {
        let n = n as i64;
        let target = target as i64;
        let sum = n * (n + 1) / 2;

        if target < -sum || target > sum {
            return Vec::new();
        }

        let mut diff = sum - target;
        if diff % 2 != 0 {
            return Vec::new();
        }

        let mut neg = vec![false; n as usize + 1];
        let mut x = n;
        while x >= 1 && diff > 0 {
            if 2 * x <= diff {
                neg[x as usize] = true;
                diff -= 2 * x;
            }
            x -= 1;
        }

        if diff != 0 {
            return Vec::new();
        }

        let mut result: Vec<i32> = (1..=n)
            .map(|v| {
                if neg[v as usize] {
                    -(v as i32)
                } else {
                    v as i32
                }
            })
            .collect();
        result.sort();
        result
    }
}

#[cfg(test)]
mod tests {
    use super::Solution;
    use rstest::rstest;

    #[rstest]
    #[case(3, 0, vec![-3, 1, 2])]
    #[case(1, 1000000000, vec![])]
    #[case(4, 2, vec![-4, 1, 2, 3])]
    fn test_lexicographically_smallest_negated_permutation(
        #[case] n: i32,
        #[case] target: i32,
        #[case] expected: Vec<i32>,
    ) {
        assert_eq!(
            Solution::lexicographically_smallest_negated_permutation(n, target),
            expected
        );
    }
}
