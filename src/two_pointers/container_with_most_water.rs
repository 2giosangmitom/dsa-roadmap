use std::cmp::{max, min};

struct Solution;

impl Solution {
    pub fn max_area(height: Vec<i32>) -> i32 {
        let (mut left, mut right) = (0, height.len() - 1);
        let mut max_area = 0;

        while left < right {
            let current_area = (right - left) as i32 * min(height[left], height[right]);
            max_area = max(max_area, current_area);

            if height[left] < height[right] {
                left += 1;
            } else {
                right -= 1;
            }
        }

        max_area
    }
}

#[cfg(test)]
mod tests {
    use super::Solution;
    use rstest::rstest;

    #[rstest]
    #[case(vec![1, 8, 6, 2, 5, 4, 8, 3, 7], 49)]
    #[case(vec![1, 1], 1)]
    #[case(vec![4, 3, 2, 1, 4], 16)]
    #[case(vec![1, 2, 1], 2)]
    fn test_max_area(#[case] height: Vec<i32>, #[case] expected: i32) {
        assert_eq!(Solution::max_area(height), expected);
    }
}
