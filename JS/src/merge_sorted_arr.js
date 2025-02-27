/**
 * @param {number[]} nums1
 * @param {number} m
 * @param {number[]} nums2
 * @param {number} n
 */
function merge (nums1, m, nums2, n) {
  let i = 0
  let j = 0
  let k = 0

  const n1 = nums1.slice(0, m)

  while (i < m && j < n) {
    if (n1[i] <= nums2[j]) {
      nums1[k] = n1[i]
      i++
    } else {
      nums1[k] = nums2[j]
      j++
    }
    k++
  }

  while (i < m) {
    nums1[k++] = n1[i++]
  }

  while (j < n) {
    nums1[k++] = nums2[j++]
  }
}

export { merge }
