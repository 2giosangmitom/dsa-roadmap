import { ListNode } from "../lib/linked_list.js";

/**
 * @param {import("../lib/linked_list.js").ListNode[]} lists
 * @return {import("../lib/linked_list.js").ListNode}
 */
function mergeKLists(lists) {
	const heap = [];
	const dummyHead = new ListNode();

	for (const head of lists) {
		if (head) {
			heap_add(heap, head);
		}
	}

	let current = dummyHead;
	while (heap.length > 0) {
		const smallestNode = heap_pop(heap);
		current.next = smallestNode;
		current = current.next;

		if (smallestNode.next) {
			heap_add(heap, smallestNode.next);
		}
	}

	return dummyHead.next;
}

function heap_add(heap, head) {
	heap.push(head);
	let current = heap.length - 1;
	let parent = Math.floor((current - 1) / 2);

	while (current > 0 && heap[parent].val > heap[current].val) {
		[heap[parent], heap[current]] = [heap[current], heap[parent]];
		current = parent;
		parent = Math.floor((current - 1) / 2);
	}
}

function heap_pop(heap) {
	[heap[0], heap[heap.length - 1]] = [heap[heap.length - 1], heap[0]];
	const res = heap[heap.length - 1];
	heap.pop();

	let current = 0;
	while (true) {
		const leftChild = current * 2 + 1;
		const rightChild = current * 2 + 2;
		let min = current;

		if (leftChild < heap.length && heap[leftChild].val < heap[min].val) {
			min = leftChild;
		}

		if (rightChild < heap.length && heap[rightChild].val < heap[min].val) {
			min = rightChild;
		}

		if (min === current) break;

		[heap[min], heap[current]] = [heap[current], heap[min]];
		current = min;
	}

	return res;
}

export { mergeKLists };
