use crate::linked_list::linked_list::ListNode;

struct Solution;

impl Solution {
    pub fn reverse_list(head: Option<Box<ListNode>>) -> Option<Box<ListNode>> {
        let mut prev = None;
        let mut next = head;

        while let Some(node) = next.as_mut() {
            let next_node = node.next.take();
            node.next = prev.take();
            prev = next;
            next = next_node;
        }

        prev
    }
}

#[cfg(test)]
mod tests {
    use super::*;
    use rstest::rstest;

    #[rstest]
    #[case(vec![1, 2, 3, 4, 5], vec![5, 4, 3, 2, 1])]
    #[case(vec![1, 2], vec![2, 1])]
    #[case(vec![], vec![])]
    fn test_reverse_list(#[case] input: Vec<i32>, #[case] expected: Vec<i32>) {
        let head = ListNode::from_vec(input);
        let reversed_head = Solution::reverse_list(head);
        let result = ListNode::to_vec(reversed_head);
        assert_eq!(result, expected);
    }
}
