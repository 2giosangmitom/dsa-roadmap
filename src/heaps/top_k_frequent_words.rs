use std::collections::HashMap;

struct Solution;

impl Solution {
    pub fn top_k_frequent(words: Vec<String>, k: i32) -> Vec<String> {
        let mut freq = HashMap::new();
        for word in words {
            *freq.entry(word).or_insert(0) += 1;
        }

        let mut pairs: Vec<(&String, &i32)> = freq.iter().collect();
        pairs.sort_by(|a, b| {
            if a.1 != b.1 {
                b.1.cmp(a.1)
            } else {
                a.0.cmp(b.0)
            }
        });

        pairs
            .into_iter()
            .take(k as usize)
            .map(|(w, _)| w.clone())
            .collect()
    }
}

#[cfg(test)]
mod tests {
    use super::*;
    use rstest::rstest;

    fn v(s: &[&str]) -> Vec<String> {
        s.iter().map(|x| x.to_string()).collect()
    }

    #[rstest]
    #[case(v(&["i", "love", "leetcode", "i", "love", "coding"]), 2, v(&["i", "love"]))]
    #[case(v(&["the", "day", "is", "sunny", "the", "the", "the", "sunny", "is", "is"]), 4, v(&["the", "is", "sunny", "day"]))]
    fn test_top_k_frequent_words(
        #[case] words: Vec<String>,
        #[case] k: i32,
        #[case] expected: Vec<String>,
    ) {
        assert_eq!(Solution::top_k_frequent(words, k), expected);
    }
}
