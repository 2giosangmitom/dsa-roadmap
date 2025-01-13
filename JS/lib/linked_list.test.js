import assert from "node:assert";
import { describe, it } from "node:test";
import { ListNode } from "./linked_list.js";

describe("ListNode", () => {
	it("should create a ListNode with the correct value and next node", () => {
		const node = new ListNode(5);
		assert.strictEqual(node.val, 5);
		assert.strictEqual(node.next, null);
	});

	it("should create a ListNode with a given value and next node", () => {
		const node2 = new ListNode(10);
		const node1 = new ListNode(5, node2);
		assert.strictEqual(node1.val, 5);
		assert.strictEqual(node1.next, node2);
		assert.strictEqual(node2.val, 10);
		assert.strictEqual(node2.next, null);
	});

	it('should create a linked list from an array of numbers using the "of" method', () => {
		const list = ListNode.of(1, 2, 3, 4, 5);
		assert.strictEqual(list.val, 1);
		assert.strictEqual(list.next.val, 2);
		assert.strictEqual(list.next.next.val, 3);
		assert.strictEqual(list.next.next.next.val, 4);
		assert.strictEqual(list.next.next.next.next.val, 5);
		assert.strictEqual(list.next.next.next.next.next, null);
	});

	it('should return null when calling "of" with an empty array', () => {
		const list = ListNode.of();
		assert.strictEqual(list, null);
	});

	it("return string representation of linked list correctly", () => {
		const list = ListNode.of(1, 2, 3, 4).toString();
		assert.strictEqual(list, "1 -> 2 -> 3 -> 4");
	});
});
