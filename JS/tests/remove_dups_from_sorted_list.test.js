import assert from "node:assert";
import { describe, it } from "node:test";
import { ListNode } from "../lib/linked_list.js";
import { deleteDuplicates } from "../src/remove_dups_from_sorted_list.js";

describe("deleteDuplicates", { concurrency: true, timeout: 1000 }, () => {
  it("should return 1 -> 2 for input 1 -> 1 -> 2", () => {
    const list = ListNode.of(1, 1, 2);
    const expected = ListNode.of(1, 2);

    const actual = deleteDuplicates(list);

    assert.strictEqual(actual.toString(), expected.toString());
  });

  it("should return 1 -> 2 -> 3 for input 1 -> 1 -> 2 -> 3 -> 3", () => {
    const list = ListNode.of(1, 1, 2, 3, 3);
    const expected = ListNode.of(1, 2, 3);

    const actual = deleteDuplicates(list);

    assert.strictEqual(actual.toString(), expected.toString());
  });

  it("should return 1 for input 1 -> 1 -> 1", () => {
    const list = ListNode.of(1, 1, 1);
    const expected = ListNode.of(1);

    const actual = deleteDuplicates(list);

    assert.strictEqual(actual.toString(), expected.toString());
  });

  it("should return 1 -> 2 -> 3 -> 4 for input 1 -> 2 -> 3 -> 4", () => {
    const list = ListNode.of(1, 2, 3, 4);
    const expected = ListNode.of(1, 2, 3, 4);

    const actual = deleteDuplicates(list);

    assert.strictEqual(actual.toString(), expected.toString());
  });

  it("should return null for input null", () => {
    const list = null;
    const expected = null;

    const actual = deleteDuplicates(list);

    assert.strictEqual(actual, expected);
  });

  it("should return -3 -> -2 -> -1 -> 0 for input -3 -> -3 -> -2 -> -1 -> -1 -> 0", () => {
    const list = ListNode.of(-3, -3, -2, -1, -1, 0);
    const expected = ListNode.of(-3, -2, -1, 0);

    const actual = deleteDuplicates(list);

    assert.strictEqual(actual.toString(), expected.toString());
  });

  it("should return -2 -> -1 -> 0 -> 1 -> 2 for input -2 -> -1 -> 0 -> 1 -> 2 -> 2", () => {
    const list = ListNode.of(-2, -1, 0, 1, 2, 2);
    const expected = ListNode.of(-2, -1, 0, 1, 2);

    const actual = deleteDuplicates(list);

    assert.strictEqual(actual.toString(), expected.toString());
  });
});
