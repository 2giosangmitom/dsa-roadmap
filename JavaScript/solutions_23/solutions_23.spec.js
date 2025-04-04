import { describe, expect, test } from "vitest";
import { ListNode } from "../lib/linked_list";
import { mergeKLists } from "./solutions_23";

const testCases = [
	{
		lists: [
			ListNode.from([1, 4, 5]),
			ListNode.from([1, 3, 4]),
			ListNode.from([2, 6]),
		],
		expected: ListNode.from([1, 1, 2, 3, 4, 4, 5, 6]),
	},
	{
		lists: [],
		expected: null,
	},
	{
		lists: [ListNode.from([0])],
		expected: ListNode.from([0]),
	},
	{
		lists: [ListNode.from([5]), ListNode.from([1]), ListNode.from([3])],
		expected: ListNode.from([1, 3, 5]),
	},
	{
		lists: [
			ListNode.from([2, 2]),
			ListNode.from([2]),
			ListNode.from([2, 2, 2]),
		],
		expected: ListNode.from([2, 2, 2, 2, 2, 2]),
	},
	{
		lists: [null],
		expected: null,
	},
];

describe("mergeKLists", () => {
	testCases.forEach(({ lists, expected }, index) => {
		test(`case ${index}`, () => {
			const actual = mergeKLists(lists);
			expect(actual).toStrictEqual(expected);
		});
	});
});
