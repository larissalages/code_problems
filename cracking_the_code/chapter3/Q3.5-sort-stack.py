from stack import Stack


def sort(stk_org):
    stk_ord = Stack()
    while not stk_org.isEmpty():
        tmp = stk_org.pop()
        while not stk_ord.isEmpty() and tmp < stk_ord.peek():
            stk_org.push(stk_ord.pop())
        stk_ord.push(tmp)

    while not stk_ord.isEmpty():
        stk_org.push(stk_ord.pop())


def main():
    stack = Stack()
    stack.push(25)
    stack.push(5)
    stack.push(2)
    stack.push(10)

    print("Stack before sort:")
    stack.print()

    sort(stack)

    print("Stack after sort:")
    stack.print()


if __name__ == '__main__':
    main()

