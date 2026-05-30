struct Solution;

impl Solution {
    pub fn find_peak_element(nums: Vec<i32>) -> i32 {
        let mut left = 0;
        let mut right = nums.len() - 1;

        while left < right {
            let mid = left + (right - left) / 2;
            if nums[mid] > nums[mid + 1] {
                right = mid;
            } else {
                left = mid + 1;
            }
        }

        left as i32
    }
}

#[cfg(test)]
mod tests {
    use super::Solution;
    use rstest::rstest;

    #[rstest]
    #[case(vec![1, 2, 3, 1])]
    #[case(vec![1, 2, 1, 3, 5, 6, 4])]
    fn test_find_peak_element(#[case] nums: Vec<i32>) {
        let index = Solution::find_peak_element(nums.clone()) as usize;
        let left = if index == 0 {
            i32::MIN
        } else {
            nums[index - 1]
        };
        let right = if index + 1 == nums.len() {
            i32::MIN
        } else {
            nums[index + 1]
        };
        assert!(nums[index] > left && nums[index] > right);
    }
}
