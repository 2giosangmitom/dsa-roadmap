class ListNode {
	/**
	 * @param {number} val
	 * @param {ListNode|null} next
	 */
	constructor(val = 0, next = null) {
		this.val = val;
		this.next = next;
	}

	/**
	 * @param {number[]} nums
	 * @returns {ListNode|null}
	 */
	static from(nums) {
		if (nums.length === 0) return null;

		const head = new ListNode(nums[0]);
		let current = head;

		for (let i = 1; i < nums.length; i++) {
			current.next = new ListNode(nums[i]);
			current = current.next;
		}

		return head;
	}
}

export { ListNode };
