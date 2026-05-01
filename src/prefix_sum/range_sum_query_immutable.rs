struct NumArray {
    prefix_sum: Vec<i32>,
}

impl NumArray {
    fn new(nums: Vec<i32>) -> Self {
        let mut prefix_sum = vec![0; nums.len()];
        prefix_sum[0] = nums[0];
        for i in 1..nums.len() {
            prefix_sum[i] = prefix_sum[i - 1] + nums[i];
        }
        Self { prefix_sum }
    }

    fn sum_range(&self, left: i32, right: i32) -> i32 {
        if left == 0 {
            return self.prefix_sum[right as usize];
        }
        self.prefix_sum[right as usize] - self.prefix_sum[left as usize - 1]
    }
}

#[cfg(test)]
mod tests {
    use super::*;
    use rstest::rstest;

    #[rstest]
    #[case(vec![-2, 0, 3, -5, 2, -1], 0, 2, 1)]
    #[case(vec![-2, 0, 3, -5, 2, -1], 2, 5, -1)]
    #[case(vec![-2, 0, 3, -5, 2, -1], 0, 5, -3)]
    fn test_num_array(
        #[case] nums: Vec<i32>,
        #[case] left: i32,
        #[case] right: i32,
        #[case] expected: i32,
    ) {
        let num_array = NumArray::new(nums);
        assert_eq!(num_array.sum_range(left, right), expected);
    }
}
