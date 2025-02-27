import { ListNode } from '../lib/linked_list.js'

/**
 * @param {ListNode} list1
 * @param {ListNode} list2
 * @return {ListNode}
 */
function mergeTwoLists (list1, list2) {
  const res = new ListNode()
  let head = res

  while (list1 && list2) {
    const num1 = list1.val
    const num2 = list2.val

    if (num1 <= num2) {
      const newNode = new ListNode(num1)
      head.next = newNode
      head = head.next
      list1 = list1.next
    } else {
      const newNode = new ListNode(num2)
      head.next = newNode
      head = head.next
      list2 = list2.next
    }
  }

  while (list1) {
    const newNode = new ListNode(list1.val)
    head.next = newNode
    head = head.next
    list1 = list1.next
  }

  while (list2) {
    const newNode = new ListNode(list2.val)
    head.next = newNode
    head = head.next
    list2 = list2.next
  }

  return res.next
}

export { mergeTwoLists }
