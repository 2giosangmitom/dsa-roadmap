use std::collections::HashMap;

struct Solution;

impl Solution {
    pub fn roman_to_int(s: String) -> i32 {
        let mut map = HashMap::new();
        map.insert('I', 1);
        map.insert('V', 5);
        map.insert('X', 10);
        map.insert('L', 50);
        map.insert('C', 100);
        map.insert('D', 500);
        map.insert('M', 1000);

        let chars: Vec<char> = s.chars().collect();
        let mut total = 0;

        for i in 0..chars.len() {
            let value = map[&chars[i]];
            if i + 1 < chars.len() && value < map[&chars[i + 1]] {
                total -= value;
            } else {
                total += value;
            }
        }

        total
    }
}

#[cfg(test)]
mod tests {
    use super::Solution;
    use rstest::rstest;

    #[rstest]
    #[case(String::from("III"), 3)]
    #[case(String::from("LVIII"), 58)]
    #[case(String::from("MCMXCIV"), 1994)]
    fn test_roman_to_int(#[case] s: String, #[case] expected: i32) {
        assert_eq!(Solution::roman_to_int(s), expected);
    }
}
