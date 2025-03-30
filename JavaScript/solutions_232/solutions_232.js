class MyQueue {
	/** @type {string[]} */
	#enqueueStack;
	/** @type {string[]} */
	#dequeueStack;

	constructor() {
		this.#enqueueStack = [];
		this.#dequeueStack = [];
	}

	/**
	 * @param {number} x
	 * @returns {void}
	 */
	push(x) {
		this.#enqueueStack.push(x);
	}

	/**
	 * @returns {number}
	 */
	pop() {
		if (this.#dequeueStack.length !== 0) {
			return this.#dequeueStack.pop();
		}

		while (this.#enqueueStack.length > 0) {
			this.#dequeueStack.push(this.#enqueueStack.pop());
		}

		return this.#dequeueStack.pop();
	}

	/**
	 * @returns {number}
	 */
	peek() {
		if (this.#dequeueStack.length !== 0) {
			return this.#dequeueStack[this.#dequeueStack.length - 1];
		}

		while (this.#enqueueStack.length > 0) {
			this.#dequeueStack.push(this.#enqueueStack.pop());
		}

		return this.#dequeueStack[this.#dequeueStack.length - 1];
	}

	/**
	 * @returns {boolean}
	 */
	empty() {
		return this.#enqueueStack.length === 0 && this.#dequeueStack.length === 0;
	}
}

export { MyQueue };
