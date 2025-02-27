/**
 * @param {string[]} s
 * @returns {boolean}
 */
function isValid (s) {
  if (s.length % 2 !== 0) {
    return false
  }

  const stack = []

  for (const char of s) {
    if (/[[({]/.test(char)) {
      stack.push(char)
    } else {
      if (stack.length === 0) {
        return false
      }

      if (char === ')' && stack[stack.length - 1] === '(') {
        stack.pop()
      } else if (char === '}' && stack[stack.length - 1] === '{') {
        stack.pop()
      } else if (char === ']' && stack[stack.length - 1] === '[') {
        stack.pop()
      } else {
        return false
      }
    }
  }

  return stack.length === 0
}

export { isValid }
