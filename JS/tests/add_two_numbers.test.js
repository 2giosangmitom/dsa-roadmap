import assert from "node:assert";
import { describe, it } from "node:test";
import { ListNode } from "../lib/linked_list.js";
import { addTwoNumbers } from "../src/add_two_numbers.js";

describe("addTwoNumbers", { concurrency: true, timeout: 1000 }, () => {
  it("should add two linked lists and return the correct result", () => {
    const l1 = ListNode.of(2, 4, 3);
    const l2 = ListNode.of(5, 6, 4);

    const result = addTwoNumbers(l1, l2);

    assert.deepStrictEqual(result, ListNode.of(7, 0, 8));
  });

  it("should handle carry over when adding two linked lists", () => {
    const l1 = ListNode.of(9, 9, 9);
    const l2 = ListNode.of(1);

    const result = addTwoNumbers(l1, l2);

    assert.deepStrictEqual(result, ListNode.of(0, 0, 0, 1));
  });

  it("should handle cases where one list is longer than the other", () => {
    const l1 = ListNode.of(1, 8);
    const l2 = ListNode.of(0);

    const result = addTwoNumbers(l1, l2);

    assert.deepStrictEqual(result, ListNode.of(1, 8));
  });

  it("should handle cases where the other list is longer", () => {
    const l1 = ListNode.of(0);
    const l2 = ListNode.of(5, 6, 4);

    const result = addTwoNumbers(l1, l2);

    assert.deepStrictEqual(result, ListNode.of(5, 6, 4));
  });

  it("should return the correct result for two empty lists", () => {
    const l1 = null;
    const l2 = null;

    const result = addTwoNumbers(l1, l2);

    assert.deepStrictEqual(result, null);
  });

  it("should return the correct result for one empty list", () => {
    const l1 = ListNode.of(1, 2, 3);
    const l2 = ListNode.of();

    const result = addTwoNumbers(l1, l2);

    assert.deepStrictEqual(result, ListNode.of(1, 2, 3));
  });
});
