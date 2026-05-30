struct Solution;

impl Solution {
    pub fn merge_arrays(nums1: Vec<Vec<i32>>, nums2: Vec<Vec<i32>>) -> Vec<Vec<i32>> {
        let mut i = 0;
        let mut j = 0;
        let mut result = Vec::new();

        while i < nums1.len() && j < nums2.len() {
            let (id1, val1) = (nums1[i][0], nums1[i][1]);
            let (id2, val2) = (nums2[j][0], nums2[j][1]);

            if id1 == id2 {
                result.push(vec![id1, val1 + val2]);
                i += 1;
                j += 1;
            } else if id1 < id2 {
                result.push(vec![id1, val1]);
                i += 1;
            } else {
                result.push(vec![id2, val2]);
                j += 1;
            }
        }

        while i < nums1.len() {
            result.push(nums1[i].clone());
            i += 1;
        }
        while j < nums2.len() {
            result.push(nums2[j].clone());
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
    #[case(vec![vec![2, 4], vec![3, 6], vec![5, 5]], vec![vec![1, 3], vec![4, 3]], vec![vec![1, 3], vec![2, 4], vec![3, 6], vec![4, 3], vec![5, 5]])]
    fn test_merge_arrays(
        #[case] nums1: Vec<Vec<i32>>,
        #[case] nums2: Vec<Vec<i32>>,
        #[case] expected: Vec<Vec<i32>>,
    ) {
        assert_eq!(Solution::merge_arrays(nums1, nums2), expected);
    }
}
