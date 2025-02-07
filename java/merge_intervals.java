import java.util.*;

/*
Given a list of intervals, merge them to get a list of non-overlapping intervals.
intervali = [starti, endi]
Example:
Intervals: [[1, 2], [2, 3], [1, 4], [5, 6]]
[1, 2] and [2, 3] can be merged to form [1, 3].
Now, [1, 3] and [1, 4] can be merged to form [1, 4].
[1, 4] and [5, 6] have no intersection.
*/


public class Main {
  public static List<int[]> mergeIntervals(int[][] intervals) {
    if (intervals.length == 0) return new ArrayList<>();
    
    Arrays.sort(intervals, (a, b) -> Integer.compare(a[0], b[0]));
    
    List<int[]> merged = new ArrayList<>();
    int[] current = intervals[0];
    
    for (int i = 1; i < intervals.length; i++) {
      if (current[1] >= intervals[i][0]) {
        current[1] = Math.max(current[1], intervals[i][1]);
      } else {
        merged.add(current);
        current = intervals[i];
      }
    }
    
    merged.add(current);
    return merged;
  }

  public static void printIntervals(List<int[]> intervals) {
    for (int[] interval : intervals) {
      System.out.print("[" + interval[0] + ", " + interval[1] + "] ");
    }
    System.out.println();
  }

  public static void main(String[] args) {
    int[][] intervals = {{1, 2}, {2, 3}, {1, 4}, {5, 6}};
    
    System.out.println("Original Intervals:");
    printIntervals(Arrays.asList(intervals));
    
    List<int[]> merged = mergeIntervals(intervals);
    
    System.out.println("\nMerged Intervals:");
    printIntervals(merged);
  }
}
