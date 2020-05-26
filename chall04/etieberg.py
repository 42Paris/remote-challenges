#!/usr/bin/env python3

p, q = zip(*[raw_input() for i in range(input())]), []
for i in range(len(p)):
    h = p[i].index('#') if '#' in p[i] else len(p)
    s = p[i][:h].count('.')
    q.append([' ' for sp in range(h-s)]+['.' for dt in range(s)]+list(p[i][h:]))
for z in zip(*q): print(''.join(z))
