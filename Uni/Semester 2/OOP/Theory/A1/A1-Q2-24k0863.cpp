#include <iostream>
#include <tuple>
using namespace std;

class Robot {
    string name;
    int hits;
public:
    Robot(string n) : name(n), hits(0) {}
    void hitBall(int &ballX, int &ballY, const string &direction) {
        if (direction == "up") {
            ballY++; hits++;
        } else if (direction == "down") {
            ballY--; hits++;
        } else if (direction == "right") {
            ballX++; hits++;
        } else if (direction == "left") {
            ballX--; hits++;
        } else {
            cout << "Invalid direction!" << endl;
        }
    }
    int getHits() {
        return hits;
    }
    string getName() {
        return name;
    }
};

class Ball {
    int x, y;
public:
    Ball(int X, int Y) : x(X), y(Y) {}
    int getX() {
        return x;
    }
    int getY() {
        return y;
    }
    void move(int dx, int dy) {
        x += dx;
        y += dy;
    }
    tuple<int, int> getPosition() {
        return make_tuple(x, y);
    }
};

class Goal {
    int gx, gy;
public:
    Goal(int x, int y) : gx(x), gy(y) {}
    bool isGoalReached(int ballX, int ballY) {
        return ballX == gx && ballY == gy;
    }
};

class Team {
    string teamName;
    Robot *robot;
public:
    Team(string name, Robot *r) : teamName(name), robot(r) {}
    Robot* getRobot() {
        return robot;
    }
    string getTeamName() {
        return teamName;
    }
};

class Game {
    Team *teamOne, *teamTwo;
    Ball *ball;
    Goal *goal;
public:
    Game(Team *t1, Team *t2, Ball *b, Goal *g) : teamOne(t1), teamTwo(t2), ball(b), goal(g) {}
    void startGame() {
        cout << "Game Started!" << endl;
        while (true) {
            play(teamOne);
            if (goal->isGoalReached(ball->getX(), ball->getY())) {
                declareWinner();
                break;
            }
            play(teamTwo);
            if (goal->isGoalReached(ball->getX(), ball->getY())) {
                declareWinner();
                break;
            }
        }
    }
    void play(Team *team) {
        int ballX = ball->getX();
        int ballY = ball->getY();
        string direction;

        if (ballX < 3) {
            direction = "right";
        } else if (ballX > 3) {
            direction = "left";
        } else if (ballY < 3) {
            direction = "up";
        } else if (ballY > 3) {
            direction = "down";
        }

        team->getRobot()->hitBall(ballX, ballY, direction);
        ball->move(ballX - ball->getX(), ballY - ball->getY());

        cout << team->getTeamName() << "'s robot " << team->getRobot()->getName()
             << " moved the ball to (" << ball->getX() << ", " << ball->getY() << "). "
             << "Total hits: " << team->getRobot()->getHits() << endl;
    }
    void declareWinner() {
        cout << "Goal Reached!" << endl;
        if (teamOne->getRobot()->getHits() < teamTwo->getRobot()->getHits()) {
            cout << teamOne->getTeamName() << " wins with " << teamOne->getRobot()->getHits() << " hits!" << endl;
        } else {
            cout << teamTwo->getTeamName() << " wins with " << teamTwo->getRobot()->getHits() << " hits!" << endl;
        }
    }
};

int main() {
    Robot robot1("RoboKicker1");
    Robot robot2("RoboKicker2");

    Team team1("Team A", &robot1);
    Team team2("Team B", &robot2);

    Ball ball(0, 0);
    Goal goal(3, 3);

    Game game(&team1, &team2, &ball, &goal);
    game.startGame();


}