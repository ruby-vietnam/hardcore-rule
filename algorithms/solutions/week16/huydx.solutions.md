# Problem 1

```java
class Solution {
    public boolean containsNearbyDuplicate(int[] nums, int k) {
        Map<Integer, Integer> cache = new HashMap<>();
        for (int i = 0; i < nums.length; i++) {
            int n = nums[i];
            if (cache.get(n) != null) {
                int oi = cache.get(n);
                if (i - oi <= k) {
                    return true;
                } 
            }
            cache.put(n, i);
        }
        return false;
    }
}
```

# Problem 2

```java
// too lazy to do binary search tree
class Solution {
    public int findPeakElement(int[] nums) {
        if (nums.length == 1) {
            return 0;
        }
        for (int i = 0; i < nums.length; i++) {
            int nm1 = i == 0 ? Integer.MIN_VALUE : nums[i-1];
            int np1 = i == nums.length-1 ? Integer.MIN_VALUE : nums[i+1];
            if (nums[i] > nm1 && nums[i] > np1) {
                return i;
            }
        }
        return -1;
    }
}
```

# Problem 3
TLE with O(N^2)

```java
class Solution {
    
    class Rec {
        Point bl; //bottom left
        Point tr; //top right
        public Rec(Point p1, Point p2) {
            bl = p1;
            tr = p2;
        }
        
        @Override
        public String toString() {
            return bl+"|"+tr;
        }
        
        @Override
        public boolean equals(Object _other) {
            // skip null check
            Rec other = (Rec)_other;
            return this.bl.equals(other.bl) &&
                this.tr.equals(other.tr);
        }

        public int surface() {
            return (bl.x-tr.x) *(bl.y-tr.y);
        }
        
        public boolean overlap(Rec other) {
            boolean ret = true;
            if (this.tr.x <= other.bl.x || other.tr.x <= this.bl.x) { ret = false; }
            if (this.bl.y >= other.tr.y || other.bl.y >= this.tr.y) { ret = false; }
            return ret;
        }
    }
    
    class Point {
        Integer x;
        Integer y;
        public Point(Integer x, Integer y) {
            this.x = x;
            this.y = y;
        }
    
        @Override
        public String toString() {
            return "x:"+x+",y:"+y;
        }
        
        @Override
        public boolean equals(Object _other) {
            // skip null check
            Point other = (Point)_other;
            return this.x.equals(other.x) &&
                this.y.equals(other.y);
        }
    }

    public boolean isRectangleCover(int[][] rectangles) {
        List<Rec> recs = new ArrayList<>();
        List<Point> points = new ArrayList<>();
        int allSurface = 0;
        
        for (int i = 0; i < rectangles.length; i++) {
            int[] r = rectangles[i];
            Point tl = new Point(r[0], r[1]);
            Point br = new Point(r[2], r[3]);
            Rec rec = new Rec(tl, br);
            recs.add(rec);
            points.add(tl); points.add(br);
            allSurface += rec.surface();   
        }
        
        if (recs.size() == 1) { return true; }
        // O(n^2)
        // check overlap
        for (int i = 0; i < recs.size()-1; i++) {
            for (int j = i+1; j < recs.size(); j++) {
                if (recs.get(i).overlap(recs.get(j))) {
                    return false;
                }
            }
        }

        // if not overlap, check same surface
        //TODO: could be optimize later
        Collections.sort(points, (p1, p2) -> {
            return p1.x.equals(p2.x) ? p1.y.compareTo(p2.y) : p1.x.compareTo(p2.x);
        });
        
        Point min = points.get(0);
        Point max = points.get(points.size()-1);

        return allSurface == new Rec(min, max).surface();
    }

}
```
