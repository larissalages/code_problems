/*

 Copyright 2018 Aman Mehara

 Licensed under the Apache License, Version 2.0 (the "License");
 you may not use this file except in compliance with the License.
 You may obtain a copy of the License at

     http://www.apache.org/licenses/LICENSE-2.0

 Unless required by applicable law or agreed to in writing, software
 distributed under the License is distributed on an "AS IS" BASIS,
 WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 See the License for the specific language governing permissions and
 limitations under the License.

 */

public class LongestCommonSubsequence {

    private final String firstString;
    private final String secondString;

    private final int[][] table;

    public LongestCommonSubsequence(
            final String firstString,
            final String secondString
    ) {
        this.firstString = firstString;
        this.secondString = secondString;

        table = new int[firstString.length() + 1][secondString.length() + 1];

        tabulate();
    }

    private void tabulate() {
        for (int i = 1; i <= firstString.length(); i++) {
            for (int j = 1; j <= secondString.length(); j++) {
                if (firstString.charAt(i - 1) == secondString.charAt(j - 1)) {
                    table[i][j] = 1 + table[i - 1][j - 1];
                 } else {
                    table[i][j] = Math.max(table[i][j - 1], table[i - 1][j]);
                }
            }
        }
    }

    public int getLength() {
        return table[firstString.length()][secondString.length()];
    }

    public String getSubsequence() {
        return recurse(firstString.length(), secondString.length());
    }

    private String recurse(int i, int j) {
        if (i == 0 || j == 0) {
            return "";
        }
        if (firstString.charAt(i - 1) == secondString.charAt(j - 1)) {
            return recurse(i - 1, j - 1) + firstString.charAt(i - 1);
        }
        if (table[i][j - 1] > table[i - 1][j]) {
            return recurse(i, j - 1);
        }
        return recurse(i - 1, j);
    }

}