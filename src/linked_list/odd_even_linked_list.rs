use crate::linked_list::data_structure::ListNode;

struct Solution;

impl Solution {
    pub fn odd_even_list(head: Option<Box<ListNode>>) -> Option<Box<ListNode>> {
        let mut current = head;
        let mut odd_dummy = Box::new(ListNode::new(0));
        let mut even_dummy = Box::new(ListNode::new(0));
        let mut odd_tail = &mut odd_dummy;
        let mut even_tail = &mut even_dummy;
        let mut is_odd = true;

        while let Some(mut node) = current {
            current = node.next.take();
            if is_odd {
                odd_tail.next = Some(node);
                odd_tail = odd_tail.next.as_mut().unwrap();
            } else {
                even_tail.next = Some(node);
                even_tail = even_tail.next.as_mut().unwrap();
            }
            is_odd = !is_odd;
        }

        odd_tail.next = even_dummy.next;
        odd_dummy.next
    }
}

#[cfg(test)]
mod tests {
    use super::*;
    use rstest::rstest;

    #[rstest]
    #[case(vec![1, 2, 3, 4, 5], vec![1, 3, 5, 2, 4])]
    #[case(vec![2, 1, 3, 5, 6, 4, 7], vec![2, 3, 6, 7, 1, 5, 4])]
    #[case(vec![1], vec![1])]
    fn test_odd_even_list(#[case] input: Vec<i32>, #[case] expected: Vec<i32>) {
        let head = ListNode::from_vec(input);
        let result = Solution::odd_even_list(head);
        assert_eq!(ListNode::to_vec(result), expected);
    }
}
