use crate::trees::data_structure::TreeNode;
use std::cell::RefCell;
use std::rc::Rc;

struct Solution;

impl Solution {
    fn helper(preorder: &[i32], inorder: &[i32]) -> Option<Rc<RefCell<TreeNode>>> {
        if preorder.is_empty() {
            return None;
        }
        let val = preorder[0];
        let mid = inorder.iter().position(|&x| x == val).unwrap();
        let mut node = TreeNode::new(val);
        node.left = Self::helper(&preorder[1..=mid], &inorder[..mid]);
        node.right = Self::helper(&preorder[mid + 1..], &inorder[mid + 1..]);
        Some(Rc::new(RefCell::new(node)))
    }

    pub fn build_tree(preorder: Vec<i32>, inorder: Vec<i32>) -> Option<Rc<RefCell<TreeNode>>> {
        Self::helper(&preorder, &inorder)
    }
}

#[cfg(test)]
mod tests {
    use super::*;
    use rstest::rstest;

    #[rstest]
    #[case(
        vec![3, 9, 20, 15, 7],
        vec![9, 3, 15, 20, 7],
        vec![Some(3), Some(9), Some(20), None, None, Some(15), Some(7)]
    )]
    #[case(vec![-1], vec![-1], vec![Some(-1)])]
    fn test(
        #[case] preorder: Vec<i32>,
        #[case] inorder: Vec<i32>,
        #[case] expected: Vec<Option<i32>>,
    ) {
        let root = Solution::build_tree(preorder, inorder);
        let expected_root = TreeNode::from_vec(expected);
        assert_eq!(root, expected_root);
    }
}
