#  1. Implement Stack using Queues

## Code

```typescript
//typescript
class MyStack {
    private mainQ: number[];
    private tempQ: number[];
    constructor() {
        this.mainQ = [];
        this.tempQ = [];
    }

    push(x: number): void {
        this.tempQ.push(x);
        while(this.mainQ.length > 0) {
            this.tempQ.push(this.mainQ.shift());
        }
        this.mainQ = this.tempQ;
        this.tempQ = [];
    }

    pop(): number {
        return this.mainQ.shift();
    }

    top(): number {
        return this.mainQ[0];
    }

    empty(): boolean {
       return this.mainQ[0] ? false : true 
    }
}
```

#  2. Implement Queue using Stacks
## Code
```typescript
//typescript
class MyQueue {
    private mainS: number[];
    private tempS: number[];

    constructor() {
        this.mainS = [];
        this.tempS = [];
    }

    push(x: number): void {
        if(this.mainS.length > 0) {
            this.tempS = this.mainS;
            this.mainS = [];
        }
        this.mainS.push(x);
        while(this.tempS.length > 0) {
            this.mainS.push(this.tempS.shift());
        }
    }

    pop(): number {
        return this.mainS.pop();
    }

    peek(): number {
        return this.mainS[this.mainS.length - 1];
    }   

    empty(): boolean {
        return this.mainS.length === 0;
    }
}
```

# 3. Reveal Cards In Increasing Order
## Code

```typescript
//typescript
function deckRevealedIncreasing(deck: number[]): number[] {
    deck.sort((a, b) => a - b);
    const n = deck.length;
    let res = new Array(n);
    let q = Array.from(Array(n), (_, i) => i);
    for(let i = 0; i < n; i++) {
        res[q.shift()!] = deck[i];
        q.push(q.shift()!);
    }
    return res;
};
```

# 4. Design Circular Queue
## Code
```typescript
//typescript
function nextIndex(curr: number, k: number): number {
    const currTmp = curr + 1;
    if(currTmp < k) return currTmp;
    return currTmp - k; 
}

class MyCircularQueue {
    private k: number;
    private queue: number[];
    private _front: number;
    private _rear: number;

    constructor(k: number) {
        this.k = k;
        this.queue =  Array.from(Array(k), () => null);
        this._front = 0;
        this._rear = -1;
    }

    length(): number {
        return this.queue.filter(e => e !== null).length;
    } 

    enQueue(value: number): boolean {
        if(this.isFull()) return false;
        this._rear = nextIndex(this._rear, this.k);
        this.queue[this._rear] = value;
        return true;
    }

    deQueue(): boolean {
        if(this.isEmpty()) return false;
        this.queue[this._front] = null;
        if(this._front === this._rear) {
            this._front = 0;
            this._rear = -1;
        } else {
            this._front = nextIndex(this._front, this.k);
        }
        return true;
    }

    Front(): number {
        return this.isEmpty() ? -1 : this.queue[this._front];
    }

    Rear(): number {
        return this.isEmpty() ? -1 : this.queue[this._rear];
    }

    isEmpty(): boolean {
        return this._rear === -1 ? true : false;
    }

    isFull(): boolean {
        return !this.isEmpty() && (( this._rear + 1) % this.k === this._front) ? true : false;
    }
}
```
