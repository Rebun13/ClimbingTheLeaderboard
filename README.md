# ClimbingTheLeaderboard

## Description

An arcade game player wants to climb to the top of the leaderboard and track their ranking. The game uses Dense Ranking, so its leaderboard works like this:

- The player with the highest score is ranked number  _1_ on the leaderboard.
- Players who have equal scores receive the same ranking number, and the next player(s) receive the immediately following ranking number.

## Returns

- int[m]: the player's rank after each new score

## Input

- The first line contains an integer _n_, the number of players on the leaderboard.
- The next line contains _n_ space-separated integers _ranked[i]_, the leaderboard scores in decreasing order.
- The next line contains an integer, _m_, the number of games the player plays.
- The last line contains _m_ space-separated integers _player[j]_, the game scores.
