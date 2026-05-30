use crate::linked_list::data_structure::ListNode;

struct Solution;

impl Solution {
    pub fn middle_node(head: Option<Box<ListNode>>) -> Option<Box<ListNode>> {
        let mut slow = &head;
        let mut fast = &head;

        while fast.is_some() && fast.as_ref().unwrap().next.is_some() {
            slow = &slow.as_ref().unwrap().next;
            fast = &fast.as_ref().unwrap().next.as_ref().unwrap().next;
        }

        slow.clone()
    }
}

#[cfg(test)]
mod tests {
    use super::*;
    use rstest::rstest;

    #[rstest]
    #[case(vec![1, 2, 3, 4, 5], vec![3, 4, 5])]
    #[case(vec![1, 2, 3, 4, 5, 6], vec![4, 5, 6])]
    #[case(vec![1], vec![1])]
    fn test_middle_node(#[case] input: Vec<i32>, #[case] expected: Vec<i32>) {
        let head = ListNode::from_vec(input);
        let result = Solution::middle_node(head);
        let result_vec = ListNode::to_vec(result);
        assert_eq!(result_vec, expected);
    }
}
