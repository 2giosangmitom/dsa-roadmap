use crate::trees::data_structure::TreeNode;
use std::cell::RefCell;
use std::rc::Rc;

struct Codec;

impl Codec {
    fn new() -> Self {
        Codec
    }

    fn serialize(&self, root: Option<Rc<RefCell<TreeNode>>>) -> String {
        fn helper(node: &Option<Rc<RefCell<TreeNode>>>, parts: &mut Vec<String>) {
            match node {
                None => parts.push("null".to_string()),
                Some(v) => {
                    parts.push(v.borrow().val.to_string());
                    helper(&v.borrow().left, parts);
                    helper(&v.borrow().right, parts);
                }
            }
        }
        let mut parts = Vec::new();
        helper(&root, &mut parts);
        parts.join(",")
    }

    fn deserialize(&self, data: String) -> Option<Rc<RefCell<TreeNode>>> {
        fn helper(it: &mut std::vec::IntoIter<String>) -> Option<Rc<RefCell<TreeNode>>> {
            if let Some(val) = it.next() {
                if val == "null" {
                    return None;
                }
                let val = val.parse::<i32>().unwrap();
                let mut node = TreeNode::new(val);
                node.left = helper(it);
                node.right = helper(it);
                Some(Rc::new(RefCell::new(node)))
            } else {
                None
            }
        }
        let parts: Vec<String> = data.split(',').map(|s| s.to_string()).collect();
        helper(&mut parts.into_iter())
    }
}

#[cfg(test)]
mod tests {
    use super::*;
    use rstest::rstest;

    #[rstest]
    #[case(vec![Some(1), Some(2), Some(3), None, None, Some(4), Some(5)])]
    #[case(vec![])]
    #[case(vec![Some(1)])]
    fn test(#[case] input: Vec<Option<i32>>) {
        let root = TreeNode::from_vec(input);
        let codec = Codec::new();
        let serialized = codec.serialize(root.clone());
        let deserialized = codec.deserialize(serialized);
        assert_eq!(root, deserialized);
    }
}
