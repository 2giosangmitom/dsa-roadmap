use crate::tries::data_structure::TrieNode;

pub struct WordDictionary {
    root: TrieNode,
}

impl WordDictionary {
    pub fn new() -> Self {
        WordDictionary {
            root: TrieNode::new(),
        }
    }

    pub fn add_word(&mut self, word: String) {
        let mut node = &mut self.root;
        for &b in word.as_bytes() {
            let idx = (b - b'a') as usize;
            node = node.children[idx].get_or_insert_with(|| Box::new(TrieNode::new()));
        }
        node.is_end = true;
    }

    pub fn search(&self, word: String) -> bool {
        Self::search_node(&self.root, word.as_bytes(), 0)
    }

    fn search_node(node: &TrieNode, word: &[u8], idx: usize) -> bool {
        if idx == word.len() {
            return node.is_end;
        }
        let ch = word[idx];
        if ch == b'.' {
            for child_node in node.children.iter().flatten() {
                if Self::search_node(child_node, word, idx + 1) {
                    return true;
                }
            }
            false
        } else {
            let i = (ch - b'a') as usize;
            match &node.children[i] {
                Some(child) => Self::search_node(child, word, idx + 1),
                None => false,
            }
        }
    }
}

#[cfg(test)]
mod tests {
    use super::WordDictionary;
    use rstest::rstest;

    #[rstest]
    fn test_word_dictionary() {
        let mut dict = WordDictionary::new();
        dict.add_word("bad".to_string());
        dict.add_word("dad".to_string());
        dict.add_word("mad".to_string());
        assert!(!dict.search("pad".to_string()));
        assert!(dict.search("bad".to_string()));
        assert!(dict.search(".ad".to_string()));
        assert!(dict.search("b..".to_string()));
    }
}
