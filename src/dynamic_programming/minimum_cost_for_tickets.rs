struct Solution;

impl Solution {
    pub fn mincost_tickets(days: Vec<i32>, costs: Vec<i32>) -> i32 {
        let last_day = days[days.len() - 1] as usize;
        let mut dp = vec![0; last_day + 1];
        let mut i = 0;
        for day in 1..=last_day {
            if i < days.len() && days[i] as usize == day {
                let cost1 = dp[day - 1] + costs[0];
                let cost7 = dp[day.saturating_sub(7)] + costs[1];
                let cost30 = dp[day.saturating_sub(30)] + costs[2];
                dp[day] = cost1.min(cost7).min(cost30);
                i += 1;
            } else {
                dp[day] = dp[day - 1];
            }
        }
        dp[last_day]
    }
}

#[cfg(test)]
mod tests {
    use super::*;
    use rstest::rstest;

    #[rstest]
    #[case(vec![1, 4, 6, 7, 8, 20], vec![2, 7, 15], 11)]
    #[case(vec![1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 30, 31], vec![2, 7, 15], 17)]
    fn test_mincost_tickets(
        #[case] days: Vec<i32>,
        #[case] costs: Vec<i32>,
        #[case] expected: i32,
    ) {
        assert_eq!(Solution::mincost_tickets(days, costs), expected);
    }
}
