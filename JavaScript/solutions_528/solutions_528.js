class Solution {
	/** @type {number[]} */
	#prefixSum;

	/**
	 * @param {number[]} w
	 */
	constructor(w) {
		this.#prefixSum = new Array(w.length);
		this.#prefixSum[0] = w[0];

		for (let i = 1; i < w.length; i++) {
			this.#prefixSum[i] = this.#prefixSum[i - 1] + w[i];
		}
	}

	/**
	 * @returns {number}
	 */
	pickIndex() {
		const target =
			Math.trunc(Math.random() * this.#prefixSum[this.#prefixSum.length - 1]) +
			1;
		let left = 0;
		let right = this.#prefixSum.length - 1;

		while (left < right) {
			const mid = Math.trunc((left + right) / 2);

			if (this.#prefixSum[mid] < target) {
				left = mid + 1;
			} else {
				right = mid;
			}
		}

		return left;
	}
}

export { Solution };
