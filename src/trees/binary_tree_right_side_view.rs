use crate::trees::data_structure::TreeNode;
use std::cell::RefCell;
use std::collections::VecDeque;
use std::rc::Rc;

struct Solution;

impl Solution {
    pub fn right_side_view(root: Option<Rc<RefCell<TreeNode>>>) -> Vec<i32> {
        let mut result = Vec::new();
        if root.is_none() {
            return result;
        }
        let mut queue = VecDeque::new();
        queue.push_back(root.unwrap());
        while !queue.is_empty() {
            let level_len = queue.len();
            for i in 0..level_len {
                if let Some(node) = queue.pop_front() {
                    if i == level_len - 1 {
                        result.push(node.borrow().val);
                    }
                    if let Some(left) = &node.borrow().left {
                        queue.push_back(left.clone());
                    }
                    if let Some(right) = &node.borrow().right {
                        queue.push_back(right.clone());
                    }
                }
            }
        }
        result
    }
}

#[cfg(test)]
mod tests {
    use super::*;
    use rstest::rstest;

    #[rstest]
    #[case(
        vec![Some(1), Some(2), Some(3), None, Some(5), None, Some(4)],
        vec![1, 3, 4]
    )]
    #[case(vec![Some(1), None, Some(3)], vec![1, 3])]
    fn test(#[case] input: Vec<Option<i32>>, #[case] expected: Vec<i32>) {
        let root = TreeNode::from_vec(input);
        assert_eq!(Solution::right_side_view(root), expected);
    }
}
