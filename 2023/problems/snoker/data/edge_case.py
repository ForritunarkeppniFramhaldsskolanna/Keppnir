#!/usr/bin/python3
import sys
import random

edge_case = sys.argv[1]

if edge_case == "axis_aligned_distance_hit":
    n = 3
    balls = [("black", 12, 17.5), ("pink", 14.9, 17), ("white", 13, 10)]
    on_color = "black"
    vx, vy = 0, 7
elif edge_case == "axis_aligned_distance_foul":
    n = 3
    balls = [("black", 12, 17.5), ("pink", 14.9, 16.3), ("white", 13, 10)]
    on_color = "black"
    vx, vy = 0, 7
elif edge_case == "axis_aligned_distance_miss":
    n = 3
    balls = [("black", 12, 17.5), ("pink", 14.9, 17), ("white", 13, 10)]
    on_color = "black"
    vx, vy = 0, 5.7
elif edge_case == "axis_aligned_bounce_distance_hit":
    n = 3
    balls = [("black", 12, 17.5), ("pink", 14.9, 17), ("white", 13, 10)]
    on_color = "black"
    vx, vy = 0, -16
elif edge_case == "axis_aligned_bounce_distance_foul":
    n = 3
    balls = [("black", 12, 17.5), ("pink", 14.9, 16.3), ("white", 13, 10)]
    on_color = "black"
    vx, vy = 0, -16
elif edge_case == "axis_aligned_bounce_distance_miss":
    n = 3
    balls = [("black", 12, 17.5), ("pink", 14.9, 17), ("white", 13, 10)]
    on_color = "black"
    vx, vy = 0, -14.7
else:
    assert False

sys.stdout.write("{}\n".format(n))
for ball in balls:
    sys.stdout.write("{} {:.3f} {:.3f}\n".format(*ball))
sys.stdout.write("{}\n".format(on_color))
sys.stdout.write("{:.3f} {:.3f}\n".format(vx, vy))
