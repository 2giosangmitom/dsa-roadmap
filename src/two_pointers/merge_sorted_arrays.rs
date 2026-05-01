struct Solution;

impl Solution {
    pub fn merge(nums1: &mut [i32], m: i32, nums2: &mut [i32], n: i32) {
        let mut i = m - 1;
        let mut j = n - 1;
        let mut k = (m + n) - 1;

        while k >= 0 {
            if i >= 0 && j >= 0 {
                if nums1[i as usize] >= nums2[j as usize] {
                    nums1[k as usize] = nums1[i as usize];
                    i -= 1;
                } else {
                    nums1[k as usize] = nums2[j as usize];
                    j -= 1;
                }
            } else if i >= 0 {
                nums1[k as usize] = nums1[i as usize];
                i -= 1;
            } else if j >= 0 {
                nums1[k as usize] = nums2[j as usize];
                j -= 1;
            }
            k -= 1;
        }
    }
}

#[cfg(test)]
mod tests {
    use super::*;
    use rstest::rstest;

    #[rstest]
    #[case(vec![1, 2, 3, 0, 0, 0], 3, vec![2, 5, 6], 3, vec![1, 2, 2, 3, 5, 6])]
    #[case(vec![1], 1, vec![], 0, vec![1])]
    #[case(vec![0], 0, vec![1], 1, vec![1])]
    fn test_merge(
        #[case] mut nums1: Vec<i32>,
        #[case] m: i32,
        #[case] mut nums2: Vec<i32>,
        #[case] n: i32,
        #[case] expected: Vec<i32>,
    ) {
        Solution::merge(&mut nums1, m, &mut nums2, n);
        assert_eq!(nums1, expected);
    }
}
