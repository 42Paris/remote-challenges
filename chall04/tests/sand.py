#!/usr/bin/env python3

print('\n'.join([''.join(i) for i in zip(*['#'.join([''.join(sorted(a)) for a in b.split('#')]) for b in [''.join(c) for c in zip(*[input() for i in range(int(input()))])]])]))

