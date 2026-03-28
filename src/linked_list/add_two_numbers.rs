use crate::linked_list::data_structure::ListNode;

struct Solution;

impl Solution {
    pub fn add_two_numbers(
        mut l1: Option<Box<ListNode>>,
        mut l2: Option<Box<ListNode>>,
    ) -> Option<Box<ListNode>> {
        let mut head = ListNode::new(0);
        let mut current = &mut head;
        let mut carry = 0;

        while l1.is_some() || l2.is_some() || carry != 0 {
            let digit1 = match l1 {
                None => 0,
                Some(node) => {
                    l1 = node.next;
                    node.val
                }
            };
            let digit2 = match l2 {
                None => 0,
                Some(node) => {
                    l2 = node.next;
                    node.val
                }
            };

            let sum = digit1 + digit2 + carry;
            current.next = Some(Box::new(ListNode::new(sum % 10)));
            carry = sum / 10;
            current = current.next.as_mut()?;
        }

        head.next
    }
}

#[cfg(test)]
mod tests {
    use super::*;
    use rstest::rstest;

    #[rstest]
    #[case(vec![2, 4, 3], vec![5, 6, 4], vec![7, 0, 8])]
    #[case(vec![0], vec![0], vec![0])]
    #[case(vec![9, 9, 9, 9, 9, 9, 9], vec![9, 9, 9, 9], vec![8, 9, 9, 9, 0, 0, 0, 1])]
    fn test_add_two_numbers(
        #[case] input1: Vec<i32>,
        #[case] input2: Vec<i32>,
        #[case] expected: Vec<i32>,
    ) {
        let l1 = ListNode::from_vec(input1);
        let l2 = ListNode::from_vec(input2);
        let result_head = Solution::add_two_numbers(l1, l2);
        let result = ListNode::to_vec(result_head);
        assert_eq!(result, expected);
    }
}
