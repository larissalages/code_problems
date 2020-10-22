class PerfectRectangle391 {
    public boolean isRectangleCover(int[][] rectangles) {
        if(rectangles==null || rectangles.length==0 || rectangles[0].length==0)
            return false;
        int N = rectangles.length;

        // Identify Overlaps - TreeSet with custom comparator: O(n*log(n))
        // Sum of areas equal to covering area : O(n)
        // Overall solution : O(n*log(n))

        Set<int[]> set = new TreeSet<>((int[] a, int[] b) -> {
            if (a[3] <= b[1]) {
                return -1;
            } else if (a[1] >= b[3]) {
                return 1;
            } else if (a[2] <= b[0]) {
                return -1;
            } else if (a[0] >= b[2]) {
                return 1;
            } else return 0;
        });

        int[] coverBottomLeft = {rectangles[0][0], rectangles[0][1]};
        int[] coverTopRight = {rectangles[0][2], rectangles[0][3]};

        long totalArea = 0;
        for (int i=0; i<N; i++) {
            if(!set.add(rectangles[i]))
                return false;

            totalArea += ((long)(rectangles[i][3] - rectangles[i][1])) * ((long)(rectangles[i][2] - rectangles[i][0]));
            coverBottomLeft[0] = Math.min(coverBottomLeft[0], rectangles[i][0]);
            coverBottomLeft[1] = Math.min(coverBottomLeft[1], rectangles[i][1]);
            coverTopRight[0] = Math.max(coverTopRight[0], rectangles[i][2]);
            coverTopRight[1] = Math.max(coverTopRight[1], rectangles[i][3]);
        }
        long coverArea = ((long)(coverTopRight[0] - coverBottomLeft[0])) * ((long)(coverTopRight[1] - coverBottomLeft[1]));

        return (totalArea == coverArea);
    }
}