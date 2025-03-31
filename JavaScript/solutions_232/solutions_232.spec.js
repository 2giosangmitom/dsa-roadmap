import { describe, expect, test } from "vitest";
import { MyQueue } from "./solutions_232.js";

describe("MyQueue", () => {
	test("should push and pop elements correctly", () => {
		const queue = new MyQueue();
		queue.push(1);
		queue.push(2);
		queue.push(3);
		expect(queue.pop()).toBe(1);
		expect(queue.pop()).toBe(2);
		expect(queue.pop()).toBe(3);
	});

	test("should return the correct front element with peek", () => {
		const queue = new MyQueue();
		queue.push(10);
		queue.push(20);
		expect(queue.peek()).toBe(10);
		queue.pop();
		expect(queue.peek()).toBe(20);
	});

	test("should return true when empty, false otherwise", () => {
		const queue = new MyQueue();
		expect(queue.empty()).toBe(true);
		queue.push(5);
		expect(queue.empty()).toBe(false);
		queue.pop();
		expect(queue.empty()).toBe(true);
	});

	test("should handle mixed operations correctly", () => {
		const queue = new MyQueue();
		queue.push(1);
		queue.push(2);
		expect(queue.pop()).toBe(1);
		queue.push(3);
		expect(queue.peek()).toBe(2);
		expect(queue.pop()).toBe(2);
		expect(queue.pop()).toBe(3);
		expect(queue.empty()).toBe(true);
	});
});
