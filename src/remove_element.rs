struct Solution;

impl Solution {
    pub fn remove_element(nums: &mut Vec<i32>, val: i32) -> i32 {
        let mut k = 0;

        for i in 0..nums.len() {
            if nums[i] != val {
                nums[k] = nums[i];
                k += 1;
            }
        }

        k as i32
    }
}

#[cfg(test)]
mod test {
    use super::Solution;
    use rstest::rstest;

    #[rstest]
    #[case(vec![3, 2, 2, 3], 3, 2, vec![2, 2])]
    #[case(vec![0, 1, 2, 2, 3, 0, 4, 2], 2, 5, vec![0, 1, 3, 0, 4])]
    fn remove_element_test(
        #[case] mut nums: Vec<i32>,
        #[case] val: i32,
        #[case] expected_len: i32,
        #[case] expected_nums: Vec<i32>,
    ) {
        assert_eq!(Solution::remove_element(&mut nums, val), expected_len);
        assert_eq!(&nums[0..expected_len as usize], &expected_nums[..]);
    }
}
