use std::cell::RefCell;
use std::collections::HashMap;
use std::rc::Rc;

#[derive(Debug, PartialEq, Eq)]
pub struct Node {
    pub val: i32,
    pub neighbors: Vec<Rc<RefCell<Node>>>,
}

struct Solution;

impl Solution {
    pub fn clone_graph(node: Option<Rc<RefCell<Node>>>) -> Option<Rc<RefCell<Node>>> {
        let mut map = HashMap::new();
        Self::dfs(&node, &mut map)
    }

    fn dfs(
        node: &Option<Rc<RefCell<Node>>>,
        map: &mut HashMap<i32, Rc<RefCell<Node>>>,
    ) -> Option<Rc<RefCell<Node>>> {
        let node = node.as_ref()?;
        let val = node.borrow().val;
        if let Some(clone) = map.get(&val) {
            return Some(clone.clone());
        }
        let clone = Rc::new(RefCell::new(Node {
            val,
            neighbors: vec![],
        }));
        map.insert(val, clone.clone());
        for neighbor in &node.borrow().neighbors {
            if let Some(neighbor_clone) = Self::dfs(&Some(neighbor.clone()), map) {
                clone.borrow_mut().neighbors.push(neighbor_clone);
            }
        }
        Some(clone)
    }
}

#[cfg(test)]
mod tests {
    use super::*;
    use rstest::rstest;

    fn make_node(val: i32) -> Rc<RefCell<Node>> {
        Rc::new(RefCell::new(Node {
            val,
            neighbors: vec![],
        }))
    }

    #[rstest]
    #[case(1, 2)]
    fn test_clone_graph(#[case] a: i32, #[case] b: i32) {
        let n1 = make_node(a);
        let n2 = make_node(b);
        n1.borrow_mut().neighbors.push(n2.clone());
        n2.borrow_mut().neighbors.push(n1.clone());
        let cloned = Solution::clone_graph(Some(n1.clone())).unwrap();
        assert_eq!(cloned.borrow().val, a);
        assert_eq!(cloned.borrow().neighbors.len(), 1);
        assert_eq!(cloned.borrow().neighbors[0].borrow().val, b);
        assert_ne!(cloned.as_ptr(), n1.as_ptr());
    }
}
