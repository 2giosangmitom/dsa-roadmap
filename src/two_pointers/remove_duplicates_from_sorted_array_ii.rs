struct Solution;

impl Solution {
    pub fn remove_duplicates(nums: &mut [i32]) -> i32 {
        if nums.len() <= 2 {
            return nums.len() as i32;
        }

        let mut k = 2;

        for i in 2..nums.len() {
            if nums[i] != nums[k - 2] {
                nums[k] = nums[i];
                k += 1;
            }
        }

        k as i32
    }
}

#[cfg(test)]
mod tests {
    use super::Solution;
    use rstest::rstest;

    #[rstest]
    #[case(vec![1, 1, 1, 2, 2, 3], 5, vec![1, 1, 2, 2, 3])]
    #[case(vec![0, 0, 1, 1, 1, 1, 2, 3, 3], 7, vec![0, 0, 1, 1, 2, 3, 3])]
    #[case(vec![1, 1], 2, vec![1, 1])]
    fn test_remove_duplicates_ii(
        #[case] mut nums: Vec<i32>,
        #[case] expected_len: i32,
        #[case] expected_nums: Vec<i32>,
    ) {
        assert_eq!(Solution::remove_duplicates(&mut nums), expected_len);
        assert_eq!(&nums[0..expected_len as usize], &expected_nums[..]);
    }
}
