//Making a JS array to behave like a Stack, putting some restricted operations (top, pop and push)

class Stack {
  constructor() {
    this.s = []
  }

  top() {
    if (this.s.length === 0) return null
    return this.s[this.s.length - 1]
  }

  pop() {
    return this.s.pop()
  }

  push(element) {
    this.s.push(element)
  }
}

const s = new Stack()
console.log('Inital top',s.top())
s.push(1)
console.log('top afeter add 1',s.top())
s.push(2)
s.push(4)
s.push(5)
console.log('top after some pushes',s.top())
console.log('what was popped',s.pop())
console.log('top after the pop',s.top())
