/**
 * @param {import("../lib/linked_list.js").ListNode} headA
 * @param {import("../lib/linked_list.js").ListNode} headB
 * @return {import("../lib/linked_list.js").ListNode}
 */
function getIntersectionNode(headA, headB) {
  let currentA = headA;
  let currentB = headB;

  while (currentA !== currentB) {
    currentA = currentA ? currentA.next : headB;
    currentB = currentB ? currentB.next : headA;
  }

  return currentA;
}

export { getIntersectionNode };
