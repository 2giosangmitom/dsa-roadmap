use crate::trees::data_structure::TreeNode;
use std::cell::RefCell;
use std::collections::VecDeque;
use std::rc::Rc;

struct Solution;

impl Solution {
    pub fn width_of_binary_tree(root: Option<Rc<RefCell<TreeNode>>>) -> i32 {
        if root.is_none() {
            return 0;
        }
        let mut queue = VecDeque::new();
        queue.push_back((root.unwrap(), 1i64));
        let mut max_width = 0i64;
        while !queue.is_empty() {
            let level_len = queue.len();
            let first = queue.front().unwrap().1;
            let mut last = first;
            for _ in 0..level_len {
                if let Some((node, idx)) = queue.pop_front() {
                    last = idx;
                    if let Some(left) = &node.borrow().left {
                        queue.push_back((left.clone(), idx * 2));
                    }
                    if let Some(right) = &node.borrow().right {
                        queue.push_back((right.clone(), idx * 2 + 1));
                    }
                }
            }
            max_width = max_width.max(last - first + 1);
        }
        max_width as i32
    }
}

#[cfg(test)]
mod tests {
    use super::*;
    use rstest::rstest;

    #[rstest]
    #[case(vec![Some(1), Some(3), Some(2), Some(5), Some(3), None, Some(9)], 4)]
    #[case(
        vec![Some(1), Some(3), Some(2), Some(5), None, None, Some(9), Some(6), None, Some(7)],
        7
    )]
    fn test(#[case] input: Vec<Option<i32>>, #[case] expected: i32) {
        let root = TreeNode::from_vec(input);
        assert_eq!(Solution::width_of_binary_tree(root), expected);
    }
}
