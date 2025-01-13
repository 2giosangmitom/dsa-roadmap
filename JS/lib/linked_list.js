class ListNode {
	/**
	 * @param {number} val
	 * @param {ListNode | null} next
	 */
	constructor(val = 0, next = null) {
		this.val = val;
		this.next = next;
	}

	/**
	 * @param {number[]} nums
	 * @returns {ListNode}
	 */
	static of(...nums) {
		if (nums.length === 0) return null;

		let head = null;

		for (let i = nums.length - 1; i >= 0; --i) {
			head = new ListNode(nums[i], head);
		}

		return head;
	}

	/**
	 * @returns {string}
	 */
	toString() {
		let head = this;
		let s = "";

		while (head) {
			s = s.concat(head.val.toString());
			if (head.next) {
				s = s.concat(" -> ");
			}
			head = head.next;
		}

		return s;
	}
}

export { ListNode };
