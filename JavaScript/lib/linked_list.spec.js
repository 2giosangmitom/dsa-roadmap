import { describe, expect, it } from "vitest";
import { ListNode } from "./linked_list.js";

describe("ListNode.from", () => {
	it("should return null when passing an empty array", () => {
		const nums = [];

		const actual = ListNode.from(nums);

		expect(actual).toBeNull();
	});

	it("should return 1 -> 2 -> 3 linked list when passing [1, 2, 3]", () => {
		const nums = [1, 2, 3];
		const expected = new ListNode(1, new ListNode(2, new ListNode(3)));

		const actual = ListNode.from(nums);

		expect(actual).toStrictEqual(expected);
	});
});

describe("ListNode.toString", () => {
	it("should return '1 -> 2 -> 3' when passing a corresponding ListNode", () => {
		const head = ListNode.from([1, 2, 3]);
		const expected = "1 -> 2 -> 3";

		const actual = head.toString();

		expect(actual).toBe(expected);
	});
});
