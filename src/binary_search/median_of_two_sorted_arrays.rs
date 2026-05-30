struct Solution;

impl Solution {
    pub fn find_median_sorted_arrays(nums1: Vec<i32>, nums2: Vec<i32>) -> f64 {
        let (a, b) = if nums1.len() <= nums2.len() {
            (nums1, nums2)
        } else {
            (nums2, nums1)
        };

        let m = a.len();
        let n = b.len();
        let half = (m + n).div_ceil(2);
        let mut left = 0;
        let mut right = m;

        while left <= right {
            let i = (left + right) / 2;
            let j = half - i;

            let a_left = if i == 0 { i32::MIN } else { a[i - 1] };
            let a_right = if i == m { i32::MAX } else { a[i] };
            let b_left = if j == 0 { i32::MIN } else { b[j - 1] };
            let b_right = if j == n { i32::MAX } else { b[j] };

            if a_left <= b_right && b_left <= a_right {
                if (m + n) % 2 == 0 {
                    let left_max = a_left.max(b_left) as f64;
                    let right_min = a_right.min(b_right) as f64;
                    return (left_max + right_min) / 2.0;
                }
                return a_left.max(b_left) as f64;
            } else if a_left > b_right {
                if i == 0 {
                    break;
                }
                right = i - 1;
            } else {
                left = i + 1;
            }
        }

        0.0
    }
}

#[cfg(test)]
mod tests {
    use super::Solution;
    use rstest::rstest;

    #[rstest]
    #[case(vec![1, 3], vec![2], 2.0)]
    #[case(vec![1, 2], vec![3, 4], 2.5)]
    #[case(vec![0, 0], vec![0, 0], 0.0)]
    fn test_find_median_sorted_arrays(
        #[case] nums1: Vec<i32>,
        #[case] nums2: Vec<i32>,
        #[case] expected: f64,
    ) {
        assert!((Solution::find_median_sorted_arrays(nums1, nums2) - expected).abs() < 1e-6);
    }
}
