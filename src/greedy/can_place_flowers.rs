struct Solution;

impl Solution {
    pub fn can_place_flowers(flowerbed: Vec<i32>, n: i32) -> bool {
        let mut flowerbed = flowerbed;
        let mut n = n;
        let len = flowerbed.len();

        for i in 0..len {
            if flowerbed[i] == 0
                && (i == 0 || flowerbed[i - 1] == 0)
                && (i == len - 1 || flowerbed[i + 1] == 0)
            {
                flowerbed[i] = 1;
                n -= 1;
            }
        }

        n <= 0
    }
}

#[cfg(test)]
mod tests {
    use super::*;
    use rstest::rstest;

    #[rstest]
    #[case(vec![1, 0, 0, 0, 1], 1, true)]
    #[case(vec![1, 0, 0, 0, 1], 2, false)]
    fn test_can_place_flowers(#[case] flowerbed: Vec<i32>, #[case] n: i32, #[case] expected: bool) {
        assert_eq!(Solution::can_place_flowers(flowerbed, n), expected);
    }
}
