use crate::linked_list::data_structure::DoublyNodeRef;

struct Solution;

impl Solution {
    pub fn flatten(head: Option<DoublyNodeRef>) -> Option<DoublyNodeRef> {
        head.as_ref()?;

        let mut stack = Vec::new();
        let mut current = head.clone();
        let mut prev: Option<DoublyNodeRef> = None;

        while let Some(node) = current {
            if let Some(prev_node) = prev.clone() {
                prev_node.borrow_mut().next = Some(node.clone());
                node.borrow_mut().prev = Some(prev_node);
            }

            let next = node.borrow_mut().next.take();
            if let Some(next_node) = next {
                stack.push(next_node);
            }

            if let Some(child) = node.borrow_mut().child.take() {
                current = Some(child);
            } else {
                current = stack.pop();
            }

            prev = Some(node);
        }

        head
    }
}

#[cfg(test)]
mod tests {
    use super::*;
    use crate::linked_list::data_structure::DoublyNode;
    use rstest::rstest;

    #[rstest]
    fn test_flatten() {
        let n1 = DoublyNode::new(1);
        let n2 = DoublyNode::new(2);
        let n3 = DoublyNode::new(3);
        let n4 = DoublyNode::new(4);
        let n5 = DoublyNode::new(5);
        let n6 = DoublyNode::new(6);
        let n7 = DoublyNode::new(7);
        let n8 = DoublyNode::new(8);
        let n9 = DoublyNode::new(9);
        let n10 = DoublyNode::new(10);
        let n11 = DoublyNode::new(11);
        let n12 = DoublyNode::new(12);

        n1.borrow_mut().next = Some(n2.clone());
        n2.borrow_mut().prev = Some(n1.clone());
        n2.borrow_mut().next = Some(n3.clone());
        n3.borrow_mut().prev = Some(n2.clone());
        n3.borrow_mut().next = Some(n4.clone());
        n4.borrow_mut().prev = Some(n3.clone());
        n4.borrow_mut().next = Some(n5.clone());
        n5.borrow_mut().prev = Some(n4.clone());
        n5.borrow_mut().next = Some(n6.clone());
        n6.borrow_mut().prev = Some(n5.clone());

        n3.borrow_mut().child = Some(n7.clone());
        n7.borrow_mut().next = Some(n8.clone());
        n8.borrow_mut().prev = Some(n7.clone());
        n8.borrow_mut().next = Some(n9.clone());
        n9.borrow_mut().prev = Some(n8.clone());
        n9.borrow_mut().next = Some(n10.clone());
        n10.borrow_mut().prev = Some(n9.clone());

        n8.borrow_mut().child = Some(n11.clone());
        n11.borrow_mut().next = Some(n12.clone());
        n12.borrow_mut().prev = Some(n11.clone());

        let result = Solution::flatten(Some(n1));
        let expected = vec![1, 2, 3, 7, 8, 11, 12, 9, 10, 4, 5, 6];
        assert_eq!(DoublyNode::to_vec(result), expected);
    }
}
