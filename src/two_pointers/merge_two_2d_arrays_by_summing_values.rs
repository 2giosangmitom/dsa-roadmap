struct Solution;

impl Solution {
    pub fn merge_arrays(nums1: Vec<Vec<i32>>, nums2: Vec<Vec<i32>>) -> Vec<Vec<i32>> {
        let (mut i, mut j) = (0, 0);
        let mut result: Vec<Vec<i32>> = Vec::new();
        let (n1_len, n2_len) = (nums1.len(), nums2.len());

        while i < n1_len && j < n2_len {
            if nums1[i][0] == nums2[j][0] {
                result.push(vec![nums1[i][0], nums1[i][1] + nums2[j][1]]);
                i += 1;
                j += 1;
            } else if nums1[i][0] < nums2[j][0] {
                result.push(vec![nums1[i][0], nums1[i][1]]);
                i += 1;
            } else {
                result.push(vec![nums2[j][0], nums2[j][1]]);
                j += 1;
            }
        }

        while i < n1_len {
            result.push(vec![nums1[i][0], nums1[i][1]]);
            i += 1;
        }

        while j < n2_len {
            result.push(vec![nums2[j][0], nums2[j][1]]);
            j += 1;
        }

        result
    }
}

#[cfg(test)]
mod tests {
    use super::Solution;
    use rstest::rstest;

    #[rstest]
    #[case(vec![vec![1, 2], vec![2, 3], vec![4, 5]], vec![vec![1, 4], vec![3, 2], vec![4, 1]], vec![vec![1, 6], vec![2, 3], vec![3, 2], vec![4, 6]])]
    #[case(vec![vec![1, 1], vec![2, 2], vec![3, 3]], vec![vec![2, 1], vec![3, 2], vec![4, 3]], vec![vec![1, 1], vec![2, 3], vec![3, 5], vec![4, 3]])]
    fn test_merge_arrays(
        #[case] nums1: Vec<Vec<i32>>,
        #[case] nums2: Vec<Vec<i32>>,
        #[case] expected: Vec<Vec<i32>>,
    ) {
        assert_eq!(Solution::merge_arrays(nums1, nums2), expected);
    }
}
