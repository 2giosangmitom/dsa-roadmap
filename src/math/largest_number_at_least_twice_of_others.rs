struct Solution;

impl Solution {
    pub fn dominant_index(nums: Vec<i32>) -> i32 {
        if nums.is_empty() {
            return -1;
        }

        let mut max = -1;
        let mut second = -1;
        let mut index = -1;

        for (i, &num) in nums.iter().enumerate() {
            if num > max {
                second = max;
                max = num;
                index = i as i32;
            } else if num > second {
                second = num;
            }
        }

        if max >= second * 2 { index } else { -1 }
    }
}

#[cfg(test)]
mod tests {
    use super::Solution;
    use rstest::rstest;

    #[rstest]
    #[case(vec![3, 6, 1, 0], 1)]
    #[case(vec![1, 2, 3, 4], -1)]
    #[case(vec![1], 0)]
    fn test_dominant_index(#[case] nums: Vec<i32>, #[case] expected: i32) {
        assert_eq!(Solution::dominant_index(nums), expected);
    }
}
