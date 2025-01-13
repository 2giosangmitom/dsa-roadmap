import assert from "node:assert";
import { describe, it } from "node:test";
import { ListNode } from "../lib/linked_list.js";
import { mergeTwoLists } from "../src/merge_two_sorted_lists.js";

describe("mergeTwoLists", () => {
  it("should merge two sorted lists correctly", () => {
    const l1 = ListNode.of(1, 2, 4);
    const l2 = ListNode.of(1, 3, 4);

    const result = mergeTwoLists(l1, l2);
    assert.strictEqual(result.toString(), "1 -> 1 -> 2 -> 3 -> 4 -> 4");
  });

  it("should return the second list if the first list is empty", () => {
    const l1 = ListNode.of();
    const l2 = ListNode.of(1, 2, 3);

    const result = mergeTwoLists(l1, l2);
    assert.strictEqual(result.toString(), "1 -> 2 -> 3");
  });

  it("should return the first list if the second list is empty", () => {
    const l1 = ListNode.of(1, 2, 3);
    const l2 = ListNode.of();

    const result = mergeTwoLists(l1, l2);
    assert.strictEqual(result.toString(), "1 -> 2 -> 3");
  });

  it("should merge two lists where one list is shorter than the other", () => {
    const l1 = ListNode.of(1, 4);
    const l2 = ListNode.of(2, 3, 5, 6);

    const result = mergeTwoLists(l1, l2);
    assert.strictEqual(result.toString(), "1 -> 2 -> 3 -> 4 -> 5 -> 6");
  });

  it("should handle two identical lists", () => {
    const l1 = ListNode.of(1, 2, 3);
    const l2 = ListNode.of(1, 2, 3);

    const result = mergeTwoLists(l1, l2);
    assert.strictEqual(result.toString(), "1 -> 1 -> 2 -> 2 -> 3 -> 3");
  });

  it("should handle lists with only one element each", () => {
    const l1 = ListNode.of(1);
    const l2 = ListNode.of(2);

    const result = mergeTwoLists(l1, l2);
    assert.strictEqual(result.toString(), "1 -> 2");
  });

  it("should handle two lists with the same value at the start", () => {
    const l1 = ListNode.of(1, 3, 5);
    const l2 = ListNode.of(1, 2, 4);

    const result = mergeTwoLists(l1, l2);
    assert.strictEqual(result.toString(), "1 -> 1 -> 2 -> 3 -> 4 -> 5");
  });
});
