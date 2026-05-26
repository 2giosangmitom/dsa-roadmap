use crate::linked_list::data_structure::ListNode;

struct Solution;

impl Solution {
    pub fn remove_elements(head: Option<Box<ListNode>>, val: i32) -> Option<Box<ListNode>> {
        let mut dummy_head = ListNode::new(0);
        dummy_head.next = head;
        let mut current = &mut dummy_head;

        while let Some(node) = current.next.as_mut() {
            if node.val == val {
                current.next = node.next.take();
            } else {
                current = current.next.as_mut().unwrap();
            }
        }

        dummy_head.next
    }
}

#[cfg(test)]
mod tests {
    use super::*;
    use rstest::rstest;

    #[rstest]
    #[case(vec![1, 2, 6, 3, 4, 5, 6], 6, vec![1, 2, 3, 4, 5])]
    #[case(vec![], 1, vec![])]
    #[case(vec![7, 7, 7, 7], 7, vec![])]
    fn test_remove_elements(#[case] input: Vec<i32>, #[case] val: i32, #[case] expected: Vec<i32>) {
        let head = ListNode::from_vec(input);
        let result = Solution::remove_elements(head, val);
        let result_vec = ListNode::to_vec(result);
        assert_eq!(result_vec, expected);
    }
}
