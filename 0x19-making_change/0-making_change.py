#!/usr/bin/python3
"""
Making Change module
"""


def makeChange(coins, total):
    """
    Function that makes change for a given total
    """
    if total < 1:
        return 0
    mychange = 0
    coins.sort(reverse=True)
    for mycoin in coins:
        temp = int(total / coin)
        total -= (temp * coin)
        mychange += temp
        if total == 0:
            return mychange
    if total != 0:
        return -1
