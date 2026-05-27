struct Solution;

impl Solution {
    pub fn next_permutation(nums: &mut [i32]) {
        let n = nums.len() as i32;
        if n == 1 {
            return;
        }

        let mut j = n - 2;
        while j >= 0 && nums[j as usize] >= nums[j as usize + 1] {
            j -= 1;
        }
        if j < 0 {
            nums.reverse();
        } else {
            let mut i = n - 1;
            while i >= 0 && nums[i as usize] <= nums[j as usize] {
                i -= 1;
            }
            nums.swap(i as usize, j as usize);
            nums[j as usize + 1..n as usize].reverse();
        }
    }
}

#[cfg(test)]
mod tests {
    use super::Solution;
    use rstest::rstest;

    #[rstest]
    #[case(vec![1, 2, 3], vec![1, 3, 2])]
    #[case(vec![3, 2, 1], vec![1, 2, 3])]
    #[case(vec![1, 3, 2], vec![2, 1, 3])]
    #[case(vec![2, 3 ,1], vec![3, 1, 2])]
    fn test_next_permutation(#[case] mut nums: Vec<i32>, #[case] expected: Vec<i32>) {
        Solution::next_permutation(&mut nums);
        assert_eq!(nums, expected);
    }
}
