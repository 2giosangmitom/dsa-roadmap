use crate::trees::data_structure::TreeNode;
use std::cell::RefCell;
use std::rc::Rc;

struct Solution;

impl Solution {
    fn helper(nums: &[i32]) -> Option<Rc<RefCell<TreeNode>>> {
        if nums.is_empty() {
            return None;
        }
        let mid = nums.len() / 2;
        let mut node = TreeNode::new(nums[mid]);
        node.left = Self::helper(&nums[..mid]);
        node.right = Self::helper(&nums[mid + 1..]);
        Some(Rc::new(RefCell::new(node)))
    }

    pub fn sorted_array_to_bst(nums: Vec<i32>) -> Option<Rc<RefCell<TreeNode>>> {
        Self::helper(&nums)
    }
}

#[cfg(test)]
mod tests {
    use super::*;
    use rstest::rstest;

    #[rstest]
    #[case(vec![-10, -3, 0, 5, 9], vec![Some(0), Some(-3), Some(9), Some(-10), None, Some(5)])]
    #[case(vec![1, 3], vec![Some(3), Some(1)])]
    fn test(#[case] nums: Vec<i32>, #[case] expected: Vec<Option<i32>>) {
        let root = Solution::sorted_array_to_bst(nums);
        let expected_root = TreeNode::from_vec(expected);
        assert_eq!(root, expected_root);
    }
}
