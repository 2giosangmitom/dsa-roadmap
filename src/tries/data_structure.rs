#[derive(Default)]
pub struct TrieNode {
    pub children: [Option<Box<TrieNode>>; 26],
    pub is_end: bool,
}

impl TrieNode {
    pub fn new() -> Self {
        Self::default()
    }
}
