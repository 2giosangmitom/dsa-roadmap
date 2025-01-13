import { ListNode } from "../lib/linked_list.js";

/**
 * @param {ListNode} l1
 * @param {ListNode} l2
 * @returns {ListNode}
 */
function addTwoNumbers(l1, l2) {
  let dummyHead = new ListNode();
  let tail = dummyHead;
  let carry = 0;

  while (l1 !== null || l2 !== null || carry !== 0) {
    let digit1 = l1?.val ?? 0;
    let digit2 = l2?.val ?? 0;

    let sum = digit1 + digit2 + carry;
    let digit = sum % 10;
    carry = Math.trunc(sum / 10);

    let newNode = new ListNode(digit, null);
    tail.next = newNode;
    tail = tail.next;

    l1 = l1?.next ?? null;
    l2 = l2?.next ?? null;
  }

  return dummyHead.next;
}

export { addTwoNumbers };
