class MyQueue(object):

    def __init__(self):
        self.stack1 = []
        self.stack2 = []

    def push(self, x):
        self.stack1.append(x)

    def pop(self):
        self.move_elements()
        return self.stack2.pop()

    def peek(self):
        self.move_elements()
        return self.stack2[-1]

    def empty(self):
        return not self.stack1 and not self.stack2

    def move_elements(self):
        if not self.stack2:
            while self.stack1:
                self.stack2.append(self.stack1.pop())
