#include <iostream>
#include <vector>
#include <queue>
#include <set>

using namespace std;

// Function to calculate the possible moves based on (first, second)
vector<pair<int, int>> get_moves(int first, int second) {
    return {
        {first, second},   // forward
        {second, -first},  // right
        {-second, first},  // left
        {-first, -second}  // backward
    };
}

// Check if the cell is valid and can be moved to
bool is_valid(vector<vector<int>>& grid, int row, int col) {
    return row >= 0 && row < grid.size() && col >= 0 && col < grid[0].size() && grid[row][col] == 0;
}

// BFS function to calculate the minimum moves
int bfs(vector<vector<int>>& grid, pair<int, int> source, pair<int, int> destination, int first, int second) {
    int M = grid.size();
    int N = grid[0].size();
    
    // Queue for BFS: (row, col, steps)
    queue<tuple<int, int, int>> q;
    q.push({source.first, source.second, 0});
    
    // Visited set
    set<pair<int, int>> visited;
    visited.insert({source.first, source.second});
    
    // Get possible moves based on (first, second)
    vector<pair<int, int>> moves = get_moves(first, second);
    
    // BFS loop
    while (!q.empty()) {
        auto [row, col, steps] = q.front();
        q.pop();
        
        // If we reached the destination, return the steps
        if (row == destination.first && col == destination.second) {
            return steps;
        }
        
        // Explore all 4 directions
        for (auto [drow, dcol] : moves) {
            int new_row = row + drow;
            int new_col = col + dcol;
            
            // Check if the new position is valid and not visited
            if (is_valid(grid, new_row, new_col) && visited.find({new_row, new_col}) == visited.end()) {
                visited.insert({new_row, new_col});
                q.push({new_row, new_col, steps + 1});
            }
        }
    }
    
    // Return -1 if there's no valid path to the destination
    return -1;
}

int main() {
    int M, N;
    cin >> M >> N;
    
    vector<vector<int>> grid(M, vector<int>(N));
    
    // Reading grid values
    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> grid[i][j];
        }
    }
    
    // Reading source and destination coordinates
    pair<int, int> source, destination;
    cin >> source.first >> source.second;
    cin >> destination.first >> destination.second;
    
    // Reading move rule
    int first, second;
    cin >> first >> second;
    
    // Print the minimum moves required to reach the destination
    cout << bfs(grid, source, destination, first, second) << endl;
    
    return 0;
}
