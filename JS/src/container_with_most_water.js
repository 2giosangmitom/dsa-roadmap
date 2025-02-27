/**
 * Brute force approach (TLE)
 * @param {number[]} height
 * @return {number}
 */
function maxArea (height) {
  let max = 0

  for (let i = 0; i < height.length - 1; i++) {
    for (let j = i + 1; j < height.length; j++) {
      const area = Math.min(height[i], height[j]) * (j - i)
      max = Math.max(area, max)
    }
  }

  return max
}

/**
 * Two pointer approach
 * @param {number[]} height
 * @return {number}
 */
function maxArea2 (height) {
  let max = 0
  let left = 0
  let right = height.length - 1

  while (left < right) {
    const area = Math.min(height[left], height[right]) * (right - left)
    max = Math.max(area, max)

    if (height[left] === height[right]) {
      left++
      right--
    } else if (height[left] < height[right]) {
      left++
    } else {
      right--
    }
  }

  return max
}

export { maxArea, maxArea2 }
