// Definition for singly-linked list.
#[derive(PartialEq, Eq, Clone, Debug)]
pub struct ListNode {
    pub val: i32,
    pub next: Option<Box<ListNode>>,
}

impl ListNode {
    #[inline]
    pub fn new(val: i32) -> Self {
        ListNode { next: None, val }
    }

    pub fn from_vec(vec: Vec<i32>) -> Option<Box<ListNode>> {
        let mut head = None;
        let mut current = &mut head;

        for &value in vec.iter() {
            let new_node = Box::new(ListNode::new(value));
            *current = Some(new_node);
            if let Some(node) = current {
                current = &mut node.next;
            }
        }

        head
    }

    pub fn to_vec(head: Option<Box<ListNode>>) -> Vec<i32> {
        let mut vec = Vec::new();
        let mut current = head;

        while let Some(node) = current {
            vec.push(node.val);
            current = node.next;
        }

        vec
    }
}

#[cfg(test)]
mod tests {
    use super::*;
    use rstest::rstest;

    #[rstest]
    #[case(vec![1, 2, 3], vec![1, 2, 3])]
    #[case(vec![], vec![])]
    fn test_list_node(#[case] input: Vec<i32>, #[case] expected: Vec<i32>) {
        let head = ListNode::from_vec(input);
        let result = ListNode::to_vec(head);
        assert_eq!(result, expected);
    }
}
