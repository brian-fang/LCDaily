import java.util.*;

// 967. Numbers With Same Consecutive Differences
// Medium

// Return all non-negative integers of length n such that the absolute difference between every two consecutive digits is k.

// Note that every number in the answer must not have leading zeros. For example, 01 has one leading zero and is invalid.

// You may return the answer in any order.


public class Solution {

  	public static int[] numsSameConsecDiff(int n, int k) {
  		
  		Deque<Integer> queue = new ArrayDeque<>(); 

  		for(int num = 1; num <= 9; num++) queue.offer(num);

  		// The "first" level of the BFS are the single digits
  		// The objective is to build up the numbers from the single digits, all the way up to n.
  		// We only continue with a number if it fulfils the desired property
  		for(int lvl = 1; lvl < n; lvl++) {

  			int sz = queue.size(); 

  			for(int i = 0; i < sz; i++) {

  				int num = queue.poll(), digit = num % 10;

  				if(digit + k < 10) queue.offer(num*10 + digit+k);
  				// If k == 0, we don't want to offer the same number
  				if(k != 0 && digit  - k >= 0) queue.offer(num*10 + digit-k);

  			}

  		}

  		// The queue now contains all of the numbers of length n with the requested property
  		int sz = queue.size();

  		int[] arresult = new int[sz];

  		while(sz > 0) arresult[--sz] = queue.poll();

  		return arresult;
  	}

	public static void main(String[] argv) {

		for(int num: numsSameConsecDiff(Integer.parseInt(argv[0]), Integer.parseInt(argv[1]))) 
			System.out.print(num + " ");

 	} 	
}