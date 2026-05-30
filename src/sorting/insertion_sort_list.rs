use crate::linked_list::data_structure::ListNode;

struct Solution;

impl Solution {
    pub fn insertion_sort_list(head: Option<Box<ListNode>>) -> Option<Box<ListNode>> {
        let mut dummy = Box::new(ListNode { val: 0, next: head });
        let mut curr = dummy.next.take();

        while let Some(mut node) = curr {
            let next = node.next.take();
            let mut insert_pos = &mut dummy;

            while insert_pos.next.is_some() && insert_pos.next.as_ref().unwrap().val < node.val {
                insert_pos = insert_pos.next.as_mut().unwrap();
            }

            node.next = insert_pos.next.take();
            insert_pos.next = Some(node);
            curr = next;
        }

        dummy.next
    }
}

#[cfg(test)]
mod tests {
    use super::*;
    use rstest::rstest;

    #[rstest]
    #[case(vec![4, 2, 1, 3], vec![1, 2, 3, 4])]
    #[case(vec![-1, 5, 3, 4, 0], vec![-1, 0, 3, 4, 5])]
    fn test_insertion_sort_list(#[case] input: Vec<i32>, #[case] expected: Vec<i32>) {
        let head = ListNode::from_vec(input);
        let result = Solution::insertion_sort_list(head);
        assert_eq!(ListNode::to_vec(result), expected);
    }
}
