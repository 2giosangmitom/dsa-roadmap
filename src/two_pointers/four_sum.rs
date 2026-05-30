struct Solution;

impl Solution {
    pub fn four_sum(mut nums: Vec<i32>, target: i32) -> Vec<Vec<i32>> {
        nums.sort_unstable();
        let n = nums.len();
        let mut result: Vec<Vec<i32>> = Vec::new();

        for i in 0..n {
            if i > 0 && nums[i] == nums[i - 1] {
                continue;
            }

            for j in i + 1..n {
                if j > i + 1 && nums[j] == nums[j - 1] {
                    continue;
                }

                let mut left = j + 1;
                let mut right = n.saturating_sub(1);

                while left < right {
                    let sum =
                        nums[i] as i64 + nums[j] as i64 + nums[left] as i64 + nums[right] as i64;
                    let target = target as i64;

                    if sum == target {
                        result.push(vec![nums[i], nums[j], nums[left], nums[right]]);
                        left += 1;
                        right -= 1;
                        while left < right && nums[left] == nums[left - 1] {
                            left += 1;
                        }
                        while left < right && nums[right] == nums[right + 1] {
                            right -= 1;
                        }
                    } else if sum < target {
                        left += 1;
                    } else {
                        right -= 1;
                    }
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
    #[case(vec![1, 0, -1, 0, -2, 2], 0, vec![vec![-2, -1, 1, 2], vec![-2, 0, 0, 2], vec![-1, 0, 0, 1]])]
    #[case(vec![2, 2, 2, 2, 2], 8, vec![vec![2, 2, 2, 2]])]
    #[case(vec![], 0, vec![])]
    fn test_four_sum(#[case] nums: Vec<i32>, #[case] target: i32, #[case] expected: Vec<Vec<i32>>) {
        let result = Solution::four_sum(nums, target);
        assert_eq!(sort_output(result), sort_output(expected));
    }
}
