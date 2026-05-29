struct Solution;

impl Solution {
    pub fn search(nums: Vec<i32>, target: i32) -> i32 {
        let (mut left, mut right) = (0, nums.len() as i32 - 1);

        while left <= right {
            let mid = (left + right) / 2;
            if nums[mid as usize] == target {
                return mid;
            } else if nums[mid as usize] < target {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        -1
    }
}

#[cfg(test)]
mod tests {
    use super::*;
    use rstest::rstest;

    #[rstest]
    #[case(vec![-1, 0, 3, 5, 9, 12], 9, 4)]
    #[case(vec![-1, 0, 3, 5, 9, 12], 2, -1)]
    #[case(vec![5], 5, 0)]
    fn test(#[case] nums: Vec<i32>, #[case] target: i32, #[case] expected: i32) {
        assert_eq!(Solution::search(nums, target), expected);
    }
}
