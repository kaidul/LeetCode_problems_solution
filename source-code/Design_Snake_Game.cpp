class SnakeGame {
    int score;
    int width, height;
    list<pair<int, int>> snake;
    queue<pair<int, int>> foods;
    vector<vector<bool>> grid;
    unordered_map<string, pair<int, int>> moves;
    inline bool isInside(int x, int y) {
        return (x >= 0 and y >= 0 and x < height and y < width);
    }
public:
    /** Initialize your data structure here.
     @param width - screen width
     @param height - screen height
     @param food - A list of food positions
     E.g food = [[1,1], [1,0]] means the first food is positioned at [1,1], the second is at [1,0]. */
    SnakeGame(int width, int height, vector<pair<int, int>> food) {
        this->width = width;
        this->height = height;
        grid = vector<vector<bool>>(height, vector<bool>(width, false));
        for(int i = 0; i < (int)food.size(); ++i) {
            foods.push(food[i]);
        }
        snake.push_front({0, 0});
        grid[0][0] = true;
        moves["U"] = {-1, 0};
        moves["L"] = {0, -1};
        moves["R"] = {0, +1};
        moves["D"] = {+1, 0};
        score = 0;
    }
    
    /** Moves the snake.
     @param direction - 'U' = Up, 'L' = Left, 'R' = Right, 'D' = Down
     @return The game's score after the move. Return -1 if game over.
     Game over when snake crosses the screen boundary or bites its body. */
    int move(string direction) {
        assert(direction == "U" or direction == "L" or direction == "R" or direction == "D");
        if(score == -1) {
            return score;
        }
        pair<int, int> head = *snake.begin();
        int dx = moves[direction].first;
        int dy = moves[direction].second;
        int newX = head.first + dx;
        int newY = head.second + dy;
        
        if(!isInside(newX, newY)) {
            score = -1;
            return -1;
        }
        
        if(foods.empty() or foods.front() != pair<int, int>(newX, newY)) {
            pair<int, int> tail = *(--snake.end());
            grid[tail.first][tail.second] = false;
            snake.pop_back();
        }
        
        if(grid[newX][newY]) {
            score = -1;
            return -1;
        }
        
        snake.push_front({newX, newY});
        if(!foods.empty() and foods.front() == pair<int, int>(newX, newY)) {
            ++score;
            foods.pop();
        }
        grid[newX][newY] = true;
        
        return score;
    }
};

/**
 * Your SnakeGame object will be instantiated and called as such:
 * SnakeGame obj = new SnakeGame(width, height, food);
 * int param_1 = obj.move(direction);
 */