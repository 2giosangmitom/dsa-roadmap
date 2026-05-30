struct TrieNode {
    children: [Option<Box<TrieNode>>; 26],
    word: Option<String>,
}

impl TrieNode {
    fn new() -> Self {
        TrieNode {
            children: Default::default(),
            word: None,
        }
    }
}

struct Solution;

impl Solution {
    pub fn find_words(board: Vec<Vec<char>>, words: Vec<String>) -> Vec<String> {
        let mut root = TrieNode::new();
        for w in &words {
            let mut node = &mut root;
            for &b in w.as_bytes() {
                let idx = (b - b'a') as usize;
                node = node.children[idx].get_or_insert_with(|| Box::new(TrieNode::new()));
            }
            node.word = Some(w.clone());
        }

        let mut board = board;
        let mut result = Vec::new();
        for r in 0..board.len() {
            for c in 0..board[0].len() {
                Self::dfs(&mut board, r as i32, c as i32, &root, &mut result);
            }
        }
        result
    }

    fn dfs(board: &mut Vec<Vec<char>>, r: i32, c: i32, node: &TrieNode, result: &mut Vec<String>) {
        if r < 0 || r >= board.len() as i32 || c < 0 || c >= board[0].len() as i32 {
            return;
        }
        let ch = board[r as usize][c as usize];
        if ch == '#' {
            return;
        }
        let idx = (ch as u8 - b'a') as usize;
        let Some(next) = &node.children[idx] else {
            return;
        };
        if let Some(w) = &next.word {
            result.push(w.clone());
        }
        board[r as usize][c as usize] = '#';
        Self::dfs(board, r + 1, c, next, result);
        Self::dfs(board, r - 1, c, next, result);
        Self::dfs(board, r, c + 1, next, result);
        Self::dfs(board, r, c - 1, next, result);
        board[r as usize][c as usize] = ch;
    }
}

#[cfg(test)]
mod tests {
    use super::Solution;
    use rstest::rstest;

    #[rstest]
    #[case(
        vec![
            vec!['o','a','a','n'],
            vec!['e','t','a','e'],
            vec!['i','h','k','r'],
            vec!['i','f','l','v'],
        ],
        vec!["oath".to_string(), "pea".to_string(), "eat".to_string(), "rain".to_string()],
        vec!["eat".to_string(), "oath".to_string()],
    )]
    fn test_find_words(
        #[case] board: Vec<Vec<char>>,
        #[case] words: Vec<String>,
        #[case] mut expected: Vec<String>,
    ) {
        let mut result = Solution::find_words(board, words);
        result.sort();
        expected.sort();
        assert_eq!(result, expected);
    }
}
