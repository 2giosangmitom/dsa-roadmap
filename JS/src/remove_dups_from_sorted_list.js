import { ListNode } from '../lib/linked_list.js'

/**
 * @param {ListNode} prevNode
 * @param {ListNode} node
 */
function deleteNode (prevNode, node) {
  if (prevNode) {
    prevNode.next = node.next
  }
}

/**
 * @param {ListNode} head
 * @return {ListNode}
 */
function deleteDuplicates (head) {
  if (!head) {
    return null
  }
  let current = head
  let val = current.val
  let prev = head

  current = current.next

  while (current) {
    if (current?.val === val) {
      deleteNode(prev, current)
    } else {
      val = current.val
      prev = current
    }
    current = current.next
  }

  return head
}

export { deleteDuplicates }
