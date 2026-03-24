struct Solution;

impl Solution {
    // Quick Sort implementation
    fn partition(nums: &mut [i32], left: i32, right: i32) -> i32 {
        let pivot = nums[right as usize];
        let mut i = left;

        for j in left..right {
            if nums[j as usize] <= pivot {
                nums.swap(i as usize, j as usize);
                i += 1;
            }
        }
        nums.swap(i as usize, right as usize);

        i
    }

    fn quick_sort(nums: &mut [i32], left: i32, right: i32) {
        if left < right {
            let pivot_index = Self::partition(nums, left, right);
            Self::quick_sort(nums, left, pivot_index - 1);
            Self::quick_sort(nums, pivot_index + 1, right);
        }
    }

    // Merge Sort implementation
    fn merge(nums: &mut [i32], left: usize, right: usize, mid: usize) {
        let mut left_nums = Vec::<i32>::new();
        let mut right_nums = Vec::<i32>::new();
        nums[left..=mid].clone_into(&mut left_nums);
        nums[mid + 1..=right].clone_into(&mut right_nums);

        let (mut i, mut j, mut k) = (0, 0, left);

        let left_len = mid - left + 1;
        let right_len = right - mid;

        while i < left_len && j < right_len {
            if left_nums[i] <= right_nums[j] {
                nums[k] = left_nums[i];
                i += 1;
            } else {
                nums[k] = right_nums[j];
                j += 1;
            }
            k += 1;
        }

        while i < left_len {
            nums[k] = left_nums[i];
            i += 1;
            k += 1;
        }

        while j < right_len {
            nums[k] = right_nums[j];
            j += 1;
            k += 1;
        }
    }

    fn merge_sort(nums: &mut [i32], left: usize, right: usize) {
        if left < right {
            let mid = (left + right) / 2;
            Self::merge_sort(nums, left, mid);
            Self::merge_sort(nums, mid + 1, right);
            Self::merge(nums, left, right, mid);
        }
    }

    pub fn sort_array(mut nums: Vec<i32>) -> Vec<i32> {
        let n = nums.len();
        Self::merge_sort(&mut nums, 0, n - 1);
        nums
    }

    pub fn sort_array_quick(mut nums: Vec<i32>) -> Vec<i32> {
        let n = nums.len();
        Self::quick_sort(&mut nums, 0, (n - 1) as i32);
        nums
    }
}

#[cfg(test)]
mod tests {
    use super::Solution;
    use rstest::*;
    use rstest_reuse::{apply, template};

    #[template]
    #[rstest]
    #[case(vec![5, 2, 3, 1], vec![1, 2, 3, 5])]
    #[case(vec![5, 1, 1, 2, 0, 0], vec![0, 0, 1, 1, 2, 5])]
    fn test_template(#[case] input: Vec<i32>, #[case] expected: Vec<i32>) {}

    #[apply(test_template)]
    fn test_merge_sort(#[case] input: Vec<i32>, #[case] expected: Vec<i32>) {
        assert_eq!(Solution::sort_array(input), expected);
    }

    #[apply(test_template)]
    fn test_quick_sort(#[case] input: Vec<i32>, #[case] expected: Vec<i32>) {
        assert_eq!(Solution::sort_array_quick(input), expected);
    }
}
