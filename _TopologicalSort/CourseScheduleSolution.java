import java.util.*;

/*
    There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take course ai.

    For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.
    Return true if you can finish all courses. Otherwise, return false.

    --- 


*/

public class CourseScheduleSolution {
    final char UNVISITED = '0';
    final char VISITED = '1';
    final char FINALIZED = '2';
    char[] status;
    Map<Integer, Set<Integer>> prereqs;

    // returns whether crs has a cyclical dependency
    private boolean cycle(int crs) {
        if(status[crs] != UNVISITED) 
            return status[crs] == VISITED;

        status[crs] = VISITED;
        for(int req: prereqs.get(crs)) 
            if(cycle(req))
                return true;
        status[crs] = FINALIZED;

        return false;
    }


    public boolean canFinish(int numCourses, int[][] prerequisites) {  
        status = new char[numCourses];
        prereqs = new HashMap<>();

        for(int crs = 0; crs < numCourses; crs++) 
            prereqs.put(crs, new HashSet<>());
        for(int[] rel: prerequisites) 
            prereqs.get(rel[0]).add(rel[1]);
        
        for(int crs = 0; crs < numCourses; crs++)
            if(cycle(crs))
                return false;

        return true;
    }


	public static void main(String[] argv) {


 	} 	
}