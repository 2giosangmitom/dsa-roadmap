struct Solution;

impl Solution {
    pub fn num_water_bottles(num_bottles: i32, num_exchange: i32) -> i32 {
        let mut bottles = num_bottles;
        let mut empty = 0;
        let mut total = 0;

        while bottles > 0 {
            total += bottles;
            empty += bottles;
            bottles = empty / num_exchange;
            empty %= num_exchange;
        }

        total
    }
}

#[cfg(test)]
mod tests {
    use super::Solution;
    use rstest::rstest;

    #[rstest]
    #[case(9, 3, 13)]
    #[case(15, 4, 19)]
    fn test_num_water_bottles(
        #[case] num_bottles: i32,
        #[case] num_exchange: i32,
        #[case] expected: i32,
    ) {
        assert_eq!(
            Solution::num_water_bottles(num_bottles, num_exchange),
            expected
        );
    }
}
