import java.util.*;

public class CourseScheduleIISolution {
    final char UNVISITED = '0';
    final char VISITED = '1';
    final char FINALIZED = '2';
    char[] status;
    Map<Integer, Set<Integer>> prereqs;
    int[] result;
    int idx = 0; // index to insert course at (in result)


    // returns whether crs has a cyclical dependency
    private boolean cycle(int crs) {
        if(status[crs] != UNVISITED) 
            return status[crs] == VISITED;

        status[crs] = VISITED;
        for(int req: prereqs.get(crs)) 
            if(cycle(req))
                return true;
        result[idx++] = crs; // insert crs after its prerequisites
        status[crs] = FINALIZED;

        return false;
    }


    public int[] findOrder(int numCourses, int[][] prerequisites) {  
        status = new char[numCourses];
        prereqs = new HashMap<>();
        result = new int[numCourses];

        for(int crs = 0; crs < numCourses; crs++) 
            prereqs.put(crs, new HashSet<>());
        for(int[] rel: prerequisites) 
            prereqs.get(rel[0]).add(rel[1]);
        
        for(int crs = 0; crs < numCourses; crs++)
            if(cycle(crs))
                return new int[0];

        return result;
    }


    public static void main(String[] argv) {


    }   
}