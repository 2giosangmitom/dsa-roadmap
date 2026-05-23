use std::cell::RefCell;
use std::collections::VecDeque;
use std::rc::Rc;

// Definition for a binary tree node.
#[derive(Debug, PartialEq, Eq)]
pub struct TreeNode {
    pub val: i32,
    pub left: Option<Rc<RefCell<TreeNode>>>,
    pub right: Option<Rc<RefCell<TreeNode>>>,
}

impl TreeNode {
    #[inline]
    pub fn new(val: i32) -> Self {
        TreeNode {
            val,
            left: None,
            right: None,
        }
    }

    pub fn from_vec(vec: Vec<Option<i32>>) -> Option<Rc<RefCell<Self>>> {
        if vec.is_empty() {
            return None;
        }

        let root = Rc::new(RefCell::new(TreeNode::new(vec[0].unwrap())));
        let mut queue = VecDeque::new();
        queue.push_back(root.clone());

        let mut i = 1;
        while i < vec.len() {
            if let Some(node) = queue.pop_front() {
                if let Some(val) = vec[i] {
                    let left_child = Rc::new(RefCell::new(TreeNode::new(val)));
                    node.borrow_mut().left = Some(left_child.clone());
                    queue.push_back(left_child);
                }
                i += 1;

                if i < vec.len() {
                    if let Some(val) = vec[i] {
                        let right_child = Rc::new(RefCell::new(TreeNode::new(val)));
                        node.borrow_mut().right = Some(right_child.clone());
                        queue.push_back(right_child);
                    }
                    i += 1;
                }
            }
        }

        Some(root)
    }
}

#[cfg(test)]
mod tests {
    use super::*;
    use rstest::rstest;

    #[rstest]
    #[case(vec![Some(1), None, Some(2), Some(3)], vec![1, 2, 3])]
    #[case(vec![], vec![])]
    #[case(vec![Some(1)], vec![1])]
    fn test_from_vec(#[case] input: Vec<Option<i32>>, #[case] expected: Vec<i32>) {
        let tree = TreeNode::from_vec(input);
        let mut result = Vec::new();
        if let Some(node) = tree {
            let mut queue = VecDeque::new();
            queue.push_back(node);
            while let Some(node) = queue.pop_front() {
                let node_ref = node.borrow();
                result.push(node_ref.val);
                if let Some(left) = &node_ref.left {
                    queue.push_back(left.clone());
                }
                if let Some(right) = &node_ref.right {
                    queue.push_back(right.clone());
                }
            }
        }
        assert_eq!(result, expected);
    }
}
