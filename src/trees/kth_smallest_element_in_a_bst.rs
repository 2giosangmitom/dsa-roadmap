use crate::trees::data_structure::TreeNode;
use std::cell::RefCell;
use std::rc::Rc;

struct Solution;

impl Solution {
    pub fn kth_smallest(root: Option<Rc<RefCell<TreeNode>>>, k: i32) -> i32 {
        let mut stack = Vec::new();
        let mut current = root;
        let mut count = 0;
        loop {
            while let Some(node) = current {
                stack.push(node.clone());
                current = node.borrow().left.clone();
            }
            if let Some(node) = stack.pop() {
                count += 1;
                if count == k {
                    return node.borrow().val;
                }
                current = node.borrow().right.clone();
            } else {
                break;
            }
        }
        0
    }
}

#[cfg(test)]
mod tests {
    use super::*;
    use rstest::rstest;

    #[rstest]
    #[case(vec![Some(3), Some(1), Some(4), None, Some(2)], 1, 1)]
    #[case(
        vec![Some(5), Some(3), Some(6), Some(2), Some(4), None, None, Some(1)],
        3,
        3
    )]
    fn test(#[case] input: Vec<Option<i32>>, #[case] k: i32, #[case] expected: i32) {
        let root = TreeNode::from_vec(input);
        assert_eq!(Solution::kth_smallest(root, k), expected);
    }
}
