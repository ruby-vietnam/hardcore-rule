# Reveal Cards In Increasing Order

## Summary
- Reverse the simulation

``` typescript
function deckRevealedIncreasing(deck: number[]): number[] {
    deck.sort((a,b) => a-b)
    let result = []
    while(deck.length) {
        if(result.length) result.unshift(result.pop())
        result.unshift(deck.pop())
    }
    return result
    
};
```

# Design Circular Queue

``` typescript
class LL {
    val
    next
    prev
    constructor(val) {
        this.val = val
    }
}

class MyCircularQueue {
    length
    capacity
    head
    tail
    constructor(k: number) {
        this.capacity = k
        this.length = 0
        this.head = new LL(0)
        this.tail = new LL(0)
        this.head.next = this.tail
        this.tail.prev = this.head
    }

    enQueue(value: number): boolean {
        if(this.length < this.capacity) {
            this.length++
            let prevTail = this.tail.prev
            let newNode = new LL(value)
            prevTail.next = newNode
            newNode.prev = prevTail
            newNode.next = this.tail
            this.tail.prev = newNode
            return true
        } else {
            return false
        }
    }


    deQueue(): boolean {
        if(this.length > 0) {
            this.length--
            let nextFirst = this.head.next.next
            nextFirst.prev = this.head
            this.head.next = nextFirst
            return true
        } else {
            return false
        }
    }

    Front(): number {
        if(!this.length) return -1
        return this.head.next.val
    }

    Rear(): number {
        if(!this.length) return -1
        return this.tail.prev.val
    }

    isEmpty(): boolean {
        return this.length === 0
    }

    isFull(): boolean {
        return this.length === this.capacity
    }
}
```

# Max Value of Equation

## Summary
- Monotonous Deque problem

``` typescript
function findMaxValueOfEquation(points: number[][], k: number): number {
    let result = Number.MIN_SAFE_INTEGER
    let deque = []
    for(let i = 0; i < points.length; i++) {
        while(deque.length && points[i][0] - deque[0][0] > k) {
            deque.shift()
        }
        if(deque.length) {
            let prev = deque[0]
            result = Math.max(result, points[i][0] - prev[0] + prev[1] + points[i][1])
        }
        while(deque.length) {
            let last = deque[deque.length - 1]
            if(points[i][0] - last[0] + last[1] <= points[i][1]) {
                deque.pop()
            } else {
                break
            }
        }
        deque.push(points[i])
    }
    return result
};
```