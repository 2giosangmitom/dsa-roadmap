struct Solution;

impl Solution {
    pub fn three_sum(mut nums: Vec<i32>) -> Vec<Vec<i32>> {
        nums.sort_unstable();
        let n = nums.len();
        let mut result: Vec<Vec<i32>> = Vec::new();

        for i in 0..n {
            if i > 0 && nums[i] == nums[i - 1] {
                continue;
            }
            if nums[i] > 0 {
                break;
            }

            let mut left = i + 1;
            let mut right = n.saturating_sub(1);

            while left < right {
                let sum = nums[i] + nums[left] + nums[right];
                if sum == 0 {
                    result.push(vec![nums[i], nums[left], nums[right]]);
                    left += 1;
                    right -= 1;
                    while left < right && nums[left] == nums[left - 1] {
                        left += 1;
                    }
                    while left < right && nums[right] == nums[right + 1] {
                        right -= 1;
                    }
                } else if sum < 0 {
                    left += 1;
                } else {
                    right -= 1;
                }
            }
        }

        result
    }
}

#[cfg(test)]
mod tests {
    use super::Solution;
    use rstest::rstest;

    fn sort_output(mut output: Vec<Vec<i32>>) -> Vec<Vec<i32>> {
        for v in &mut output {
            v.sort_unstable();
        }
        output.sort_unstable();
        output
    }

    #[rstest]
    #[case(vec![-1, 0, 1, 2, -1, -4], vec![vec![-1, -1, 2], vec![-1, 0, 1]])]
    #[case(vec![0, 1, 1], vec![])]
    #[case(vec![0, 0, 0], vec![vec![0, 0, 0]])]
    fn test_three_sum(#[case] nums: Vec<i32>, #[case] expected: Vec<Vec<i32>>) {
        let result = Solution::three_sum(nums);
        assert_eq!(sort_output(result), sort_output(expected));
    }
}
