import java.util.Scanner;

public class MinimumMoves {

    public static int minimumMoves(String[] instruct) {
        String[] directions = {"up", "down", "left", "right"};
        int s = instruct.length;
        int[][][] dp = new int[s + 1][4][4];

        // Initialize dp with a large value (infinity equivalent)
        for (int i = 0; i <= s; i++) {
            for (int j = 0; j < 4; j++) {
                for (int k = 0; k < 4; k++) {
                    dp[i][j][k] = Integer.MAX_VALUE;
                }
            }
        }

        // Base case
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                dp[0][i][j] = 0;
            }
        }

        // Fill dp table
        for (int k = 1; k <= s; k++) {
            int instrIdx = -1;
            for (int d = 0; d < 4; d++) {
                if (directions[d].equals(instruct[k - 1])) {
                    instrIdx = d;
                    break;
                }
            }

            for (int i = 0; i < 4; i++) {
                for (int j = 0; j < 4; j++) {
                    if (dp[k - 1][i][j] != Integer.MAX_VALUE) {
                        if (instrIdx == i || instrIdx == j) {
                            dp[k][i][j] = Math.min(dp[k][i][j], dp[k - 1][i][j]);
                        } else {
                            dp[k][i][j] = Math.min(dp[k][i][j],
                                    Math.min(dp[k - 1][instrIdx][j] + 1, dp[k - 1][i][instrIdx] + 1));
                        }
                    }
                }
            }
        }

        // Find the minimum moves
        int minimumMoves = Integer.MAX_VALUE;
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                minimumMoves = Math.min(minimumMoves, dp[s][i][j]);
            }
        }

        return minimumMoves;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int m = Integer.parseInt(scanner.nextLine().trim());
        String[] instruct = new String[m];

        for (int i = 0; i < m; i++) {
            instruct[i] = scanner.nextLine().trim();
        }

        int result = minimumMoves(instruct);
        System.out.print(result);
        scanner.close();
    }
}